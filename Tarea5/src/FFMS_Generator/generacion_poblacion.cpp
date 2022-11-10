#include "FFMS_Generator.hpp"

using namespace std;

vector<string> FFMS_Generator::gen_poblacion(int n_agentes){
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<size_t> r_pick(0,alfabeto.size()-1);

	vector<string> poblacion;
	for(int i = 0; i < n_agentes; i++){
		string agente = "";
		for (int j = 0; j < M; j++){
			agente.push_back(alfabeto[r_pick(gen)]);
		}
		poblacion.push_back(agente);
	}
	return poblacion;
}