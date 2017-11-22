/* 
 * File:   discoteca.hpp
 * Author: iper
 *
 * Created on 22 de noviembre de 2017, 18:56
 */

#ifndef DISCOTECA_HPP
#define	DISCOTECA_HPP
#include <iostream>
#include <string>
#include <mia/no_renderizadas/mis_funciones.hpp>
using namespace std;
namespace dis{
    class disco{
    public:
        struct dis{
            int n;//este es el numero del disco
            int dura; //esta es la duracion del disco
            string autor;
            string titulo;
        }d;
        disco();
        virtual void crear(int, int, string, string);//este es para hacer la lista de arriva
        ~disco();
    };
    class lugar : public disco{
    public:
        int discos[2];//el primero del array es para los virtuales i el es para los creados
        disco* Pdiscos;
        lugar(int p);
        void crear(int, int, string, string);
        ~lugar();
    };
}


#endif	/* DISCOTECA_HPP */

