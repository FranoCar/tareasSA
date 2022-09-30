#include "funciones.h"

int main(int argc, char const *argv[]){
	//Nombre de la instancia a abrir.
	string instancia = getArg("-i",argc,argv);
	if (instancia.empty()){
		cout << "Entrada erronea o nula en argumento -i" << endl;
		return 0;
	}
	instancia = "dataset/" + instancia + ".txt";

    string tiempo = getArg("-t",argc,argv);
    float t;
	try{
		t = stof(tiempo);
		if(t <= 0){
			cout << "Entrada erronea o nula en argumento -t" << endl;
			return 0;
		}
	}catch(...){
		cout << "Entrada erronea o nula en argumento -t" << endl;
		return 0;
	}
    
	//Set de secuencias.
	vector<string> omega = getData(instancia);
	if(omega.empty()){
		cout << "Archivo no se puede leer o no existe" << endl;
		return 0;
	}
	int M = omega[0].length();	//Longitud M de cada secuencia.

	// Argumento obligatorio threshold.
	float th;
	try{
		th = stof(getArg("-th",argc,argv));
		if(th > 1 or th < 0){
			cout << "Entrada erronea o nula en argumento -th" << endl;
			return 0;
		}
	}catch(...){
		cout << "Entrada erronea o nula en argumento -th" << endl;
		return 0;
	}
	// Argumento opcional probabilidad epsilon
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

	int valorObj = getValorObjetivo(omega,GRASP(omega,M,e,th,t),M,th);

	return 0;
}