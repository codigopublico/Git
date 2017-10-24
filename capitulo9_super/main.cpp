
/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 15 de septiembre de 2017, 17:15
 */

#include <cstdlib>
#include <iostream>
#include <string>
//#include "garaje.h"
#include "definicion.cpp"
using namespace std;

/*
 * Hola mundo cybernetico
 */
 
void p3(){
	//hol();//esta es para comprovar la integridad de la bibletca del garaje antes de descomentar incluir
	def();//esta es la definicion del mismo
	std::cout << "Hola mundo\n";
	garaje maria(20, 30);
	maria.grafica();
}
int main(int argc, char** argv) {
    p3();
    std::cout << "hola mundo\n";
}

