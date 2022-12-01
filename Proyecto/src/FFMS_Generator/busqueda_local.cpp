#include "FFMS_Generator.hpp"

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

string FFMS_Generator::siguiente_vecino(vector<string> vecindad, string solucion){
    // Valor objetivo del string solucion entregado
    int base = getFitness(solucion);
    // Iteramos en la vecindad hasta encontrar un string mejor
    // que la solución actual.
    for (string vecino : vecindad){
        if(getFitness(vecino) > base)
            return vecino;
    }
    return "";  //En el caso de no encontrar se retorna vacío.
}

string FFMS_Generator::busqueda_local(string sol){
    // Se genera la vecindad de la solución inicial.
    vector<string> vecinos = vecindad(sol);
    // Se obtiene la primera mejor opción en la vecindad.
    string siguiente = siguiente_vecino(vecinos,sol);
	string sol_busqueda = sol; // Se le da valor inicial sol para evitar retornar vacío.
    // Mientras que existan vecinos mejores se sigue buscando
    while(!siguiente.empty()){
        siguiente = siguiente_vecino(vecinos,sol_busqueda);

		if(!siguiente.empty()){
			sol_busqueda = siguiente;
			vecinos = vecindad(sol_busqueda);
		}
    }
    return sol_busqueda;
}