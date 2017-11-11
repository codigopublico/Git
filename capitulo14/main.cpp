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
 * Esto es la classe de calculadora
 */
void limp(){
    for(int i = 0; i < 100; i++){
        std::cout << "\n";
    }
}
void limp(int n){
    for(int i = 0; i < n; i++){
        std::cout << "\n";
    }
}
void calc(){
    Calculadora oclac(0);
    oclac.getNumero();
    oclac.suma(20, 30);
    std::cout << oclac.getNumero() << "\n";
    oclac.set(0);
    std::cout << oclac.getNumero() << "\n";
    
}
void p1(){
    Calculadora o;
    o.suma(20, 30);
    Calculadora a(o);
    std::cout << a.getNumero() << "\n";
    std::cout << o.getNumero() << "\n";
}
int ins(){
    int n;
    std::cout << "Dime un numero\n";
    std::cin >> n;
    return n;
}
void menu(){
    Calculadora w;
    int n;
    int f = 1;
    string n1;
    while(n1 != "0"){
        limp(10);
    std::cout << "Dime un numero \n";
    std::cout << "El resulado de las operaciones es:   " << w.getNumero() << "\n"; 
    std::cin >> n;
    w.set(n);
    std::cout << "Dime las operaciones que quieres hacer con dicho numero\n";
    std::cout << "Sumar(s)\n, restar(r)\n, dividir(d)\n, multiplicar(m)\n";
    std::cin >> n1;
    if(n1 == "s"){
        n = ins();
        w.suma(n);
    }
    if(n1 == "r"){
        n = ins();
        w.resta(n);
    }
    if(n1 == "d"){
        n = ins();
        w.resta(n);
    }
    if(n1 == "m"){
        n = ins();
        w.multi(n);
    }
    std::cout << "Para salir 0\n";
    std::cin >> n1;
    }
    
}
int main(int argc, char** argv) {
    calc();
    p1();
    menu();
    return 0;
}

