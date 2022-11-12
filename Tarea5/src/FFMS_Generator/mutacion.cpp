#include "FFMS_Generator.hpp"

using namespace std;

vector<string> FFMS_Generator::mutar(vector<string> siggen, float rate){

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<size_t> r_pick(0,alfabeto.size()-1);

	uniform_real_distribution<> dis(0.0, 100.0);

	for(int i = 0; i < siggen.size(); i++){
		for(int j=0; j < M; j++){
			if(dis(gen) < rate){
				char aux;
				do{
					aux = alfabeto[r_pick(gen)];
				}while(siggen[i][j] == aux);
				siggen[i][j] = aux;
			}
		}
	}
	return siggen;
}