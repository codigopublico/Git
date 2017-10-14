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
        //std::cout << "Poniendo la nota " << inota << " a " << nombre;
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
    classe(){
        conta = 0;
        nclasse = "Sin_classe";
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
            std::cout << "  " << nom[i].notas[ii] << " de la classe  " << nom[i].classes[ii]  << "\n";
        }
        std::cout << "\n";
        }
    }
    void pnotas(int nota, int ref){
        nom[ref].classes[nom[ref].conta] = nclasse;
        nom[ref].pnotas(nota);
    }
    void cmedia(){
        int sum = 0;
        int sum2 = 0;
        for(int i = 0; i < conta; i++){
            for(int ii = 0; ii < nom[i].conta; ii++){
            sum = nom[i].notas[ii] + sum;
            sum2++;
            }
        }
        std::cout << "\nLa nota media de la classe   " << nclasse << "  es:"  << sum/sum2 << "\n";
    }
    void amedia(){
        int no[conta];
        int re[conta];
    for(int i = 0; i < conta; i++){
       std::cout << "\nNotas de  media de " << nom[i].nombre << "  ";
            for(int ii = 0; ii < nom[i].conta; ii++){
                no[i] = no[i] + nom[i].notas[ii];
                re[i]++;
            }
       std::cout << " es de " << no[i]/re[i] << " de la classe " << nclasse << "\n";
    }

    }
    
};
class director{
public:
    classe res[200];
    int conta;
    director(){
        conta = 0;
    }
    void ingresar_classe(classe virtua){
        std::cout << "Haciendo la classe virtual\n";
                res[conta] = virtua;
                conta++;
    }
    void mostrar(){
        std::cout << "hola\n"; 
        for(int i = 0; i < conta; i++){
            for(int ii = 0; ii < res[i].nom[i].conta; ii++){
        std::cout << "Los alumnos son " << res[i].nom[ii].nombre << " de la classe "<<res[i].nom[ii].classes ;
        }
        }
    } 
};
void final(){
    int aux = 20;
    string nom = "alex";
    string fem = "laura";
    alumno hola;
    alumno laura;
    laura.igresar(fem);
    classe mates("mates");
    classe sofware("Sofware");
    hola.igresar(nom);
    for(int i = 0; i < aux; i++){
        mates.entar(hola, 1);
        sofware.entar(laura, 1);
    }
    mates.saludo();
    sofware.saludo();
    for(int i = 0; i < aux; i++){
        for(int ii = 0; ii < aux; ii++){
        mates.pnotas(rand()% 10, i);
        sofware.pnotas(rand()% 10, i);
        }
    }
    //mates.mnotas();
    sofware.mnotas();
    sofware.cmedia();
    mates.cmedia();
    //mates.amedia();
    //sofware.amedia();
    director bigdata;
    //bigdata.ingresar_classe(mates);
    //bigdata.ingresar_classe(sofware);
    //bigdata.mostrar();
    
}
int main(int argc, char** argv) {
    final();
    return 0;
}

