#ifndef GENETICO
#define GENETICO

#include "funciones.h"

vector<string> gen_poblacion(int n_agentes, int M);

string seleccion(vector<string> poblacion,vector<int> fitness);

vector<string> crossover(string padre1, string padre2);

void mutar(vector<string> siggen);

vector<string> reemplazo(vector<string> poblacion,vector<string> hijos);

inline void lognewr(float score, float tiempo_encontrado){
	cout << "Nueva calidad: " << score << endl;
    cout << "Encontrado en: " << tiempo_encontrado << "(s)" << endl;
    cout << "-----" << endl;
}

string AG(vector<string> omega, int M, int n_agentes, float e, float th, float time);

#endif