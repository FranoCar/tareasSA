#include "FFMS_Generator.hpp"
// Aquí implementaremos él algoritmo genético

using namespace std;

vector<string> FFMS_Generator::gen_poblacion(int n_agentes, float e){
	vector<string> poblacion;	
	for(int i = 0; i < n_agentes; i++){
		poblacion.push_back(greedy_probabilista(e));
	}
	return poblacion;
}

string FFMS_Generator::seleccion(vector<string> poblacion, vector<float> fitness){
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<size_t> r_pick(0,poblacion.size()-1);

	// Cantidad de participantes del torneo.
	int part = 3;

	// Elegimos el primer contrinicante y lo comparamos los restantes para elegir un ganador.
	int ganador = r_pick(gen);
	for(int i = 1; i < part; i++){
		int contrincante = r_pick(gen);
		if(fitness[contrincante] > fitness[ganador])
			ganador = contrincante;
	}
	return poblacion[ganador];
}

vector<string> FFMS_Generator::crossover(string padre1, string padre2){
	random_device rd;
	mt19937 gen(rd());
	
	// UNIFORM CROSSOVER

	/*
	uniform_int_distribution<> p(0.0,1.0);

	for(int i = 0; i < padre1.size(); i++){
		if(p(gen) < 0.5){
			char aux = padre1[i];
			padre1[i] = padre2[i];
			padre2[i] = aux; 
		}
	}
	*/

	// 2-POINT CROSSOVER

	uniform_int_distribution<> rand1(0,padre1.size()-1);
	int split_point1 = rand1(gen);
	uniform_int_distribution<> rand2(split_point1,padre1.size()-1);
	int split_point2 = rand2(gen);

	for(int i=split_point1; i<split_point2+1; i++){
		char aux = padre1[i];
		padre1[i] = padre2[i];
		padre2[i] = aux;
	}

	vector<string> hijos;
	hijos.push_back(padre1);
	hijos.push_back(padre2);

	return hijos;
}

// Implementación de reemplazo steady-state
vector<string> FFMS_Generator::reemplazo(vector<string> poblacion,vector<string> hijos, vector<float> fitness, float elit){
	vector<float> fitAux = fitness;
	sort(fitAux.begin(),fitAux.end());
	float umbralElite = fitAux[(fitAux.size()-1)*(1-elit)]; //elitismo

	for(string hijo : hijos){
		// Búsqueda del agente con menor fitness:
		int peor = 0;
		for (int i = 1; i < poblacion.size(); i++){
			//si el fitness del agente indica que pertenece a la elite, se lo salta
			if(fitness[i] > fitness[umbralElite])
				continue;
			if(fitness[peor] < fitness[i])
				peor = i;
		}
		// reemplazo:
		poblacion[peor] = hijo;
	}
	return poblacion;
}

vector<string> FFMS_Generator::mutar(vector<string> siggen, float rate, vector<float> fitness, float elit){
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dis(0.0, 1.0);
	uniform_int_distribution<size_t> r_pick_alfabeto(0,alfabeto.size()-1);
	uniform_int_distribution<size_t> r_pick_letra(0,M-1);

	vector<float> fitAux = fitness;
	sort(fitAux.begin(),fitAux.end());
	float umbralElite = fitAux[(fitAux.size()-1)*(1-elit)]; //elitismo

	for(int i = 0; i < siggen.size(); i++){
		if(fitness[i] > fitness[umbralElite]) continue;
		if(dis(gen) < rate){
			int j = r_pick_letra(gen);
			char aux;
			do{
				aux = alfabeto[r_pick_alfabeto(gen)];
			}while(siggen[i][j] == aux);
			siggen[i][j] = aux;
		}
	}
	return siggen;
}

string FFMS_Generator::AG(int n_agentes, float crossover_rate, float mutation_rate, float e, float time, float elitism){
	auto start = currentTime(); // Tiempo de inicio del algoritmo.
	bool newrecord = false;
	// Generar Población
	vector<string> poblacion = gen_poblacion(n_agentes, e);
	vector<float> fitness;
	//Best so far
	string solbf = poblacion[0];
	float fitbf = getFitness(solbf);
	// Evaluar Población
	for(string agente : poblacion){
		float curfit = getFitness(agente);
		if (curfit > fitbf){
			solbf = agente;
			fitbf = curfit;
		}
		fitness.push_back(curfit);
	}
	lognewr(fitbf,timeDiff(start)/1000);
	cout << "valor objetivo: " << getScore(solbf) << endl;
	while( (timeDiff(start)/1000) < time){
		vector<string> siggen = poblacion;
		for (int k = 0; k < poblacion.size()*crossover_rate/2; k++){
			// Selección
			string padre1 = seleccion(poblacion,fitness);
			string padre2 = seleccion(poblacion,fitness);
			// Recombinar
			vector<string> hijos = crossover(padre1,padre2);

			// Generar nueva población
			siggen = reemplazo(siggen,hijos,fitness, elitism);
		}
		// Mutar nueva generación
		siggen = mutar(siggen, mutation_rate,fitness, elitism);
		// MEMES
		for(int i = 0; i < siggen.size(); i++){
			cout << "buscando " << i << endl;
			siggen[i] = busqueda_local(siggen[i]);
		}

		// Evaluar Población
		fitness = vector<float>();
		for(string agente : siggen){
			float curfit = getFitness(agente);
			if(curfit > fitbf){
				solbf = agente;
				fitbf = curfit;
				newrecord = true;
			}
			fitness.push_back(curfit);
		}
		if(newrecord){
			lognewr(fitbf,timeDiff(start)/1000);
			cout << "valor objetivo: " << getScore(solbf) << endl;
			newrecord = false;
		}
		poblacion = siggen;
	}
	return solbf;
}