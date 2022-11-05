#ifndef GENETICO
#define GENETICO

#include "funciones.h"

vector<string> gen_poblacion(int n_agentes, int M);

vector<string> seleccion(vector<string> poblacion,vector<int> fitness);

vector<string> crossover(vector<string> padres);

void mutar(vector<string> siggen);

vector<string> reemplazo(vector<string> poblacion,vector<string> hijos);

string AG(vector<string> omega, int M, int n_agentes, float e, float th, float time);

#endif