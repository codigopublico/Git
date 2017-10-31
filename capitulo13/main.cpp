/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 29 de octubre de 2017, 12:27
 */

#include <cstdlib>
#include <iostream>
#include "libreria.hpp"
using namespace std;
using namespace lib;
/*
 * 
 */
void final(){

    std::cout << "final"; 
    libro orwell("o", "1984", 1);
    libro mundo_feliz("orwell", "mundo", 2);
    libreria sintitulo;
    for(int i = 0; i < 20; i++){
    sintitulo.intro_libro(orwell);
    sintitulo.intro_libro(mundo_feliz);
    }
    sintitulo.mostrar();
    sintitulo.eliminar("o");
    std::cout << "Mostrando la biblioteca final\n";
    for(int i = 0; i < 150; i++){
        std::cout << ".";
    }
    sintitulo.mostrar();
}
int main(int argc, char** argv) {
    final();
    return 0;
}

