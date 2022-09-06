#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

string getArg(int i, char const* val_esperado, int argc, char const *argv[]){
	string error_msg = "Uso correcto del programa: \n\
./<programa> -i <instancia-problema> -th <treshold>";
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

int main(int argc, char const *argv[]){
	string instancia = getArg(0,"-i",argc,argv);
	float th = stof(getArg(1,"-th",argc,argv));
	vector<string> omega; //Set de secuencias

	if (!instancia.empty()){
		omega = getData("dataset/" + instancia + ".txt");
		cout << omega[0] << endl;
	}else{
		return 0;
	}

	return 0;
}