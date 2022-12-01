#ifndef FUNCIONES
#define FUNCIONES

#include <iostream>
#include <string.h>
#include <fstream>
#include <random>
#include <vector>
#include <string>
#include <map>
#include <chrono>
#include <array>
#include <utility>

using namespace std;

struct Opt{
	char const* name;
	int type;
	float l_limit;
	float u_limit = -1;
};

string getArg(char const* val_esperado, int argc, char const *argv[]);

vector<string> getData(string dir);

#endif