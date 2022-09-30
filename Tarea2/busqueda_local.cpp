#include "funciones.h"

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