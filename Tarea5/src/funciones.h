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

using namespace std;

// inline copia el contenido de la función donde es llamada en tiempo de compiĺación
// así que estas funciones son solo para simplificar código.
// Como son funciones que reemplazarán el código, la definición complete debe ir en
// el header file.
inline chrono::time_point<std::chrono::high_resolution_clock> currentTime(){
	return chrono::high_resolution_clock::now();
}
inline float timeDiff(chrono::time_point<std::chrono::high_resolution_clock> start){
	return (float)chrono::duration_cast<chrono::milliseconds>(
						currentTime() - start
                            ).count();
}

string getArg(char const* val_esperado, int argc, char const *argv[]);

vector<string> getData(string dir);

int hummingDist(string A, string B, int M);

int getValorObjetivo(vector<string> omega, string solucion,int M, float th);


#endif