#include "genetico.hpp"
// Aquí implementaremos él algoritmo genético

using namespace std;

string AG(vector<string> omega, int M, int n_agentes, float crossover_rate,float e, float th, float time){
	auto start = currentTime(); // Tiempo de inicio del algoritmo.
	float tiempo_encontrado = 0;
	bool newrecord = false;
	// Generar Población
	vector<string> poblacion = gen_poblacion(n_agentes,M);
	vector<int> fitness;
	//Best so far
	string solbf = poblacion[0];
	int fitbf = getValorObjetivo(omega,solbf,M,th);
	// Evaluar Población
	for(string agente : poblacion){
		int curfit = getValorObjetivo(omega,agente,M,th);
		if (curfit > fitbf){
			solbf = agente;
			fitbf = curfit;
		}
		fitness.push_back(curfit);
	}
	int N = omega.size();
	tiempo_encontrado = timeDiff(start)/1000;
	lognewr((float)fitbf/N,tiempo_encontrado);
	while( (timeDiff(start)/1000) < time){
		// Selección}
		string padre1 = seleccion(poblacion,fitness);
		string padre2 = seleccion(poblacion,fitness);
		vector<string> siggen = poblacion;
		for (int k = 0; k < poblacion.size()*crossover_rate/2; k++){
			// Recombinar
			vector<string> hijos = crossover(padre1,padre2);
			// Generar nueva población
			siggen = reemplazo(siggen,hijos,fitness);
		}
		// Mutar nueva generación
		siggen = mutar(siggen, e);
		// Evaluar Población
		fitness = vector<int>();
		for(string agente : siggen){
			int curfit = getValorObjetivo(omega,agente,M,th);
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
	}
	return solbf;
}
