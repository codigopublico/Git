/* 
 * File:   main.cpp
 * Author: iper
 * falta revisar las preuvas de erres aunque esta bien echo.
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
int imax = 900;
int null = -1;
int*  catego(int aux[2], int n[900][900]){
    int *r = new int[4]; // Al finalizar el programa se ya de poner el codigo(memoria) bien.....
    int suma[3] = {0,0,0};
    for(int i = 0; i < aux[0]; i++){
        for(int ii = 0; ii < aux[1]; ii++){
            if(n[i][ii] == 1 && i < 4){
                suma[0]++;
            }
            if(n[i][ii] == 1 && i < 25 && i > 5){
                suma[1]++;
            }
            if(n[i][ii] == 1 && i < 30 && i > 26){
                suma[3]++;
            }
        }
    }
    for(int i = 0; i < 3; i++){
        *r = suma[i];
        *r++;
    }
    for(int i = 3; i > 0; i--){
        *r--;
    }
    return r;
}
class espectador{
public:
    struct persona{
        string nom;
        string apellido;
        int edad;
        int asiento[2];
    }pers[900];
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
    int mayor(){
        int max = 0;
        for(int i = 0; i < ref; i++){
            if(max < pers[i].edad){
                max = pers[i].edad;
            }
        }
        return max;
        
    }
    
};

class sala : public espectador{
public:
    //int smax = 220;
    int n[900][900];//este es el array que define si esta lleno vacio el array.
    int aux[2];//este array es el que define el cuadrado de los assientos
    int per[900][900];//este es la referncia de la persona.
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
        for(int i = 0; i < aux[0]; i++){
            for(int ii = 0; ii < aux[1]; ii++){
                n[i][ii] = 0;
            }
        }
        for(int i = 0; i < ref; i++){
                n[pers[i].asiento[0]][pers[i].asiento[1]] = 1;
            }
        grafica(aux, n);
    }
    void reguistrar(int a[2], int id){
        n[a[0]][a[1]] = 1;
        for(int i = 0; i < 2; i++){
        pers[id].asiento[i] = a[i];
        }
    }
    void liberar(int a[2]){
        for(int i = 0; i < aux[0]; i++){
                if(pers[i].asiento[0] == a[0] && pers[i].asiento[0] == a[1]){
                    pers[i].asiento[0] = null;
                    pers[i].asiento[1] = null;
                }
        }
    
    }
    int* categoria(){
        int *r = catego(aux, n);
        return r;
    }
    int ocupacion(){
                double r = 0;
        for(int i = 0; i < aux[0] * aux[1]; i++){
                if(pers[i].asiento[0] > 0){
                    r++;
            }
        }
                r = (r / (30 * 30)) * 100;
        return r;
    }
};
void p1(){
    int aux[2] = {30, 30};
    string nom;
    sala rock(aux);
    rock.mostrar();
    int a[2];
    int b = 0; 
    /*for(int i = 0; i  < 29; i++){
        for(int ii = 0; ii < 30; ii++){
    rock.entrar("laura", "laura", 30);
    a[0] = ii;
    a[1] = i;
    b++;
    rock.reguistrar(a, b);
    rock.mostrar();
        }}*///este codigo es para hacer en el tren.
    //Menu de gestion de teatro
    //que mierdas le paso!!!!!!!
    int n;
    std::cin >> nom;
    while(nom != "FIN"){
        limpiar();
        rock.mostrar();
        std::cout << "Este es el menu de la gestion  de la sala\n reservar assiento (r), reguistrar cliente(c) \n, librar asiento(l)\n, cargar el systema de estadisticas(e)\n";
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
        if(nom == "l"){
            std::cout << "Dime el asiento a liberar\n";
        std::cout << "\n fila: ";
            std::cin >> a[0];
            std::cout << "Columna\n";
            std::cin >> a[1];
            rock.liberar(a);
        }
        if(nom == "e"){
            std::cout << "Dime el tipo de estadistica que quieres hacer\n la persona con mas edad(m)\n categorias(c)\n total de ocupacion";
            std::cin >> nom;
            if(nom == "m"){
                std::cout << "El cliente de mayor de edad es:  " << rock.mayor() << "\n";
            }
            if(nom == "c"){
                int *r2 = rock.categoria();
                std::cout << "la categoria 0 tiene:  " << *r2 << "\n";
                *r2++;
                for(int i = 1; i < 3; i++){
                    std::cout << "la categoria " << i << "tiene " << *r2 << "\n";
                    *r2++;
                }
            }
            if(nom == "o"){
            std::cout << "La ocupacion es de " << rock.ocupacion() << "%  \n";
        }
         std::cout << "Pulsa una tecla para continuar\n";
                std::cin >> nom;
        }
       
    }
}
int main(int argc, char** argv) {
    p1();
    return 0;
}

