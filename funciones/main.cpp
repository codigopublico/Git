/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 7 de noviembre de 2017, 14:11
 * 
 * Este proyecto es para hacer mis biblieteca estadard de funciones...
 */

#include <cstdlib>
#include "mis_funciones.hpp"

using namespace std;

/*
 * 
 */
void p1(){
    int n[2] = {0, 1};
    std::cout << "n1   " << n[0] << "  n2   " << n[1] << "\n";
    inter(n[0], n[1]);
    std::cout << "n1   " << n[0] << "  n2   " << n[1] << "\n";
    string n2[2] = {"hola", "adios"};
    inter(n2[0], n2[1]);
    std::cout << "n1   " << n2[0] << "  n2   " << n2[1] << "\n";
}
int main(int argc, char** argv) {
    p1();
    return 0;
}

