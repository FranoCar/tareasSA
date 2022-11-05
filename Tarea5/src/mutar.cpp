#include "genetico.hpp"

using namespace std;

vector<string> mutar(vector<string> siggen, double rate){
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dis(0.0, 1.0);

	for(int i=0; i<siggen.size(); i++){
		for(int j=0; j<siggen[i].length(); j++){
			double p = dis(gen);
			if(p<rate){
				//cout<<"He mutado"<<endl;
				char aux = 'A';
				do{
					double bit = dis(gen);
					if(bit<0.25)
						aux = 'A';
					else if(bit<0.50 && bit>=0.25)
						aux = 'G';
					else if(bit<0.75 && bit>=0.50)
						aux = 'C';
					else if(bit<=1 && bit>= 0.75)
						aux = 'T';
				}while(aux == siggen[i][j]);
				siggen[i][j] = aux;
				
			}
		}
	}

	return siggen;
}