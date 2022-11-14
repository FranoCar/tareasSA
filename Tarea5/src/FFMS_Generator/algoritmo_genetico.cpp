#include "FFMS_Generator.hpp"
// Aquí implementaremos él algoritmo genético

using namespace std;

string FFMS_Generator::AG(int n_agentes, float crossover_rate, float mutation_rate, float e, float time, float elitism){
	auto start = currentTime(); // Tiempo de inicio del algoritmo.
	float tiempo_encontrado = 0;
	bool newrecord = false;
	// Generar Población
	vector<string> poblacion = gen_poblacion(n_agentes, e);
	vector<int> fitness;
	//Best so far
	string solbf = poblacion[0];
	int fitbf = getFitness(solbf);
	// Evaluar Población
	for(string agente : poblacion){
		int curfit = getFitness(agente);
		if (curfit > fitbf){
			solbf = agente;
			fitbf = curfit;
		}
		fitness.push_back(curfit);
	}
	tiempo_encontrado = timeDiff(start)/1000;
	lognewr((float)fitbf/N,tiempo_encontrado);
	while( (timeDiff(start)/1000) < time){
		vector<string> siggen = poblacion;
		for (int k = 0; k < poblacion.size()*crossover_rate/2; k++){
			//cerr << "k: " << k <<endl;
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
		// Evaluar Población
		fitness = vector<int>();
		for(string agente : siggen){
			int curfit = getFitness(agente);
			//cerr<<endl<<"Best Fitness: "<<fitbf<<endl;
			//cerr<<"Current Fitness: "<<curfit<<endl<<endl;
			if(curfit > fitbf){
				solbf = agente;
				fitbf = curfit;
				newrecord = true;
			}
			fitness.push_back(curfit);
		}
		if(newrecord){
			tiempo_encontrado = timeDiff(start)/1000;
			lognewr((float)fitbf/N,tiempo_encontrado);
			newrecord = false;
		}
		poblacion = siggen;
	}
	return solbf;
}
