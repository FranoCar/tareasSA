#include "FFMS_Generator.hpp"

using namespace std;

// Implementación de reemplazo steady-state
vector<string> FFMS_Generator::reemplazo(vector<string> poblacion,vector<string> hijos, vector<int> fitness, float elit){
	vector<int> fitAux = fitness;
	sort(fitAux.begin(),fitAux.end());
	int umbralElite = fitAux[(fitAux.size()-1)*(1-elit)]; //elitismo

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