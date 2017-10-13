/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 13 de octubre de 2017, 15:10
 */

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

/*
 * 
 */
class alumno{
public:
    int max;
    string *nombre;
    int *notas;
    int conta;
    int ref[200];
    alumno(){
        max = 200;
        string *nom = new string[max];
        nombre = nom;
        int *notas = new int[max];
        conta = 0;
    }
    void poner(string inom){
        nombre[conta] = inom;
        ref[conta] = conta;
        conta++;
    }
    void mostrar(){
        for(int i = 0; i <= conta; i++){
            std::cout << nombre[ref[i]] << "\n";
        }
    }
};

void final(){
    alumno virtua;
    virtua.poner("maria");
    virtua.poner("Joan");
    virtua.mostrar();
}
int main(int argc, char** argv) {
    final();
    return 0;
}

