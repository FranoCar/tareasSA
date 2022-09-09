#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <vector>
#include <map>
#include <chrono>
#include "funciones.h"

using namespace std;

string greedy(vector<string> omega, int M, float th){
	string solucion;
	int count[M] = {0};

	for(int i = 0; i < M; i++){
		map<char, int> frecuencia;
		// Contar frecuencia de caracteres.
		for(string s : omega){
			char c = s.at(i);
			if(frecuencia.find(c) == frecuencia.end()){
				frecuencia[c] = 1;
			}else{
				frecuencia[c] = frecuencia[c] + 1;
			}
		}
		// Búsqueda de caracter menos frecuente.
		char minChar = frecuencia.begin()->first;
		for(auto const& pair : frecuencia){
			if(frecuencia[pair.first] < frecuencia[minChar])
				minChar = pair.first;
		}

		int logrado = 0;
		
		for(auto pair = frecuencia.begin(); pair != frecuencia.end() && logrado == 0; pair++){
			for(int j = 0; j < omega.size(); j++){
				if(omega[j].at(i) != pair->first && count[j] == (int)(th*M)-1){
					logrado = 1;
					solucion.push_back(pair->first);
					break;
				}
			}
		}

		if (logrado == 0)
			solucion.push_back(minChar);

		for(int j = 0; j < omega.size(); j++){
			if(omega[j].at(i) != solucion.at(i)){
				count[j]++;
			}			
		}	
	}
	return solucion;
}


int main(int argc, char const *argv[]){
	//Nombre de la instancia a abrir.
	string instancia = getArg("-i",argc,argv);
	if (instancia.empty()){
		cout << "Entrada erronea o nula en argumento -i" << endl;
		return 0;
	}
	instancia = "dataset/" + instancia + ".txt";

	//Set de secuencias.
	vector<string> omega = getData(instancia);
	if(omega.empty()){
		cout << "Archivo no se puede leer o no existe" << endl;
		return 0;
	}
	int M = omega[0].length();	//Longitud M de cada secuencia.

	float th;	//Threshold.
	try{
		th = stof(getArg("-th",argc,argv));
		if(th > 1 || th < 0){
			cout << "Entrada erronea o nula en argumento -th" << endl;
			return 0;
		}
	}catch(...){
		cout << "Entrada erronea o nula en argumento -th" << endl;
		return 0;
	}

	string solucion = greedy(omega, M, th);

	auto start = chrono::high_resolution_clock::now();
	int valorObj = getValorObjetivo(omega,greedy(omega,M,th),M,th);
	auto stop = chrono::high_resolution_clock::now();

	int N = omega.size();
	cout << endl;
	cout << "Calidad de solución: " << valorObj << "/" << N << " = " << (float)valorObj/N << endl;
	cout << "(Valor objetivo / Total secuencias)" << endl;
	float duration = (float)chrono::duration_cast<chrono::microseconds>(stop - start).count()/1000;
	cout << "Duración: " << duration << "(ms)" << endl;
	cout << endl;

    return 0;
}