#include "genetico.hpp"

using namespace std;

vector<string> gen_poblacion(int n_agentes, int M){
	vector<char> alfabeto{'A','C','G','T'};

	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dis(0.0, 1.0);

	uniform_int_distribution<size_t> r_pick(0,alfabeto.size()-1);

	vector<string> poblacion;
	for(int i = 0; i < n_agentes; i++){
		string agente = "";
		for (int j = 0; j < M; j++){
			agente.push_back(alfabeto[r_pick(gen)]);
		}
		cout <<"agente " << i << ": "<< agente << endl;
		poblacion.push_back(agente);
	}
	return poblacion;
}