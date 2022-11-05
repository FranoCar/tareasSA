#include "genetico.hpp"

using namespace std;

vector<string> crossover(string padre1, string padre2){
	random_device rd;
	mt19937 gen(rd());
	
	uniform_int_distribution<size_t> p(0,100);

	for(int i = 0; i < padre1.size(); i++){
		if(p(gen) < 50){
			char aux = padre1[i];
			padre1[i] = padre2[i];
			padre2[i] = aux; 
		}
	}

	vector<string> hijos;
	hijos.push_back(padre1);
	hijos.push_back(padre2);

	return hijos;
}