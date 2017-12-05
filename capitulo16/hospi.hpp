/* 
 * File:   hospi.hpp
 * Author: iper
 *
 * Created on 5 de diciembre de 2017, 16:43
 */

#ifndef HOSPI_HPP
#define	HOSPI_HPP
#include <iostream>
#include <string>
using namespace std;
namespace hos{
    void limpia();
    void limpia(const int&);
    class persona{
    public:
        virtual void ver(string&, int&);
        persona();
        persona(const string&, const int&);
        struct Spersona{
             string Nombre;
        int telf;
        Spersona(){
            Nombre = "0";
            telf = 0;
        };//este es el contructor de la classe
        Spersona operator=(const Spersona &a){//tengo que hacer un operador igual que este pero para eliminar en la alura de profecional.
            Spersona res;
            res.Nombre = a.Nombre;
            res.telf = a.telf;
            return res;
        }//este es el contructor de copias para el editor.
        void operator-(Spersona &a){
            a.Nombre = "0";
            a.telf = 0;
        }
}Spers;

        };
 class profecional : public persona{
 public: 
     //profecional *Hprof;
     profecional();
     profecional(const string&, const int&);
     profecional(const string&, const int&, const float&, const int[2]);
     profecional operator=(const profecional&);
     //profecional* ver();
     //variables......
     int n; 
     struct Sprofecional{
        float Planta;
        string especialidad;
        int horario[2]; //una es la que emplieza i la otra la que acaba;
        Sprofecional(){
            Planta = 0;
            especialidad = "0";
            for(int i = 0; i < 2; i++){
                horario[i] = 0;
                
            }
        }
        Sprofecional operator=(const Sprofecional &a){
            Sprofecional res;
            res.Planta = a.Planta;
            res.especialidad = a.especialidad;
            for(int i = 0; i < 2; i++){
            res.horario[i] = res.horario[i];
            }
        }
        void operator-(Sprofecional &a){
            a.Planta = 0;
            a.especialidad = "0";
            for(int i = 0; i < 2; i++){
            a.horario[i] = 0;
            }
        }
}Sprof;

     
 };
       
    }

    
    



#endif	/* HOSPI_HPP */

