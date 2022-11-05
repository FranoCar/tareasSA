#ifndef GENETICO
#define GENETICO

#include "funciones.h"

vector<string> gen_poblacion(int n_agentes, int M);

string seleccion(vector<string> poblacion,vector<int> fitness);

vector<string> crossover(string padre1, string padre2);

vector<string> mutar(vector<string> siggen, double rate);

vector<string> reemplazo(vector<string> poblacion,vector<string> hijos, vector<int> fitness);

inline void lognewr(float score, float tiempo_encontrado){
	cout << "Nueva calidad: " << score << endl;
    cout << "Encontrado en: " << tiempo_encontrado << "(s)" << endl;
    cout << "-----" << endl;
}

string AG(vector<string> omega, int M, int n_agentes, float crossover_rate,float e, float th, float time);

#endif