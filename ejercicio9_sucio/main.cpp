/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 23 de octubre de 2017, 19:48
 */

#include <cstdlib>
#include "garaje.hpp"
using namespace std;

/*
 * Este es un ejemplo de usar librerias bien echas
 * nada mas falta el display
 */
using namespace g;
void p3(){
    gara autom;
    autom.grafica();
    autom.get(10, 10);
    autom.grafica();
    vehiculo seat;
    seat.arrancar();
    std::cout << "La velocidad es de " << seat.getvel() << "\n";
    seat.radio_enceder();
    seat.radio_sintonizar(20);
    /*int *e = seat.radio_display();
    std::cout << "El display de la radio muestra " << e[0];
    //e++;
    std::cout << "   " << e[1];*/
}
void final(){
    liga *base = new liga;
    std::cout << "\nCreacion de una liga \n" << "Para empezar pon los nombres de los equipos \n";
    setnombres(base);
    //base->getmonstar();
    for(int i = 0; i < 2; i++){
        base->crearliga();
        base->jugar();
    }
    delete base;
}
int main(int argc, char** argv) {
    p3();//gestion del garaje i del vehiculo
    final();
    return 0;
}

