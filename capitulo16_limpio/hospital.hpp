/* 
 * File:   hospital.hpp
 * Author: iper
 *
 * Created on 22 de noviembre de 2017, 17:44
 */

#ifndef HOSPITAL_HPP
#define	HOSPITAL_HPP
#include <iostream>
#include <string>
const int maxesp = 10;
using namespace std;
namespace hospi{
class persona{
public:  
    persona();
    persona(string, int); 
    virtual void setdatos(int a, int b, int c){}
public:
    struct pers{
        string nombre;
        int telefono;
    }per;
};
    struct datos_t{
        int n;
        int Esp;//Es la variable que dice a que especialidad de la lista perteneze;
        int h[2]; //esta es la variable del horario que dice donde esta en el primer int se pone  a donde va.
    };
class enfermero : public persona{
public:
    datos_t enf;
    string nomesp;//este es la etiqueta del enfermoro.
    string esp[maxesp]; 
public:
    enfermero();
    enfermero(int, int, int);
    void setdatos(int, int, int);
}; 
class limpieza : public persona{
protected: 
    datos_t limp;
    string nomesp;//esta es la etiqueta de limpieza;
    string esp[maxesp];
    void setdatos(int, int, int);
public: 
    limpieza();
    limpieza(int, int, int);
};
const int medi = 2;
const string emedi[medi] = {"General", "Ginecologo"};
class medicos : public persona{
protected:
    datos_t medi;
    string nomesp;
    string esp[maxesp];
public:
    medicos();
    medicos(int, int, int);
    void setdatos(int, int, int);
};
class hosipta{
public:
    int p;//estas son las personas totales del hospital
    persona *Ppers;
    int Tra; //esta es para contar los trabajadores actuales echos.
    hospita(int);
    void alta(int, int, string); //el primero int es para la categoria, el segundo es para la especialidad, i el tercero es para el nombre.
    ~hospita();
};
}


#endif	/* HOSPITAL_HPP */

