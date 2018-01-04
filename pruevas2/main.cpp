/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 30 de diciembre de 2017, 21:59
 */

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

/*
 * 
 */
class Vehiculo
{
public:
string color;
int peso;
public:
Vehiculo(string Icolor , int Ipeso);
virtual void getInfo();
virtual ~Vehiculo();
virtual Vehiculo operator=(const Vehiculo &Iv); 
};
Vehiculo::~Vehiculo(){
    this->color = "0";
    this->peso = 0;
}
Vehiculo::Vehiculo(string Icolor, int Ipeso)
{
this->color = Icolor;
this->peso = Ipeso;
}
void Vehiculo::getInfo()
{
cout << "Vehiculo: color=" << color << " , peso=" << peso << endl;
}
Vehiculo Vehiculo::operator =(const Vehiculo &Iv){
    this->color = Iv.color;
    this->peso = Iv.peso;
}
class Coche : public Vehiculo
{
protected:
int numPuertas;
public:
Coche(string Icolor, int Ipeso, int numPuertas);
void getInfo();
void abrirMaletero();
Coche operator=(const Coche &a);
virtual ~Coche();
};
Coche::Coche(string Icolor, int Ipeso, int numPuertas):Vehiculo(Icolor, Ipeso)
{
this->numPuertas = numPuertas;
}
void Coche::getInfo() {
cout << "Coche: color=" << color << " , peso=" << peso << " , numPuertas=" << numPuertas << endl;
}
void Coche::abrirMaletero()
{
cout << "Coche: abriendo maletero";
}
Coche Coche::operator =(const Coche& a){
    this->numPuertas = a.numPuertas;
}
Coche::~Coche(){
    this->numPuertas = 0;
}
void p1(){
Vehiculo* v2 = new Vehiculo("Verde", 1000);
Vehiculo* c2 = new Coche("Amarillo", 1100, 6);
v2->getInfo();
c2->getInfo();
v2 = c2;
v2->getInfo();
}
int main(int argc, char** argv) {
    p1();
    return 0;
}

