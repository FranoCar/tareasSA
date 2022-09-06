using namespace std;

string getArg(int i, char const* val_esperado, int argc, char const *argv[]){
	string opcion;
	int idx = i*2 + 1;
	if(argc > idx+1 and strcmp(argv[idx], val_esperado) == 0){
		opcion = argv[idx+1];
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