/* 
 * File:   libreria.hpp
 * Author: iper
 *
 * Created on 29 de octubre de 2017, 13:27
 */

#ifndef LIBRERIA_HPP
#define	LIBRERIA_HPP
#include <iostream>
#include <string>
using namespace std;
namespace lib{
    
    class libro{
    public:
        struct dlibro{
            string titulo;
            string autor;
            int categoria;
            int stock;
            int id;
        };
        dlibro uno;
        libro();
        libro(string, string, int);
    };
    class libreria : public libro{
    public:
        dlibro vlibro[200];
        dlibro *pvlibro;
        int total;
        libreria();
        void mostrar();
        void intro_libro(libro);
        int Buscar_libro(string);
        int Buscar_libro(int);//si tengo tiempo hare otra classe si es 0 no encontro si es 1 encontro.
        void vender_libro();
        void stock(int, int);
        void astock(int, int);
        int eliminar(string);
        void vender(int);
        void vender(string);
    };


}


#endif	/* LIBRERIA_HPP */

