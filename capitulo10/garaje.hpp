/* 
 * File:   garaje.hpp
 * Author: iper
 *Lo tengo que hacer es reguistrar vehiculos pero por punteros esto se tiene que preguntar como se hace i si lo puedo hacer sin punteros.
 * Created on 24 de octubre de 2017, 17:54
 */

#ifndef GARAJE_HPP
#define	GARAJE_HPP

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
namespace g{
    struct vehi{
    public:
        string incolor;
        float incaballos;
        string inmarca;
        string imodelo;
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
    void cambio(int[2], int);
    void entrar(vehiculo);
        
};


}
#endif	/* GARAJE_HPP */

