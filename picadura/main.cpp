/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 26 de octubre de 2017, 0:12
 */

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

/*
 *Este arvhivo es para hacer lo de punteros a estructuras 
 */
struct prueva{
    public:
        int num;
        string hola;
    };
class hola{
    public:
    struct prueva c[900];
    struct prueva *l;
    hola(){
        l = &c[0];
    }
};
void p1(){
    hola h;
    h.l->hola = "hola  ";
    std:: cout << h.l->hola;
    h.l++;
    h.l->hola = "adios  ";
    for(int i = 2; i > 0; i--){
        std::cout << h.l->hola << "  ";
        h.l--;
    }
}
void p2(){
    int *pP = new int;
    //int P = 0;
    //pP = &P;
    *pP = 50;
    std::cout << "P " << *pP;
    delete pP;
    std::cout << "\nPDeleete " << *pP;
}
void p3(){
    const int *edad;
    int e;
    edad = &e;
    e = 25;
    std::cout << "edad1   " << *edad << "\n";
    //edad = 30;
    std::cout << "edad 2  " << *edad << "\n";
    
    //const int *const edad;
    //edad = 25;
    int const edad; 
}
int main(int argc, char** argv) {
    //p1();
    //p2();
    p3();
    return 0;
}

