#include "funciones.h"

using namespace std;

// Función para buscar opción mediante el nombre, de la opción
// Ej: "-i"
// Si no encuentra la opción retorna vacío, manejar estos casos desde afuera.
string getArg(char const* val_esperado, int argc, char const *argv[]){
	string opcion = "";
	for(int i = 1; i < argc - 1; i++){
		if(strcmp(argv[i], val_esperado) == 0)
			opcion = argv[i+1];
	}
	return opcion;
}

//Función para leer el archivo de texto del dataset
//Si no encuentra el archivo o hay un error retorna un vector vacío.
vector<string> getData(string dir){
	vector<string> data;
	ifstream input(dir);
	if(input.is_open()){
		string line;
		while(getline(input,line)){
			data.push_back(line);
		}
		input.close();
	}
	return data;
}
