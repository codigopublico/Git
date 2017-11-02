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
    //string cate[] ={"terror", "poesia"};
    class libro{
    public:
        struct dlibro{
            string titulo;
            string autor;
            int categoria;
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
        void Buscar_libro();
        void vender_libro();
        void eliminar(string);
    };
}


#endif	/* LIBRERIA_HPP */

