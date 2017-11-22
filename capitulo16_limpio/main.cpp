/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 22 de noviembre de 2017, 17:43
 */

#include <cstdlib>
#include <mia/no_renderizadas/mis_funciones.hpp>
#include "hospital.hpp"
using namespace std;

/*
 * 
 */
void p1(){
    int a = 20;
    hospi::hosipta St(a);
    St.alta(0, 0, "Wichita");
}
int main(int argc, char** argv) {
    p1();
    return 0;
}

