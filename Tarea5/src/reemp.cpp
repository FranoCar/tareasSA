#include "genetico.hpp"

using namespace std;

// Implementación de reemplazo steady-state
vector<string> reemplazo(vector<string> poblacion,vector<string> hijos, vector<int> fitness){
	for(string hijo : hijos){
		// Búsqueda del agente con menor fitness:
		int peor = 0;
		for (int i = 1; i < poblacion.size(); i++){
			if(fitness[peor] < fitness[i])
				peor = i;
		}
		// reemplazo:
		poblacion[peor] = hijo;
	}
	return poblacion;
}