#include <iostream>
#include <string.h>
#include <fstream>
#include <random>
#include <vector>
#include <string>
#include <map>
#include <chrono>
#include "funciones.h"

using namespace std;


vector<string> vecindad(string sol){
    // Caracteres posibles, específicos a las instancias a usar.
	vector<char> alfabeto{'A','C','G','T'};
    vector<string> retorno;
    
    //iterar en la solución
     for (int i = 0; i < sol.length(); i++){
        //Agregar los 3 vecinos posibles al arreglo
        // Error 2: string vecino = sol; <- tiene que estar en el for de abajo.
        for(char letra : alfabeto){
        	// Sólución 2 ------
        	string vecino = sol;
        	// -----------------
            if(letra != sol[i]){
                vecino[i] = letra;
            }
            // Solución 1 ------------
         	retorno.push_back(vecino);
         	// -----------------------   
        }
        // ERROR 1: retorno.push_back(vecino); <- tiene que estar dentro del for de arriba
     }
    return retorno;
}

string siguiente_vecino(vector<string> omega, vector<string> vecindad, string sol, int M, float th){
    int base = getValorObjetivo(omega,sol,M,th);
    for (string vecino : vecindad){
        if(getValorObjetivo(omega,vecino,M,th) > base)
            return vecino;
    }
    return "";
}

string busqueda_local(vector<string> omega, string sol, int M, float th){
    vector<string> vecinos = vecindad(sol); 				// Se genera la vecindad de la solución inicial.
    string siguiente = siguiente_vecino(omega,vecinos,sol,M,th);	// Se obtiene la primera mejor opción en la vecindad.
	string esta = sol; // Se le da valor inicial sol para evitar retornar vacío.
	// Error 6: siguiente siempre termina siendo vacío al final.
    while(siguiente != ""){
        string siguiente = siguiente_vecino(omega,vecinos,esta,M,th); //DE AQUI NO siguiente SALIENDO
		

		if(siguiente != ""){	// Solución 6: usar un buffer en vez de solo una variable "esta"
			esta = siguiente;
			vecinos = vecindad(esta);
		}else{
			break;
		}
        // Error 3: No se está generando la vecindad nueva, si no usando la de la solución antigua.
    }
    return esta;
}

string greedy_probabilista(vector<string> omega, int M, float e){
	// Caracteres posibles, específicos a las instancias a usar.
	vector<char> alfabeto{'A','C','G','T'}; 

	// Estructuras para generar números aleatorios
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dis(0.0, 1.0);

	string solucion; // Solución inicialmente vacía
	for(int i = 0; i < M; i++){		//Iteramos por posición desde 0 a M.
		map<char, int> frecuencia;	// Mapa para comparar frecuencia de caracteres.
		// Conteo de frecuencias de caracteres.
		for(string s : omega){
			char c = s.at(i);
			if(frecuencia.find(c) == frecuencia.end()){
				frecuencia[c] = 1;
			}else{
				frecuencia[c] = frecuencia[c] + 1;
			}
		}
		// Búsqueda de caracter menos frecuente.
		char minChar = frecuencia.begin()->first;
		for(auto const& pair : frecuencia){
			if(frecuencia[pair.first] < frecuencia[minChar])
				minChar = pair.first;
		}
		// Se selecciona como siguiente en la solución la opción greedy con probabilidad 1-e.
		// Se selecciona una opción aleatoria con una probabilidad e.
		double p = dis(gen);
		uniform_int_distribution<size_t> r_pick(0,alfabeto.size()-1);
		if(p < e){
			solucion.push_back(alfabeto[r_pick(gen)]);
		}else{
			solucion.push_back(minChar);
		}
	}
	return solucion;
}

string GRASP(vector<string> omega, int M, float e, float th, float time){
    auto start = chrono::high_resolution_clock::now();
    string solucion = "";
    float tiempo_segundos = 0;
	float tiempo_encontrado = 0;
	int N = omega.size();
    while(tiempo_segundos < time){
        tiempo_segundos = (float) chrono::duration_cast<chrono::milliseconds>(
                                chrono::high_resolution_clock::now() - start
                            ).count()/1000; //Error 5: *1000;
        //Greedy aleatorizado
        string nueva = greedy_probabilista(omega,M,e);
        //Busqueda local
        nueva = busqueda_local(omega,nueva,M,th);
        if(solucion == "" || (getValorObjetivo(omega,solucion,M,th) < getValorObjetivo(omega,nueva,M,th)) ){
            solucion = nueva;
            if(solucion != ""){
				tiempo_encontrado = (float) chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start).count()/1000;
                cout << "Nueva calidad: " << (float)getValorObjetivo(omega,nueva,M,th)/N << endl;
                cout << "Encontrado en: " << tiempo_encontrado /* Error 5: 1000 */ << "(s)" << endl;
				cout << "-----" << endl;
            }
        }
		
    }
	cout << "Calidad final: " << (float)getValorObjetivo(omega,solucion,M,th)/N << endl;
	cout << "Encontrado en: " << tiempo_encontrado << "(s)" << endl;
	// Error 4: return 0; <- return 0??? en una función que retorna strings?
	// Solución 4 --
	return solucion;
	// -------------

}

int main(int argc, char const *argv[]){
	//Nombre de la instancia a abrir.
	string instancia = getArg("-i",argc,argv);
	if (instancia.empty()){
		cout << "Entrada erronea o nula en argumento -i" << endl;
		return 0;
	}
	instancia = "dataset/" + instancia + ".txt";

    string tiempo = getArg("-t",argc,argv);
    float t;
	try{
		t = stof(tiempo);
		if(t <= 0){
			cout << "Entrada erronea o nula en argumento -t" << endl;
			return 0;
		}
	}catch(...){
		cout << "Entrada erronea o nula en argumento -t" << endl;
		return 0;
	}
    
	//Set de secuencias.
	vector<string> omega = getData(instancia);
	if(omega.empty()){
		cout << "Archivo no se puede leer o no existe" << endl;
		return 0;
	}
	int M = omega[0].length();	//Longitud M de cada secuencia.

	// Argumento obligatorio threshold.
	float th;
	try{
		th = stof(getArg("-th",argc,argv));
		if(th > 1 or th < 0){
			cout << "Entrada erronea o nula en argumento -th" << endl;
			return 0;
		}
	}catch(...){
		cout << "Entrada erronea o nula en argumento -th" << endl;
		return 0;
	}
	// Argumento opcional probabilidad epsilon
	string e_arg = getArg("-e",argc,argv);
	float e = 0.1;
	if(!e_arg.empty()){
		try{
			e = stof(e_arg);
			if(e > 1 or e < 0){
				cout << "Entrada erronea en argumento -e" << endl;
				return 0;
			}
		}catch(...){
			cout << "Entrada erronea en argumento -e" << endl;
			return 0;
		}
	}

	auto start = chrono::high_resolution_clock::now();
	int valorObj = getValorObjetivo(omega,GRASP(omega,M,e,th,t),M,th);
	auto stop = chrono::high_resolution_clock::now();
	int N = omega.size();
	cout << endl;
	float duration = (float)chrono::duration_cast<chrono::microseconds>(stop - start).count()/1000;
	cout << endl;

	return 0;
}