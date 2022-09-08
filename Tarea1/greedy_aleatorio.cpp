#include <iostream>
#include <string.h>
#include <fstream>
#include <random>
#include <vector>
#include <string>
#include <map>
#include <chrono>
#include "funciones.h"

using namespace std;

string greedy_probabilista(vector<string> omega, int M, float e){
	// Caracteres posibles, específicos a las instancias a usar.
	vector<char> alfabeto{'A','C','G','T'}; 

	// Estructuras para generar números aleatorios
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dis(0.0, 1.0);

	string solucion; // Solución inicialmente vacía
	for(int i = 0; i < M; i++){		//Iteramos por posición desde 0 a M.
		map<char, int> frecuencia;	// Mapa para comparar frecuencia de caracteres.
		// Conteo de frecuencias de caracteres.
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
		// Se selecciona como siguiente en la solución la opción greedy con probabilidad 1-e.
		// Se selecciona una opción aleatoria con una probabilidad e.
		double p = dis(gen);
		uniform_int_distribution<size_t> r_pick(0,alfabeto.size()-1);
		if(p < e){
			solucion.push_back(alfabeto[r_pick(gen)]);
		}else{
			solucion.push_back(minChar);
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
	}catch(...){
		cout << "Entrada erronea o nula en argumento -th" << endl;
		return 0;
	}
	string e_arg = getArg("-e",argc,argv);
	float e = 0.1;
	if(!e_arg.empty()){
		try{
			e = stof(e_arg);
		}catch(...){
			cout << "Entrada erronea en argumento -e" << endl;
			return 0;
		}
	}

	auto start = chrono::high_resolution_clock::now();
	int valorObj = getValorObjetivo(omega,greedy_probabilista(omega,M,e),M,th);
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