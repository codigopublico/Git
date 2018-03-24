/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 18 de marzo de 2018, 17:40
 */

#include <cstdlib>
#include <iostream>
#include "base.hpp"
using namespace std;

/*
 * 
 */
void p1(){
    prueva_lib();
}
void p2(){
    //esta es la prueva de entrada del programa
    int l = 20;
    int *i = new int[l];
    for(int f = 0; f < l; f++){
        i[f] = f;
    }
    int *o = new int[l];
    int aux = l;
    int aux2 = 5;
    red learn(i, o, aux, aux2);
}
int main(int argc, char** argv) {
    //p1();
    p2();
    return 0;
}

