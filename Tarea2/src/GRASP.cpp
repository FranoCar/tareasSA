#include "funciones.h"

using namespace std;

string GRASP(vector<string> omega, int M, float e, float th, float time){
    auto start = currentTime(); // Tiempo de inicio del algoritmo.
    // Guardamos siempre la mejor solución encontrada.
    string solucion = "";
    // Guardamos el tiempo para la solución final.
	float tiempo_encontrado = 0;
	int N = omega.size();
    // Mientras que tiempo límite no es superado se continúa iterando.
    while( (timeDiff(start)/1000) < time){
        // Greedy aleatorizado
        string nueva = greedy_probabilista(omega,M,e);
        // Busqueda local
        nueva = busqueda_local(omega,nueva,M,th);

        // Comparamos la nueva solución con la mejor actual.
        int calidad_nueva = getValorObjetivo(omega,nueva,M,th);
        if(solucion == "" || (calidad_nueva > getValorObjetivo(omega,solucion,M,th)) ){
            // Si es mejor se reemplaza la solución y se avisa por consola.
            solucion = nueva;
			tiempo_encontrado = timeDiff(start)/1000;
            cout << "Nueva calidad: " << (float)calidad_nueva/N << endl;
            cout << "Encontrado en: " << tiempo_encontrado << "(s)" << endl;
			cout << "-----" << endl;
        }
    }
	cout << "Calidad final: " << (float)getValorObjetivo(omega,solucion,M,th)/N << endl;
	cout << "Encontrado en: " << tiempo_encontrado << "(s)" << endl;
	return solucion;

}

