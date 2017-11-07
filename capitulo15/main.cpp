/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 21 de octubre de 2017, 13:26
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include "mis_funciones.hpp"
using namespace std;

/*
 * 
 */
void limpiar(){
    for(int i = 0; i < 1000; i++){
        std::cout << "\n";
    }
}
class vehiculo{
public:
    struct vehicul{
        string nombre;
        int dinero;
        int nreparacion;
    };
    vehicul d;
    vehiculo(){
        std::cout << "Construiendo el vehiculo";
    }
};
class taller : public vehiculo{
public:
    int id;
    vehicul tall[200]; //tall es el string de vehculos. 
    taller(){
        id = 200;
        for(int i = 0; i < id; i++){
        tall[i].dinero = 0;
        tall[i].nreparacion = 0;
        tall[i].nombre = "0";
        }
        id = 0;
    }
    void reparar(int d){
        tall[d].dinero = tall[id].dinero + d;
        tall[d].nreparacion--;
        if(tall[d].nreparacion < 0){
            tall[d].nreparacion = 0;
        }
    }
    void entrar(const vehiculo &en){
        tall[id].dinero = en.d.dinero;
        tall[id].nombre = en.d.nombre;
        tall[id].nreparacion = en.d.nreparacion;
        id++;
}
    void mostrar(){
        std::cout << "\n";
        for(int i = 0; i < id; i++){
            std::cout << "Nombre:          " << tall[i].nombre << "\n";
            std::cout << "Pagar:           " << tall[i].dinero << "\n";
            std::cout << "N. reparaciones  " << tall[i].nreparacion << "\n";
            for(int ii = 0; ii < 3; ii++){
                std::cout << "\n";
            }
        }
    }
    void eliminar(string n){
        for(int i = 0; i < id; i++){
            if(tall[i].nombre == n){
                tall[i].nombre = "0";
                tall[i].dinero = 0;
                tall[i].nreparacion = 0;
            }
        }
        int q = 0;
        while(q <= id){
            q = 0;
            for(int i = 0; i < id; i++){
                if(tall[i].nombre != "0"){
                    q++;
                }else{
                    q--;
                    //inter(tall[i].nombre, tall[i + 1].nombre);
                }
            }
        }
    }
    void pagar(int n){
       
    }
};
void p3(){
    string in;
    string aux;
    vehiculo vcoche;
    taller autom;
    do{
        limpiar();
        std::cout << "\n Para crear un choche(c) \n";
        std::cout << "Para mostrar los coches(m) \n";
        std::cout << "Para eliminar un coches(e) \n";
        std::cout << "Para salir Fin\n";
        std::cin >> in;
        if(in == "c"){
            std::cout << "Dime el dinero que debe\n";
            std::cin >> vcoche.d.dinero;
            std::cout << "Dime el nombre del vehiculo\n";
            std::cin >> in;
            vcoche.d.nombre = in;
            std::cout << "Dime el numero de reparaciones que lleva en el taller\n";
            std::cin >> vcoche.d.nreparacion;
            autom.entrar(vcoche);
        }
        if(in == "m"){
            autom.mostrar();
        }
        if(in == "e"){
            autom.mostrar();
            std::cout << "Dime el nombre a eliminar\n";
            std::cin >> in;
            autom.eliminar(in);
        }
        if(in == "FIN"){
            std::cout << "Fin del programa\n";
        }
        else{
            std::cout << "Error!!!!";
        }
        if(in != "FIN"){
        std::cout << "dame un dato para continuar\n";
        std::cin >> aux;
        }
    }while(in != "FIN");
}
class cuenta{//Classe cuentacorriente
private:
    int d;
public:
    cuenta();
    cuenta(int n){
        d = n;
    };
    operator unsigned int(){
        return d;
    }
    
    cuenta operator +(int n){
        cuenta res(d + n);
        return res;
    }
    cuenta operator-(int n){
        cuenta res(d - n);
        return res;
    }
   
    cuenta operator+(const cuenta &p1){//este para hacer la sobre carga de operadores de classes
        cuenta res(p1.d + d);
        return res;
    }
    cuenta operator-(const cuenta &p1){//este para hacer la sobre carga de operadores de classes
        cuenta res(p1.d - d);
        return res;
    }
    cuenta operator*(int n){
        cuenta res(d * n);
        return res;
    }
    cuenta operator=(int n){
        cuenta res(d = n);
        return res;
    }
    int getd(){
        return d;
    }
};
cuenta::cuenta(){
    d = 0;
}
void p1(){
    cuenta joan;
    joan = joan + 10;
    cuenta alex;
    alex = alex + 200;
    alex = alex - 0;
    std::cout << "alex  " << alex.getd() << "\n ";
    cuenta banco = alex + joan;
    banco = banco * 2;
    std::cout << "d  " << banco.getd() << "\n  ";
    cuenta ale(10);
    ale = ale = 1000;
    //int x = ale;
    //std::cout << x;
    int x = ale;
    std::cout << x << "\n";
    
}
class Rectangulo 
{ 
public: 
double ancho; 
double alto; 
Rectangulo(double ina, double inb){
    alto = ina;
    ancho = inb;
}
Rectangulo(){
    ancho = 0;
    alto = 0;
}
Rectangulo operator+(const Rectangulo &b) 
{ 
    Rectangulo res(b.alto + alto, b.ancho + ancho);
    return res;
} 
double getArea() 
{ 
return ancho * alto; 
} 
}; 
void p2(){
    
Rectangulo c1; 
Rectangulo c2; 
Rectangulo c3; 
c1.ancho = 2,0; 
c1.alto = 20,0; 


c2.ancho = 2,0; 
c2.alto = 4,0; 
c3= c1 + c2; 
cout << "caja 1: " << c1.getArea() <<endl; 
cout << "caja 2: " << c2.getArea() <<endl; 
cout << "caja 3: " << c3.getArea() <<endl; 
cout << "caja 3: " << c3.ancho <<endl;

}

int main(int argc, char** argv) {
    //p1();
    //p2();
    p3();
    std::cout << "\n";
    return 0;
}