/* 
 * File:   garaje.h
 * Author: iper
 *
 * Created on 10 de octubre de 2017, 17:54
 */

#ifndef GARAJE_H__
#define	GARAJE_H__
namespace pasta{
class garaje{
    public:
    int aux[2];
    int n[200][200];
    garaje();
    garaje(int, int);
    void graf();
    void cambio(int p[], int r);
};
}
class vehiculo{ 
    /*public:
    string color;
    int caballos;
    string marca;
    string modelo;
    vehiculo(){};
    vehiculo(string incolor, int incaballos, string inmarca, string inmodelo){
        color = incolor;
        caballos = incaballos;
        marca = inmarca;
        modelo = inmodelo;
    };*/
};
#endif	/* GARAJE_H */

