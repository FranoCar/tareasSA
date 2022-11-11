#include "funciones.h"
#include "FFMS_Generator/FFMS_Generator.hpp"

using namespace std;

int main(int argc, char const *argv[]){
	// Nombre de la instancia a abrir.
	string instancia = getArg("-i",argc,argv);
	if (instancia.empty()){
		cout << "Entrada erronea o nula en argumento -i" << endl;
		return 0;
	}
	instancia = "dataset/" + instancia + ".txt";

	// Tiempo en segundos para limitar la ejecución de GRASP.
    float tiempo;
	try{
		tiempo = stof(getArg("-t",argc,argv));
		if(tiempo <= 0){
			cout << "Entrada erronea o nula en argumento -t" << endl;
			return 0;
		}
	}catch(...){
		cout << "Entrada erronea o nula en argumento -t" << endl;
		return 0;
	}

	string na_arg = getArg("-na",argc,argv);
	int n_agentes = 100;
	if(!na_arg.empty()){
		try{
			n_agentes = stoi(na_arg);
			if(n_agentes <= 0){
				cout << "Entrada erronea o nula en argumento -na" << endl;
				return 0;
			}
		}catch(...){
			cout << "Entrada erronea o nula en argumento -na" << endl;
			return 0;
		}
	}
    
	//Set de secuencias.
	vector<string> omega = getData(instancia);
	if(omega.empty()){
		cout << "Archivo no se puede leer o no existe" << endl;
		return 0;
	}
	int M = omega[0].length();	//Longitud M de cada secuencia.

	// Argumento opcional threshold.
	string th_arg = getArg("-th",argc,argv);
	float th = 0.8;
	if(!th_arg.empty()){
		try{
			th = stof(th_arg);
			if(th > 1 or th < 0){
				cout << "Entrada erronea o nula en argumento -th" << endl;
				return 0;
			}
		}catch(...){
			cout << "Entrada erronea o nula en argumento -th" << endl;
			return 0;
		}
	}
	// Argumento opcional probabilidad epsilon
	string mr_arg = getArg("-mr",argc,argv);
	float mr = 0.1;
	if(!mr_arg.empty()){
		try{
			mr = stof(mr_arg);
			if(mr > 1 or mr < 0){
				cout << "Entrada erronea en argumento -mr" << endl;
				return 0;
			}
		}catch(...){
			cout << "Entrada erronea en argumento -mr" << endl;
			return 0;
		}
	}

	string e_arg = getArg("-e",argc,argv);
	float e = 0.1;
	if(!e_arg.empty()){
		try{
			e = stof(e_arg);
			if(e > 1 or e < 0){
				cout << "Entrada erronea en argumento -e" << endl;
				return 0;
			}
		}catch(...){
			cout << "Entrada erronea en argumento -e" << endl;
			return 0;
		}
	}

	string cr_arg = getArg("-cr",argc,argv);
	float crossover_rate = 0.2;
	if(!e_arg.empty()){
		try{
			crossover_rate = stof(cr_arg);
			if(crossover_rate > 1 or crossover_rate < 0){
				cout << "Entrada erronea en argumento -cr" << endl;
				return 0;
			}
		}catch(...){
			cout << "Entrada erronea en argumento -cr" << endl;
			return 0;
		}
	}

	auto generator = FFMS_Generator(omega,th);
	generator.AG(n_agentes,crossover_rate,mr,e,tiempo);

	return 0;
}