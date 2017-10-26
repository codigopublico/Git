#include "classes.hpp"
using namespace g;
//solo es pasar el codigo aqui i ya esta no se como se envio pero ahora lo modificare.
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
int* radio::radio_display(){
    int *r = new int[2];//cuando tenga tiempo lo arreglos el siguite paso es hacer un arreglo con delete
    r[0] = freq;
    r[1] = vol;
    return r;
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
//copia a lo bruto
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
//fin
gara::gara(){
    regui = &c[0];
    aux[0] = 20;
    aux[1] = 20;
    id = 0;
    std::cout << "La dimencion por defecto es: ";
    for(int i = 0; i < 2; i++){
        std::cout << aux[i] <<"  ";
    }
    std::cout << "\n";
    n[aux[0]][aux[1]];
 for(int i = 0; i < aux[0]; i++){
        for(int ii = 0; ii < aux[1]; ii++){
            std::cout << "Llevas las veces ... "  << "...." << i  << "..." << ii<< "\n";
            n[i][ii] = 0;
            regui->incaballos = 0;
            regui->imodelo = "0";
            regui->incolor = "0";
            regui->inmarca = "0";
            regui->lugar[0] = -1;//este es el lugar para los coches fantasma
            regui->lugar[1] = -1;
            regui++;
        }
    }
    //esto es solo una prueva.... es para poner el contador hasta 0.
    for(int i = 0; i < aux[0] * aux[1]; i++){
        regui--;
    }
    std::cout << "Fin del bucle";
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
void gara::entrar(vehiculo en, int inlugar[2]){
    regui->incolor = en.color;
    regui->imodelo = en.modelo;
    regui->incaballos = en.caballos;
    regui->inmarca = en.marca;
    regui->lugar[0] = inlugar[0];
    regui->lugar[1] = inlugar[1];
    if( 1 == n[inlugar[0]][inlugar[1]]){
            std::cout << "No se puede realizar el cambio de  \n" << n[0] << "  " << n[1] << "  " << 1 << "\n";
        }else{
            std::cout << "entro el coche de la possicion: " << n[0] << "  " << n[1] << "\n";
        }
        n[inlugar[0]][inlugar[1]] = 1;
    regui++;
    
    id++;
}
void gara::salir(int inl[2]){
    int i = 0;
    for(; i < id + 2; i++){
        if(regui->lugar[0] == inl[0] && regui->lugar[1] == inl[1]){
            break;
        }
        regui++;
    }
    regui->incaballos = 0;
    regui->imodelo = "0";
    regui->incolor = "0";
    regui->inmarca = "0";
    regui->lugar[0] = -1;//este es el lugar para los coches fantasma
    regui->lugar[1] = -1;
    //nada mas queda ordenar i revisar i enviar mails.
    for(int ii = 0; ii < i; ii++){
        regui--;
    }
    int aux;
    string aux2;
    int e = 0;//esto es lo que tendria que ser....
    while(e >= id){
        e = 0;
        for(int ii = 0; ii < id + 2; ii++){
            if(regui->lugar[0] > 0){
                e++;
            }
        }
    }
}