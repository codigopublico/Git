/* 
 * File:   classes.hpp
 * Author: iper
 *
 * Created on 26 de octubre de 2017, 21:50
 */

#ifndef CLASSES_HPP
#define	CLASSES_HPP
#include <iostream>
#include <string>
#include <stdio.h>
#include <cstdlib>


using namespace std;
namespace g{
    struct vehi{
    public:
        string incolor;
        float incaballos;
        string inmarca;
        string imodelo;
        int lugar[2]; //este es el lugar donde se encuentra el coche en la tabla
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
    vehiculo(string, int, string, string);
    
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
class gara : public vehiculo{
public:
    struct vehi c[900];//Este es lo que hace falta.
    struct vehi *regui;
    int aux[2];
    int fil;
    int col;
    int n[900][900];
    int id;
    gara();
    void grafica();
    void get(int, int);
    //void cambio(int[2], int);//se cambia por salir
    void entrar(vehiculo, int[2]);
    void salir(int[2]);
};


}



#endif	/* CLASSES_HPP */

