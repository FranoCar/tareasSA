#include <iostream>
#include <string.h>
#include <fstream>
#include <random>
#include <vector>
#include <string>
#include <map>
#include "funciones.h"

using namespace std;

string greedy_probabilista(vector<string> omega, int M, float e){
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dis(0.0, 1.0);
	string solucion;
	for(int i = 0; i < M; i++){
		map<char, int> frecuencia;
		// Búsqueda de caracter menos frecuente.
		for(string s : omega){
			char c = s.at(i);
			if(frecuencia.find(c) == frecuencia.end()){
				frecuencia[c] = 1;
			}else{
				frecuencia[c] = frecuencia[c] + 1;
			}
		}

		char minChar = frecuencia.begin()->first;
		vector<char> alfabeto;
		for(auto const& pair : frecuencia){
			alfabeto.push_back(pair.first);
			if(frecuencia[pair.first] < frecuencia[minChar])
				minChar = pair.first;
		}

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

	float th;	//Treshold.
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

	string solucion = greedy_probabilista(omega,M,e);
	cout << "Solución: " << solucion << endl;
	cout << "Valor objetivo: " << getValorObjetivo(omega,solucion,M,th) << endl;

	return 0;
}