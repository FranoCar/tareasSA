#ifndef GENERADOR
#define GENERADOR

#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <chrono>

using namespace std;

// inline copia el contenido de la función donde es llamada en tiempo de compiĺación
// así que estas funciones son solo para simplificar código.
// Como son funciones que reemplazarán el código, la definición complete debe ir en
// el header file.
inline chrono::time_point<std::chrono::high_resolution_clock> currentTime(){
	return chrono::high_resolution_clock::now();
}
inline float timeDiff(chrono::time_point<std::chrono::high_resolution_clock> start){
	return (float)chrono::duration_cast<chrono::milliseconds>(
						currentTime() - start
                            ).count();
}
inline void lognewr(float score, float tiempo_encontrado){
	cout << "Nueva calidad: " << score << endl;
    cout << "Encontrado en: " << tiempo_encontrado << "(s)" << endl;
    cout << "-----" << endl;
}

class FFMS_Generator{
	private:
		vector<string> omega;
		int N;
		int M;
		float th;
		vector<char> alfabeto{'A','C','G','T'};
		vector<string> mutar(vector<string> siggen, float rate);
		vector<string> reemplazo(vector<string> poblacion,vector<string> hijos, vector<int> fitness);
		vector<string> gen_poblacion(int n_agentes);
		vector<string> crossover(string padre1, string padre2);
		string seleccion(vector<string> poblacion, vector<int> fitness);
		int getFitness(string solucion);
	public:
		FFMS_Generator(vector<string> _omega, float _th);
		string AG(int n_agentes, float crossover_rate, float e, float time);
};

#endif