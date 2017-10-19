/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 19 de octubre de 2017, 14:49
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include "grafica.hpp"
using namespace std;

/*
 * Este es el programa base....
 */
int imax = 220;
class espectador{
public:
    struct persona{
        string nom;
        string apellido;
        int edad;
    }pers[200];
    espectador(){
        ref = 0;
    }
    int ref;//esta es la refencia de la persona
    void entrar(string inom, string iapellido, int inedad){
        pers[ref].nom = inom;
        pers[ref].edad = inedad;
        pers[ref].apellido = iapellido;
        ref++;
    
    }
};
class sala : public espectador{
public:
    //int smax = 220;
    int n[200][200];//este es el array que define si esta lleno vacio el array.
    int aux[2];//este array es el que define el cuadrado de los assientos
    int per[220][220];//este es la referncia de la persona.
    /*sala(int in[][], int inaux[]){//este es el contructor de la classe
        for(int i = 0; i < smax; i++){
            for(int ii; ii < smax; ii++){
            n[i][ii] = in[i][ii];
        }}
        for(int i = 0; i < 2; i++){
        aux[i] = inaux[i];
        }
        ref = 0;
    }*///esto se ha de arreglar..........
    sala(int inaux[2]){
        std::cout << "Iniciado el constructor::: \n";
        for(int i = 0; i < 2; i++){
        aux[i] = inaux[i];
        std::cout << "aux: " << aux[i] << "  ";
        }
        for(int i = 0; i < 200; i++){//esto es la puesta a 0 de los assientos
            for(int ii = 0; i < 200; ii++){
                n[i][ii] = 0;
            }
        }
        ref = 0;
    }
    sala(){
     ref = 0;   
    }
    void mostrar(){
        grafica(aux, n);
    }
};
void p1(){
    int aux[2] = {2, 2};
    sala rock(aux);
    //rock.mostrar();
}
int main(int argc, char** argv) {
    p1();
    return 0;
}

