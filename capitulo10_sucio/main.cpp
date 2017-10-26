/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 26 de octubre de 2017, 21:49
 */

#include <cstdlib>
#include "classes.hpp"
using namespace std;

/*
 * 
 */
void p1(){
    g::gara maria;
    maria.grafica();
    g::vehiculo seat("rojo", 20, "seat", "9");
    int n[2] = {1, 1};
    maria.entrar(seat, n);
    maria.grafica();
}

int main(int argc, char** argv) {
    p1();
    return 0;
}
