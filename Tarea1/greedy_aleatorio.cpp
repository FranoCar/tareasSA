#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

string getArg(int i, char const* val_esperado, int argc, char const *argv[]){
	string error_msg = 	"Uso correcto del programa:\n"
						"./<programa> -i <instancia-problema> -th <treshold>\n\n"
						"instancia-problema := uno de los archivos dentro de la carpeta 'dataset' \n"
						"threshold := un valor de coma flotante entre 0 y 1\n";
	string opcion;
	int idx = i*2 + 1;
	if(argc > idx+1 and strcmp(argv[idx], val_esperado) == 0){
		opcion = argv[idx+1];
	}else{
		cout << error_msg << endl;
	}
	return opcion;

}

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

string greedy_probabilista(vector<string> omega, int M, float th){
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
		for(auto const& pair : frecuencia){
			cout << pair.first << "->" << pair.second << endl;
		}
		break;
	}
	return solucion;
}
int main(int argc, char const *argv[]){
	//Nombre de la instancia a abrir.
	string instancia = getArg(0,"-i",argc,argv);
	if (instancia.empty())
		return 0;
	//Treshold.
	float th = stof(getArg(1,"-th",argc,argv));
	//Set de secuencias.
	vector<string> omega; 
	omega = getData("dataset/" + instancia + ".txt");
	//Longitud M de cada secuencia.
	int M = omega[0].length();

	string solucion = greedy_probabilista(omega,M,th);



	return 0;
}