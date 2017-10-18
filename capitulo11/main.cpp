/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 17 de octubre de 2017, 15:16
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

/*
 * 
 */
//int max = 200;
class operar{//esta es la base de datos i las operaciones matematicas.....
public:
    int r;
    int id;
    struct cuento{
        int d;
        string titular;
    }cuentas[200];//aqui se define todo el nombre de la estructrua del array
    operar(){
    r = 0;//es el total de todas las cuentas
    id = 0;
    };
    void ingresar(int n){
        cuentas[id].d = cuentas[id].d + n;
    
    }
    void sacar(int n){
        if(cuentas[id].d -n >0){
        cuentas[id].d = cuentas[id].d - n;
        }else{
            std::cout << "\nError porfavor gana dinero :P\n";
        }
    }
};
class cuenta : public operar{
public:
    int r = 0;
    int id = 0;
    void crear(string nom){
        cuentas[r].titular = nom;
        cuentas[r].d = 0;
        r++;
    }
    void tmos(){
        for(int i = 0; i < r; i++){
            std::cout << "  " << cuentas[i].titular << "    " << cuentas[i].d  << "  " << i <<" (ref) " << "\n";
        }
    }//esta es la muestra todas cuentas
    void saldo(){
        std::cout <<  "\n" << cuentas[id].titular << " Tiene el saldo  " << cuentas[id].d << "\n";
    }
};
class banco : public cuenta{
public:
    int id = 0;
    /*banco ::  operar() {
    
    } el maldito contructor*/
    void select(int inid){
        id = inid;
    }
    void elimnar(int n){
        std::cout << "\nEspejo; del codigo\n" << r << "\n";
        cuentas[199].d = 0;
        cuentas[199].titular = "  ";
        for(int i = 0; i <= r; i++){
            std::cout << "\nEspejo; del codigo\n";
            if(i == n){
                cuentas[i] = cuentas[199];//este es el que falta.
            }
            /*if(cuentas[i + 1].titular == NULL){
                std::cout << "Es null\n";
            }*/
            if(i > n){
                cuentas[199] = cuentas[i + 1];
                cuentas[i + 1] = cuentas[i];
                cuentas[i] = cuentas[199];
            }
        }
        r--;        
        std::cout << "\nEspejo; del codigo\n" << r << "\n";

        
    }
    
}; 


void p1(){
    int n;
    banco by;
    for(int i = 0; i < rand()% 30; i++){
        if(rand()%2 == 0){
    by.crear("joan");
        }else{
    by.crear("Alex");
        }
        by.select(i);
        by.ingresar(rand()%1000);
        by.sacar(rand()%100);
        by.saldo();
    }
    by.tmos();
    std::cout << "\nFin de la prueva random \n\n";
    for(int i = 0; i < 100; i++){
        std::cout << "\n";
    }
    banco by2;
    string nom;
    while(nom != "s"){
    for(int i = 0; i < 100; i++){
        std::cout << "\n";
    }
    std::cout << "\nInicio del menu \n";
    std::cout << "Dime que quieres hacer \n crear una cuenta(c), \n borrar una cuenta(b)\n operar con una cuenta(o)\n listar las cuentas\n salir(s)\n \n";
    std:: cin >> nom;
    if(nom == "c"){
        std::cout << "Dime el nombre del titular\n";
        std::cin >> nom;
        by2.crear(nom);
    }
    if(nom=="b"){
        std::cout << "\nPara ello neccessito la contrasenya del codigo\n";
        std::cin >> nom;//pass:1234
        if(nom == "1234"){//si tengo tiempo lo codifico
            std::cout << "Te muestro las cuentas";
            by2.tmos();
            std::cout << "Dime la referncia";
            std::cin >> n;
            by2.elimnar(n);
        }
    }
    if(nom == "o"){
        std::cout << "\n Dime la referencia del  numero de cuenta al que quieras acceder \n";
        for(int r; r < by2.r; r++){
        std::cout << by2.cuentas[r].titular << "  " << r << "\n";
        }
        std::cin >> n;
        std::cout << "\nPorfavor pon la contrasenya\n";
        std::cin >> nom;
        if(nom == "1234"){
        by2.select(n);
        while(nom != "FIN"){
        std::cout << "\n Que quieres hacer mirar el saldo(s), \nRetirar efictivo(r), \ningreso(i), \nSalir(FIN)\n";
        std::cin >> nom;
        if(nom=="s"){
            by2.saldo();
        }
        if(nom=="r"){
            std::cout << "Cuanto quieres sacar\n";
            std::cin >> n;
            by2.sacar(n);
        }
        if(nom=="i"){
            std::cout << "Quanto quieres ingresar\n";
            std::cin >> n;
            by2.ingresar(n);
        }
        }}else{
            std::cout << "Contrasenya erronea";
        }
    }
    if(nom=="l"){
    
    }
    }
    
}
int main(int argc, char** argv) {
    p1();
    std::cout << "Dame una tecla para salir del programa:P";
    cin.get();
    return 0;
}

