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
 * Tengo que pasar los assientos a el array de los assientos en la grafica.
 */
int imax = 220;
class espectador{
public:
    struct persona{
        string nom;
        string apellido;
        int edad;
        int asiento[2];
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
    void clientes(){
        for(int i = 0; i < ref; i++){
            std::cout << pers[i].nom << "  " << pers[i].apellido << " id: " << i << "\n";
        }
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
            for(int ii = 0; ii < 200; ii++){
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
    void reguistrar(int a[2], int id){
        n[a[0]][a[1]] = 1;
        for(int i = 0; i < 2; i++){
        pers[id].asiento[i] = a[i];
        }
    }
};
void p1(){
    int aux[2] = {20, 20};
    string nom;
    sala rock(aux);
    rock.mostrar();
    rock.entrar("laura", "laura", 30);
    int a[2] = {0, 0};
    rock.reguistrar(a, 0);
    rock.mostrar();
    //Menu de gestion de teatro
    int n;
    while(nom != "FIN"){
        limpiar();
        std::cout << "Este es el menu de la gestion  de la sala\n reservar assiento (r), reguistrar cliente(c) \n ";
        std::cin >> nom;
    if(nom == "c"){
        string inom;
        string ap;
        std::cout << "Dime su nombre\n";
        std::cin >> nom;
        inom = nom;
        std::cout << "Dime su apellido";
        std::cin >> nom;
        ap = nom;
        std::cout << "Dime su edad\n";
        std::cin >> n;
        rock.entrar(inom, ap, n);
    }
        if(nom == "r"){
            rock.mostrar();
            std::cout << "Dime el numero de assiento";
            std::cout << "\n fila: ";
            std::cin >> a[0];
            std::cout << "Columna\n";
            std::cin >> a[1];
            std::cout << "Dime el numero de id del cliente\n";
            rock.clientes();
            std::cin >> n;
            rock.reguistrar(a, n);
        
        }
    }
}
int main(int argc, char** argv) {
    p1();
    return 0;
}

