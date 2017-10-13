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
 *Falta ponerle las classes i  classificar para ello i hacerlo random. Todo. Para manya
 */
int max = 200;


class alumno{
public:
    int max;
    string nombre;
    int *notas;
    int conta;
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
            std::cout << "  " << nom[i].notas[ii] << "\n";
        }
        std::cout << "\n";
        }
    }
};
void final(){
    alumno virtua;
    alumno alex;
    classe mates("mates");
    string nom2[] = {"maria", "Joan"};
    alex.igresar(nom2[1]);
    alex.pnotas(8);
    virtua.igresar(nom2[0]);
    mates.entar(virtua, 1);
    mates.entar(alex, 1);
    mates.saludo();
    mates.mnotas();
    
}
int main(int argc, char** argv) {
    final();
    return 0;
}

