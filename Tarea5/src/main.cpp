#include "funciones.h"
#include "FFMS_Generator/FFMS_Generator.hpp"

using namespace std;

int main(int argc, char const *argv[]){
	array<Opt,8> opt_args = {	
	/*Instancia del dataset:*/	{{"-i", 0},
	/*Tiempo de ejecución:	*/	{"-t", 2, 0.1},
	/*Threshold de FFMSP:	*/	{"-th", 2, 0, 1},
	/*Número de agentes:	*/	{"-na", 1, 1},
	/*Probabilidad mutación:*/	{"-mr", 2, 0, 1},
	/*Probabilidad epsilon: */	{"-e", 2, 0, 1},
	/*Probabilidad crossover*/	{"-cr", 2, 0, 1},
	/*Porcentaje elitismo:	*/	{"-elit", 2, 0, 1}}
							};
	// Mapa de valores, inicializado con valores por defecto para los argumentos opcionales.
	map<char const*,float> opt_val = {
										{"-th",0.8},
										{"-na",100},
										{"-e",0.1},
										{"-mr",0.1},
										{"-cr",0.2},
										{"-elit",0.2}
									};
	map<char const*,string> opt_strings;

	for(auto& opt : opt_args){
		string raw_arg = getArg(opt.name,argc,argv);
		if ( raw_arg.empty() ){
			if( opt_val.find(opt.name) == opt_val.end() && opt_strings.find(opt.name) == opt_strings.end() ){
				cout << "Entrada erronea o nula en argumento "<< opt.name << endl;
				return 0;
			}
			continue;
		}
		switch(opt.type){
			case 0:
				opt_strings[opt.name] = raw_arg;
				break;
			case 1:
				try{
					stoi(raw_arg);
				}catch(...){
					cout << "Entrada erronea o nula en argumento "<< opt.name << endl;
					return 0;
				}
			case 2:
				float float_arg;
				try{
					float_arg = stof(raw_arg);
				}catch(...){
					cout << "Entrada erronea o nula en argumento "<< opt.name << endl;
					return 0;
				}
				if(float_arg < opt.l_limit || (opt.u_limit != -1 && float_arg > opt.u_limit)){
					cout << "Entrada erronea o nula en argumento "<< opt.name << endl;
					return 0;
				}
				opt_val[opt.name] = float_arg;
				break;
		}
	}
	
	string instancia = "dataset/" + opt_strings["-i"] + ".txt";
	vector<string> omega = getData(instancia);
	if(omega.empty()){
		cout << "Archivo no se puede leer o no existe" << endl;
		return 0;
	}
	float tiempo = opt_val["-t"];
	float th = opt_val["-th"];
	int n_agentes = (int) opt_val["-na"];
	float mutation_rate = opt_val["-mr"];
	float epsilon = opt_val["-e"];
	float crossover_rate = opt_val["-cr"];
	float elitism_rate = opt_val["-elit"];

	auto generator = FFMS_Generator(omega,th);
	generator.AG(n_agentes,crossover_rate,mutation_rate,epsilon,tiempo,elitism_rate);

	return 0;
}