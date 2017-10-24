/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 23 de octubre de 2017, 19:48
 */

#include <cstdlib>
#include "garaje.hpp"
using namespace std;

/*
 * Este es un ejemplo de usar librerias bien echas
 */
using namespace g;
void classe(){
    gara maria;
    maria.grafica();
    maria.get(10, 10);
    maria.grafica();
}
int main(int argc, char** argv) {
    classe();
    return 0;
}

