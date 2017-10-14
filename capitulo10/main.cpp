/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 13 de octubre de 2017, 15:10
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <stdlib.h> // esta es la liberria de rand()
using namespace std;

/*
 *Falta poner una funcion que englove todas las demas funciones.
 */
int max = 200;


class alumno{
public:
    int max;
    string nombre;
    int *notas;
    int conta;
    string classes[200];
    alumno(){
        max = 200;
        int *nota = new int[max];
        notas = nota;
        conta = 0;
    }
    void igresar(string inom){
        nombre = inom;
    }
    void mostrar(){
            std::cout << nombre << "\n";
    }
    void pnotas(int inota){
        notas[conta] = inota; 
        std::cout << "Poniendo la nota " << inota << " a " << nombre;
        conta++;
    }
};
class classe{
public:
    alumno nom[200];
    int conta;
    string nclasse;
    classe(string inclasse){
        conta = 0;
        nclasse = inclasse;
    }
    void entar(alumno inom, int total){
        int i = 0;
        for(; i < total; i++ ){
            nom[conta + i] = inom;
        }
        conta = i + conta;
    }
    void saludo(){
        for(int i = 0; i < conta; i++){
        std::cout << "Te saluda " << nom[i].nombre << "\n";
        }
    }
    void mnotas(){
    for(int i = 0; i < conta; i++){
        std::cout << "\nNotas de  " << nom[i].nombre << "  ";
        for(int ii = 0; ii < nom[i].conta; ii++){
            std::cout << "  " << nom[i].notas[ii] << " de la classe  " << nom[i].classes[ii] ;
        }
        std::cout << "\n";
        }
    }
    void pnotas(int nota, int ref){
        nom[ref].classes[nom[ref].conta] = nclasse;
        nom[ref].pnotas(nota);
    }
};
void final(){
    int aux = 20;
    string nom = "alex";
    alumno hola;
    classe mates("mates");
    hola.igresar(nom);
    for(int i = 0; i < aux; i++){
        classe.entar(hola, 1);
    }
    classe.saludo();
    
}
int main(int argc, char** argv) {
    final();
    return 0;
}

