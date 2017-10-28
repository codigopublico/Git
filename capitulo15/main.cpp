/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 21 de octubre de 2017, 13:26
 */

#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

/*
 * 
 */
class vehiculo{
public:
    int r; 
    struct vehicul{
        string nombre;
        int dinero;
        int nreparacion;
    }vehi[500];
    vehiculo(){
        for(int i = 500; i > 0; i++){
            vehi[i].dinero = 0;
            vehi[i].nombre = ""; //tengo que hacer lo el null
            vehi[i].nreparacion = 0;
        }
        r = 0;
    }
};
class taller : public vehiculo{
public:
    int id;
    void reparar(int d){
        vehi[id].dinero = vehi[id].dinero + d;
        vehi[id].nreparacion++;
    }
};
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
    p1();
    p2();
    std::cout << "\n";
    return 0;
}