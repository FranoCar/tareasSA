#ifndef FUNCIONES
#define FUNCIONES

#include <iostream>
#include <string.h>
#include <fstream>
#include <random>
#include <vector>
#include <string>
#include <map>
#include <chrono>
#include <array>

using namespace std;

string getArg(char const* val_esperado, int argc, char const *argv[]);

vector<string> getData(string dir);

int hummingDist(string A, string B, int M);

int getValorObjetivo(vector<string> omega, string solucion,int M, float th);


#endif