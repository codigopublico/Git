#include "garaje.hpp"
using namespace g;
gara::gara(){
    std::cout << "Constructor de la classe";
    aux[2];
    aux[0] = 20;
    aux[1] = 20;
    std::cout << "La dimencion por defecto es: ";
    for(int i = 0; i < 2; i++){
        std::cout << aux[i] <<"  ";
    }
    std::cout << "\n";
    n[aux[0]][aux[1]];
 for(int i = 0; i < aux[0]; i++){
        for(int ii = 0; ii < aux[1]; ii++){
            n[i][ii] = 0;
            
        }
    }

}
void gara::grafica(){
    std::cout << "Iniciando la grafica \n el x es vacio \ni el * es lleno\n ";
    for(int i = 0; i < aux[0]; i++){
        
        std::cout << i;
        if(i < 10){
            std::cout << "  ";
        }else{
            std::cout << " ";
        }
        
    }
    std::cout << "\n";
    for(int i = 0; i < aux[0]; i++){
        for(int ii = 0; ii < aux[1]; ii++){
            if(n[i][ii] == 0){
                std::cout << " x ";
            }else{
            std::cout << " * ";
            }
        }
        std::cout << i <<"\n";
    }
}
void gara::get(int col, int fil){
    aux[0] = col;
    aux[1] = fil;
    
    
}
void gara::cambio(int p[2], int r){
     if( r == n[p[0]][p[1]]){
            std::cout << "No se puede realizar el cambio de  \n" << p[0] << "  " << p[1] << "  " << r << "\n";
        }else{
        if(r > 0){
            
            std::cout << "entro el coche de la possicion: " << p[0] << "  " << p[1] << "\n";
        }else{
            std::cout << "Salio el coche de la possicion " << p[0] << "  " << p[1] << "\n";
        }
        }
        n[p[0]][p[1]] = r;

}
void gara::entrar(){
    *vehic[id].incolor = color;
}
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
    int *r = new int[2];//cuando tenga tiempo lo arreglos
    int p[2] = {freq, vol};
    r = p;
    return r;
}