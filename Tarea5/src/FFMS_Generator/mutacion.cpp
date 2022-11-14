#include "FFMS_Generator.hpp"

using namespace std;

vector<string> FFMS_Generator::mutar(vector<string> siggen, float rate, vector<int> fitness, float elit){

	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dis(0.0, 1.0);
	uniform_int_distribution<size_t> r_pick_alfabeto(0,alfabeto.size()-1);
	uniform_int_distribution<size_t> r_pick_letra(0,M-1);

	vector<int> fitAux = fitness;
	sort(fitAux.begin(),fitAux.end());
	int umbralElite = fitAux[(fitAux.size()-1)*(1-elit)]; //elitismo

	for(int i = 0; i < siggen.size(); i++){
		if(fitness[i] > fitness[umbralElite]) continue;
		if(dis(gen) < rate){
			int j = r_pick_letra(gen);
			char aux;
			do{
				aux = alfabeto[r_pick_alfabeto(gen)];
			}while(siggen[i][j] == aux);
			siggen[i][j] = aux;
		}
	}
	return siggen;
}