#include "genetico.hpp"

using namespace std;

// Implementación de reemplazo steady-state
vector<string> reemplazo(vector<string> poblacion,string hijoganador, vector<int> fitness){
	// Búsqueda del agente con menor fitness:
	int peor = 0;
	for (int i = 1; i < poblacion.size(); i++){
		if(fitness[peor] < fitness[i])
			peor = i;
	}
	// reemplazo:
	poblacion[peor] = hijoganador;

	return poblacion;
}