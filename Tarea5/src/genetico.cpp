#include "genetico.hpp"
// Aquí implementaremos él algoritmo genético

using namespace std;

string AG(vector<string> omega, int M, int n_agentes, float e, float th, float time){
	auto start = currentTime(); // Tiempo de inicio del algoritmo.
	// Generar Población
	vector<string> poblacion = gen_poblacion(n_agentes);
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
	while( (timeDiff(start)/1000) < time){
		// Selección}
		vector<string> padres = seleccion(poblacion,fitness);
		// Recombinar
		vector<string> hijos = crossover(padres);
		// Generar nueva población
		vector<string> siggen = reemplazo(poblacion,hijos);
		//Mutar nueva generación
		mutar(siggen);
		// Evaluar Población
		fitness = vector<int>();
		for(string agente : siggen){
			fitness.push_back(getValorObjetivo(omega,agente,M,th));
		}
	}
}
