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
 *Falta como poner eleminar i mostrar reguistros.
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
    }
    void nnclasse(string inclasse){
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
    classe *res2[200];
    int conta;
    int max;
    director(){
        max = 200;
        conta = 0; 
        
    }
    void ingresar_classe(classe virtua){
        std::cout << "Haciendo la classe virtual\n";
                res2[conta] = &virtua;
                conta++;
    }
    void mostrar(){ 
        for(int i = 0; i < conta; i++){
            for(int ii = 0; ii < res2[i]->nom[i].conta; ii++){
        std::cout << "Los alumnos son " << res2[i]->nom[ii].nombre << " de la classe "<<res2[i]->nom[ii].classes << "\n" ;
        }
        }
    } 
};
alumno vlaura[200];
classe vclasse[200];
void final(){
    int aux = 20;
    string nom = "alex";
    string fem = "laura";
    int n;
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
    mates.amedia();
    //sofware.amedia();
    director bigdata;
    bigdata.ingresar_classe(mates);
    bigdata.ingresar_classe(sofware);
    bigdata.mostrar();
    //Esta parte es para hacer pruevas de sofware i cuando la base del ejercio este terminado se eliminara
    classe *prueva[200];
    prueva[1] = &mates;
    prueva[1]->entar(laura, 1);
    prueva[1]->saludo();
    std::cout << prueva[1]->nclasse << " \n" ;
    //Esta es la parte del menu
    std::cout << "\nInciado el menu de las classes\n";
    int i = 0;
    int e = 0;
    int f;
    while(nom != "FIN"){
    std::cout << "\nPrimero dime que quieres hacer\nPoner un alumno(p), \nGestionar una classe(c), \neliminar ,classe o alumno,(e), \nponer notas(n)\n";
    std::cout << "\nFin para terminar\n";
    std::cin >> nom;
    if(nom == "p"){
        std::cout << "\nDime su nombre\n";
        std::cin >> nom;
        vlaura[i].igresar(nom);
        i++;
    }
    if(nom == "c"){
        std::cout << "\nQue quieres hacer crear una classe(c),\n o poner alumnos en una classe(entrar)\n";
        std::cin >> nom; 
        if(nom == "c"){
            std::cout << "\n Dime el nombre de la classe\n";
            std::cin >> nom;
            vclasse[e].nnclasse(nom);
            e++;
        }
        if(nom == "entrar"){
            std::cout << "\nlas classes disponibles son las siguientes. \n";
            for(int r = 0; r < e; r++){
                std::cout << "classe  " << vclasse[r].nclasse << "   "<<r << "\n";
            }
            std::cout << "Eligue una classe con la refernecia mostrada\n";
            std::cin >> n;
            f = n;
            std::cout << "Eliguieste la classe " << vclasse[n].nclasse << "\n";
            std::cout << "Ahora eligue un alumno/a\n Los disponibles son \n ";
            for(int r = 0; r < i; r++){
            std::cout << " " << vlaura[r].nombre << r << "  (ref)";
            }
            std::cout << "Ahora dime una referencia \n";
            std::cin >> n;
            vclasse[f].entar(vlaura[n], 1);
            
        }
    }
    
    }
}
int main(int argc, char** argv) {
    final();
    std::cout << "Pulsa una tecla para terminar\n";
    cin.get();
    return 0;
}

