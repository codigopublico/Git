#include "taller.hpp"
void taller::hola(){
    std::cout << "\nEstas usando la libreria de taller\n";
}
using namespace taller;
vehiculo::vehiculo(){
    std::cout << "Llamando al contructor de la classe(valores por defecto)\n";
    string color = "0";
    int caballos = 0;
    string marca = "0";
    string modelo = "0";
    vel = 0;
}
vehiculo::vehiculo(string incolor, int incaballos, string inmarca, string inmodelo){
        color = incolor;
        caballos = incaballos;
        marca = inmarca;
        modelo = inmodelo;
        vel = 0;
}
void vehiculo::setcolor(string incolor){
        color = incolor;
    }
void vehiculo::setcaballos(int incaballos){
        caballos = incaballos;
    }
void vehiculo::setmarca(string inmarca){
        marca = inmarca;
    }
void vehiculo::setmodelo(string inmodelo){
        modelo = inmodelo;
    }
string vehiculo::getcolor(){
        return color;
    }
int vehiculo::getcaballos(){
        return caballos;
    }
string vehiculo::getmarca(){
        return marca;
    }
string vehiculo::getmodelo(){
        return modelo;
    }
void vehiculo::arrancar(){
    vel = vel + 1;
}
void vehiculo::parar(){
    vel = 0;
}
int vehiculo::getvel(){
    return vel;
}
radio::radio(){
    on = false;
    freq = 0;
    vol = 0;
    
}
void radio::radio_enceder(){
    on = true;
}
void radio::radio_apagar(){
    on = false;
}
void radio::radio_sintonizar(int s){
    if(on){
        freq = s;
    }
}
void radio::radio_volumen(int v){
    if(on){
        vol = v;
    }
}
int* radio::radio_display(){
    int *r;//cuando tenga tiempo lo arreglos
    int *p = new int[2];
    p[0] = freq;
    p[1] = vol;
    r = &p[0];
    return r;
}