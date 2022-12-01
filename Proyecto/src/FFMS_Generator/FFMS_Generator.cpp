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
int FFMS_Generator::getFitness(string solucion){
	int count = 0;
	for(string s: omega){
		int hd = hammingDist(s,solucion,M);
		if((float)hd/M >= th){
			count++;
		}
	}
	return count;
}
FFMS_Generator::FFMS_Generator(vector<string> _omega, float _th){
	omega = _omega;
	N = _omega.size();
	M = _omega[0].length();
	th = _th;
}