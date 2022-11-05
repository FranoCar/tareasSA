#include "genetico.hpp"

using namespace std;

string seleccion(vector<string> poblacion, vector<int> fitness){
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