/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 20 de octubre de 2017, 14:56
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "calculadora.hpp"
using namespace std;

/*
 * 
 */


void calc(){
    Calculadora oclac(0);
    oclac.getNumero();
    oclac.suma(20, 30);
    std::cout << oclac.getNumero() << "\n";
    oclac.set(0);
    std::cout << oclac.getNumero() << "\n";
    
}
int main(int argc, char** argv) {
    calc();
    return 0;
}

