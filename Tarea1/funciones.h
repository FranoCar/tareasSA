#include <string>
#include <fstream>

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