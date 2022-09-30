#include "funciones.h"

// Definición de la vecindad como todas las cadenas de caracteres similares
// a el string solucion diferentes en una letra.
vector<string> vecindad(string solucion){
    // Caracteres posibles, específicos a las instancias a usar.
	vector<char> alfabeto{'A','C','G','T'};
    vector<string> vecindad;
    
    //iterar en la solución
     for (int i = 0; i < solucion.length(); i++){
        //Agregar los 3 vecinos posibles al arreglo
        for(char letra : alfabeto){
        	string vecino = solucion;
            if(letra != solucion[i]){
                vecino[i] = letra;
            }
         	vecindad.push_back(vecino);
        }
     }
    return vecindad;
}

string siguiente_vecino(vector<string> omega, vector<string> vecindad, string solucion, int M, float th){
    // Valor objetivo del string solucion entregado
    int base = getValorObjetivo(omega,solucion,M,th);
    // Iteramos en la vecindad hasta encontrar un string mejor
    // que la solución actual.
    for (string vecino : vecindad){
        if(getValorObjetivo(omega,vecino,M,th) > base)
            return vecino;
    }
    return "";  //En el caso de no encontrar se retorna vacío.
}

string busqueda_local(vector<string> omega, string sol, int M, float th){
    // Se genera la vecindad de la solución inicial.
    vector<string> vecinos = vecindad(sol);
    // Se obtiene la primera mejor opción en la vecindad.
    string siguiente = siguiente_vecino(omega,vecinos,sol,M,th);	
	string sol_busqueda = sol; // Se le da valor inicial sol para evitar retornar vacío.
    // Mientras que existan vecinos mejores se sigue buscando
    while(!siguiente.empty()){
        siguiente = siguiente_vecino(omega,vecinos,sol_busqueda,M,th);

		if(!siguiente.empty()){
			sol_busqueda = siguiente;
			vecinos = vecindad(sol_busqueda);
		}
    }
    return sol_busqueda;
}