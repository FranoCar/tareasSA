#include "funciones.h"

using namespace std;

string GRASP(vector<string> omega, int M, float e, float th, float time){
    auto start = currentTime();
    string solucion = "";
    float tiempo_segundos = 0;
	float tiempo_encontrado = 0;
	int N = omega.size();
    while(tiempo_segundos < time){
        tiempo_segundos = timeDiff(start)/1000; //Error 5: *1000;
        //Greedy aleatorizado
        string nueva = greedy_probabilista(omega,M,e);
        //Busqueda local
        nueva = busqueda_local(omega,nueva,M,th);
        if(solucion == "" || (getValorObjetivo(omega,solucion,M,th) < getValorObjetivo(omega,nueva,M,th)) ){
            solucion = nueva;
            if(solucion != ""){
				tiempo_encontrado = timeDiff(start)/1000;
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

