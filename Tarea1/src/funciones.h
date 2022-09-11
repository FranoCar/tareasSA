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
// Función para obtener la distancia humming entre 2 strings.
int hummingDist(string A, string B, int M){
	int val = 0;
	for(int i = 0; i < M; i++){
		if (A[i] != B[i]){
			val++;
		}
	}
	return val;
}
// Función para obtener el valor objetivo del problema FFMS, recibe el arreglo, el string solución, la longitud M y el threshold th.
int getValorObjetivo(vector<string> omega, string solucion,int M, float th){
	int count = 0;
	for(string s: omega){
		int hd = hummingDist(s,solucion,M);
		if((float)hd/M >= th){
			count++;
		}
	}
	return count;
}