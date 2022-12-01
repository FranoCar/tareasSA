#include "FFMS_Generator.hpp"

// Función para obtener la distancia hamming entre 2 strings.
int hammingDist(string A, string B, int M){
	int val = 0;
	for(int i = 0; i < M; i++){
		if (A[i] != B[i]) val++;
	}
	return val;
}
// Función para obtener el valor objetivo del problema FFMS, recibe el arreglo, el string solución, la longitud M y el threshold th.
int FFMS_Generator::getScore(string solucion){
	int count = 0;
	for(string s: omega){
		int hd = hammingDist(s,solucion,M);
		if((float)hd/M >= th){
			count++;
		}
	}
	return count;
}
void FFMS_Generator::generateT(){
	for(int i = 0; i < M; i++){
		vector<int> row(M);
		T.push_back(row);
	}
	T[0][0] = 1;
	for(int k = 1; k < M; k++){
		T[0][k] = 0;
	}
	for(int L = 1; L < M; L++){
		for(int k = 0; k < M; k++){
			T[L][k] = 	T[L-1][k-1] \
						+ (alfabeto.size()-2)*T[L-1][k] \
						+ T[L-1][k+1];
		}
	} 
}
float FFMS_Generator::getFitness(string solucion){
	int near = 0;
	vector<float> distances(N);
	vector<float> costs(N);
	for(int i = 0; i < N; i++){
		distances[i] = hammingDist(solucion, omega[i], M);
		costs[i] = M - distances[i];
		if((float)distances[i]/M < th){
			near += 1;
		}
	}
	int f = N - near;
	float GpC = 0;
	if( near > 0 ){
		float sumGpC = 0;
		for(int i = 0; i < N; i++){
			if((float)distances[i]/M >= th){
				continue;
			}
			float gain = 1;
			for (int j = 0; j < N; j++){
				if(i == j){
					continue;
				}
				float sumP = 0;
				for(int k = j; k < i; k++){
					sumP += (float)T[costs[i]][costs[k]]/pow(alfabeto.size(),costs[i]);
				}
				gain += sumP;
			}
			sumGpC += gain/costs[i];
		}
		GpC = sumGpC/near;
	}
	return (N+1)*f+GpC;
}

FFMS_Generator::FFMS_Generator(vector<string> _omega, float _th){
	omega = _omega;
	N = _omega.size();
	M = _omega[0].length();
	th = _th;
	generateT();
}