/* 
 * File:   garaje.hpp
 * Author: iper
 *
 * Created on 24 de octubre de 2017, 13:26
 * Este es un ejemplo de como se ha de usar las fuentes bien echas.
 */

#ifndef GARAJE_HPP
#define	GARAJE_HPP
#include <iostream>
#include <string>
#include <stdlib.h> // esta es la liberria de rand()

using namespace std;
namespace g{
class gara{
public:
    int aux[2];
    int fil;
    int col;
    int n[200][200];
    gara();
    void grafica();
    void get(int, int);
    void cambio(int[2], int);
        
};
class radio{
public:
    bool on;
    int freq;
    int vol;
    radio();
    void radio_enceder();
    void radio_apagar();
    void radio_volumen(int);
    void radio_sintonizar(int);
    int* radio_display();
};
class vehiculo : public radio{
public:
    string color;
    int caballos;
    string marca;
    string modelo;
    int vel;

    vehiculo();
    vehiculo(string incolor, int incaballos, string inmarca, string inmodelo);
    
void setcolor(string incolor);
void setcaballos(int incaballos);
void setmarca(string inmarca);
void setmodelo(string inmodelo);
string getcolor();
int getcaballos();
string getmarca();
string getmodelo();
void arrancar();
void parar();
int getvel();

    
};
/*
 * Este es para hacer la limpieza de ejercicio9 De modo que se hara de forma progresiva.
 */
//variables publicas.
char aux2[5] = "0FIN";
char aux3[4] = "FIN";
class equipo{
    //eta classe es la del equipo con todos sus metodos i funciones que se heradara de todas las demas.
    public:
    char nombre[200][200]; //Este es el arry de arrays que verifica que todo funcione bien.
    int aux;//Esta es la que cuenta el numero de equipos introducidos.
    int ref[200];//Esta es la referencias de los nombres que existen.
    equipo(){
        //*pn = &nombre;
        aux = 0;
    }
    void setnombrar(char nom[200]){
        int i = 0;
        do{
            nombre[aux][i] = nom[i];
            i++;
        }while(nom[i - 1] != 0);
        ref[aux] = aux;
        aux++;
    }
    void getmonstar(){
        //tiene que retornar lo de la char con lo de los puneteros una vez echo se tiene que hacer un metodo para destruir.
        int ii = 0;
        for(int i = 0; i < aux; i++){
            std::cout << "Los nombres de los equipos son:    ";
            ii = 0;
            do{
                std::cout << nombre[ref[i]][ii];
                //aqui tendria que ir nombre de esta forma: nombre[ref[i]][ii]
                ii++;
            }while(nombre[ref[i]][ii] != 0);
            std::cout << "  La referencia es  " << i << "\n";
        }
    }
};
int setnombres(equipo *constante){
    //eta es la funcion que se encarga de escanear  todo lo del teclado.
    //tengo que hacer que se haga todo por teclado.
    int e = 0;
    std::cout << "\nPara poner un equipo terminar con un 0, Para terminar de poner eqipos usar la palabra FIN0\n Introducir  4 equipos\n";
    while(e < 2){//El bucle ya esta echo
     int i = 0; //Esta es la que cuenta los caracteres,
     e = 0; //Esta es la variable que verifica si el final del string con un 0.
     char im[200]; //Esta es la que se pone es la que  caputra el teclado.
        do{
            std::cin >> im[i];
            i++;
            for(int ii = 0; ii < i; ii++){
                if(im[ii] == aux2[0]){  
                    e++;
                }
            }
        }while(e == 0);
        e = 0;
        char cambio[i - 2];
        for(int g = 0; g < i -1; g++){
            cambio[g] = im[g];
        }
        e = 0;
        for(int g = 0; g < 4; g++){
            if(cambio[g] == aux3[g]){
                e++;
            }
        
        }
        if(e > 2){
            std::cout << "FIN" << "\n";
            e = 3;
        }else{
        constante->setnombrar(cambio);//tiene que haber una funcion recrusiva.
        }
        std::cout << "\n Monstrado los nombres introducidos \n";
        constante->getmonstar();
    }
    
    }
class partidos : public equipo  {
public:
    // Esta se carga de jugar los partidos.
    int l[2][10]; //este es el que se encarga de enfernatar los 0 ccon los 1. 
    partidos() : equipo(){
       
    }
    void jugar(){
        int r[2];
        r[0] = 0;
        r[1] = 0;
        //Aqui se tiene que hacer poner en la ref el que gane i quitar el que pierde.
        std::cout << "Los perdores son :    \n";
        for(int i = 0; i < aux/2; i++){
        if(rand()%2 == 0){
            std::cout << l[0][i] << "\n";
            l[0][i] = 0;
        }else{
            std::cout << l[1][i] << "\n";
            l[1][i] = 0;
        }
            }
        r[0] = 1;
        for(int i = 0; i < aux/2; i++){
        for(int e = 0; e < 2; e++ ){
            if(l[e][i] != 0){
                ref[r[0]] = l[e][i];
                r[0]++;
            }
            }
        }
        std::cout << "\n Los ganadores son:        \n";
        aux = r[0];
        for(int i = 0; i < r[0]; i++){
            int ii = 0;
            while(nombre[ref[i]][ii] != 0){
                std::cout << nombre[ref[i]][ii];
                ii++;
            }
            std::cout << "\n";
        }
    }
};
class liga : public partidos   {
public:
    //este se encarga de organizar de esquematizar los partidos en base a una liga
    liga(){
        aux = 0;
    }
    void crearliga(){
 //Aqui tienen que ir los id's de los que se tienen que enfrentar. Se tiene que poner en la classe superior.
        int ii = 0;
        int q2[2];
        q2[0] = 0;
        q2[1] = 0;
        for(int i = 0; i < aux; i++){
            if(i%2 == 0){
                l[0][q2[0]] = ref[i];
                q2[0]++;
            }else{
                l[1][q2[1]] = ref[i];
                q2[1]++;
            }
            ii++;
        }
        std::cout << ii <<"\n";
        for(int i = 0; i < ii/2; i++){
            for(int e = 0; e < 2; e++){
                //El problema esta aqui ya que hay una violacion de segmento si borro esto funciona pero con muchos errores i aun hace falta hacer ir las funciones de partidos i englovarlas en una 
                if(e == 0){
                    std::cout << "     El equipo    " ;
                }else{
                    std::cout << "     el equipo    ";
                }
                
                q2[0] = 0;
            while(nombre[l[e][i]][q2[0]] != 0) {
                std::cout << nombre[l[e][i]][q2[0]];//esta es laexpresion que esta mal
                q2[0]++;
            }
            if( e < 1 ){
            std::cout << "   se enfrenta a   ";
            }
            }
            std::cout  <<"\n";
            }
        }
    
};
}
#endif	/* GARAJE_HPP */

