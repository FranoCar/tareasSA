#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <vector>
#include "funciones.h"

using namespace std;



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


    return 0;
}
