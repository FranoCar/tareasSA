#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <vector>
#include "funciones.h"

using namespace std;

int main(int argc, char const *argv[]){
    string i = getArg(0, "-i", argc, argv);
    float th = stof(getArg(1, "-th", argc, argv));

    vector<string> omega; //Set de secuencias

	if (!i.empty()){
		omega = getData("dataset/" + i + ".txt");
	}else{
		return 0;
	}

    return 0;
}
