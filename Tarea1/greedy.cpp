#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <vector>
#include <map>
#include "funciones.h"

using namespace std;

string greedy(vector<string> omega, int M, int th){
	string solucion;

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
		
		
		if (logrado == 0)
			solucion.push_back(minChar);
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
	}catch(...){
		cout << "Entrada erronea o nula en argumento -th" << endl;
		return 0;
	}
	
	string solucion = greedy(omega, M, th);

    return 0;
}
