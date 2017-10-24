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
class vehiculo{
public:
    string color;
    int caballos;
    string marca;
    string modelo;

    vehiculo();
    vehiculo(string incolor, int incaballos, string inmarca, string inmodelo);
    
};
}
#endif	/* GARAJE_HPP */

