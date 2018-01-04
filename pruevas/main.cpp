/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 10 de diciembre de 2017, 23:42
 */

#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

/*
 * Este es para las pruevas de codigo.
 */
namespace Np1{
class Vehiculo
{
protected:
string color;
int peso;
public:
Vehiculo(string color, int peso);
virtual void getInfo();
};
Vehiculo::Vehiculo(string color, int peso)
{
this->color = color;
this->peso = peso;
}
void Vehiculo::getInfo()
{
cout << "Vehiculo: color=" << color << " , peso=" << peso << endl;
}
//************************************************************************
class Coche : public Vehiculo
{
protected:
int numPuertas;
public:
Coche(string color, int peso, int numPuertas);
void getInfo();
void abrirMaletero();
};
Coche::Coche(string color, int peso, int numPuertas) : Vehiculo(color, peso)
{
this->numPuertas = numPuertas;
}
void Coche::getInfo(){
cout << "Coche: color=" << color << " , peso=" << peso << " , numPuertas=" << numPuertas << endl;
}
void Coche::abrirMaletero()
{
cout << "Coche: abriendo maletero";
}

}
//************************************************************************
void p1(){
Np1::Vehiculo* v2 = new Np1::Vehiculo("Verde", 1000);
Np1::Vehiculo* c2 = new Np1::Coche("Amarillo", 1100, 6);
v2->getInfo();
c2->getInfo();
Np1::Coche c("Ama", 110, 6);
c.getInfo();

}
namespace Np2{
 class Vehiculo
{
protected:
string color;
int peso;
public:
Vehiculo(string color, int peso);
virtual void getInfo();
virtual void abrirMaletero();
virtual void anadirSidecar();
};
void Vehiculo::anadirSidecar(){
    
}
void Vehiculo::abrirMaletero(){
    
}
Vehiculo::Vehiculo(string color, int peso)
{
this->color = color;
this->peso = peso;
}
void Vehiculo::getInfo()
{
cout << "Vehiculo: color=" << color << " , peso=" << peso << endl;
}
//************************************************************************
class Coche : public Vehiculo
{
protected:
int numPuertas;
public:
Coche(string color, int peso, int numPuertas);
void getInfo();
void abrirMaletero();
};
Coche::Coche(string color, int peso, int numPuertas) : Vehiculo(color, peso)
{
this->numPuertas = numPuertas;
}
void Coche::getInfo()
{
cout << "Coche: color=" << color << " , peso=" << peso << " , numPuertas="
<< numPuertas << endl;
}
void Coche::abrirMaletero()
{
cout << "Coche: abriendo maletero" << endl;
}
//************************************************************************
class Moto : public Vehiculo
{
protected:
bool esTrial;
public:
Moto(string color, int peso, bool esTrial);
void getInfo();
void anadirSidecar();
};
Moto::Moto(string color, int peso, bool esTrial) : Vehiculo(color, peso)
{
this->esTrial = esTrial;
}
void Moto::getInfo()
{
cout << "Moto: color=" << color << " , peso=" << peso << " , esTrial=" <<
esTrial << endl;
}
void Moto::anadirSidecar(){
    cout << "Moto: Abriendo Sidecar" << endl;
}
}
void p2(){
Np2::Vehiculo* v1 = new Np2::Coche("Amarillo", 1100, 6);
Np2::Vehiculo* v2 = new Np2::Moto("Amarillo", 1100, true);
v1->abrirMaletero();
v2->anadirSidecar();
}
namespace Np3{
     class Vehiculo
{
protected:
string color;
int peso;
public:
Vehiculo(string color, int peso);
virtual void getInfo();
};

Vehiculo::Vehiculo(string color, int peso)
{
this->color = color;
this->peso = peso;
}
void Vehiculo::getInfo()
{
cout << "Vehiculo: color=" << color << " , peso=" << peso << endl;
}
//************************************************************************
class Coche : public Vehiculo
{
protected:
int numPuertas;
public:
Coche(string color, int peso, int numPuertas);
void getInfo();
void abrirMaletero();
};
Coche::Coche(string color, int peso, int numPuertas) : Vehiculo(color, peso)
{
this->numPuertas = numPuertas;
}
void Coche::getInfo()
{
cout << "Coche: color=" << color << " , peso=" << peso << " , numPuertas="
<< numPuertas << endl;
}
void Coche::abrirMaletero()
{
cout << "Coche: abriendo maletero" << endl;
}
//************************************************************************
class Moto : public Vehiculo
{
protected:
bool esTrial;
public:
Moto(string color, int peso, bool esTrial);
void getInfo();
void anadirSidecar();
};
Moto::Moto(string color, int peso, bool esTrial) : Vehiculo(color, peso)
{
this->esTrial = esTrial;
}
void Moto::getInfo()
{
cout << "Moto: color=" << color << " , peso=" << peso << " , esTrial=" <<
esTrial << endl;
}
void Moto::anadirSidecar(){
    cout << "Moto: Abriendo Sidecar" << endl;
}
void abrirMal(Vehiculo *p){
    if(Moto *pMoto = dynamic_cast<Moto *>(p)){
        pMoto->anadirSidecar();
    }
    if(Coche *pCoche = dynamic_cast<Coche *>(p)){
        pCoche->abrirMaletero();
    }
}
}
class avion{
protected:
    int a;
    
};
class avioneta : public avion{
    
};
void p3(){
Np3::Vehiculo* v1 = new Np3::Coche("Amarillo", 1100, 6);
Np3::Vehiculo* v2 = new Np3::Moto("Amarillo", 1100, true);
cout << "Coche \n";
Np3::abrirMal(v1);
cout << "Moto \n";
Np3::abrirMal(v2);
}
void p4(){
    
}
int main(int argc, char** argv) {
    //p1();
    //p2();
    //p3();
    p4();
    return 0;
}

