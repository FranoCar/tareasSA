#include <iostream>
#include <string.h>
#include <fstream>
#include <random>
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
			line.pop_back();
			data.push_back(line);
		}
		input.close();
	}
	return data;
}
int hummingDist(string A, string B, int M){
	int val = 0;
	for(int i = 0; i < M; i++){
		if (A[i] != B[i]){
			val++;
		}
	}
	return val;
}

string greedy_probabilista(vector<string> omega, int M, float th, float e){
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
	string solucion = greedy_probabilista(omega,M,th,0.1);

	cout << "Solución: ";
	cout << solucion << endl;

	int count = 0;
	for(string s: omega){
		int hd = hummingDist(s,solucion,M);
		if( (float)hd/M >= th){
			count++;
		}
	}
	cout << count << endl;

	return 0;
}