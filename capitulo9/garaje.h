/* 
 * File:   garaje.h
 * Author: iper
 *
 * Created on 9 de octubre de 2017, 19:05
 */
#ifndef GARAJE_H
#define	GARAJE_H
#include <string>


class garaje{
    public:
    int aux[2];
    int n[200][200];
    garaje(int fil, int col){
    aux[2];
    aux[0] = fil;
    aux[1] = col;
    n[aux[0]][aux[1]];
 for(int i = 0; i < aux[0]; i++){
        for(int ii = 0; ii < aux[1]; ii++){
            n[i][ii] = rand() % 5;
            if(n[i][ii] > 0){
                n[i][ii] == 1;
            }
        }
    }
    };
    void grafica(){
    }
    void cambio(int p[], int r){ }
    
};
class vehiculo{ 
    public:
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
    };
};



#endif

#endif	/* GARAJE_H */

