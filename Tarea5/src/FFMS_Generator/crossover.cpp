#include "FFMS_Generator.hpp"

using namespace std;

vector<string> FFMS_Generator::crossover(string padre1, string padre2){
	random_device rd;
	mt19937 gen(rd());
	
	// UNIFORM CROSSOVER

	/*
	uniform_int_distribution<> p(0.0,1.0);

	for(int i = 0; i < padre1.size(); i++){
		if(p(gen) < 0.5){
			char aux = padre1[i];
			padre1[i] = padre2[i];
			padre2[i] = aux; 
		}
	}
	*/

	// 2-POINT CROSSOVER

	uniform_int_distribution<> rand1(0,padre1.size()-1);
	int split_point1 = rand1(gen);
	uniform_int_distribution<> rand2(split_point1,padre1.size()-1);
	int split_point2 = rand2(gen);

	for(int i=split_point1; i<split_point2+1; i++){
		char aux = padre1[i];
		padre1[i] = padre2[i];
		padre2[i] = aux;
	}

	vector<string> hijos;
	hijos.push_back(padre1);
	hijos.push_back(padre2);

	return hijos;
}