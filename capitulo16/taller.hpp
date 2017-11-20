/* 
 * File:   taller.hpp
 * Author: iper
 *
 * Created on 20 de noviembre de 2017, 17:02
 */

#ifndef TALLER_HPP
#define	TALLER_HPP
#include <iostream>
using namespace std;
namespace taller{
void hola();
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
}

#endif	/* TALLER_HPP */

