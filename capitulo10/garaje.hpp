/* 
 * File:   garaje.hpp
 * Author: iper
 *Lo tengo que hacer es reguistrar vehiculos pero por punteros.
 * Created on 24 de octubre de 2017, 17:54
 */

#ifndef GARAJE_HPP
#define	GARAJE_HPP

#include <iostream>
#include <string>
using namespace std;
namespace g{
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
class gara : public vehiculo{
public:
    struct vehi{
        string incolor;
        float incaballos;
        string inmarca;
        string imodelo;
    }vehic[900]; 
    struct vehi *regui;//Este es el reguistro de los coches......
    regui = &vehic;
    int aux[2];
    int fil;
    int col;
    int n[900][900];
    int id;
    gara();
    void grafica();
    void get(int, int);
    void cambio(int[2], int);
    void entrar(vehiculo);
        
};


}
#endif	/* GARAJE_HPP */

