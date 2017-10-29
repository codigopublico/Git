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
    string cate[] ={"terror", "poesia"};
    class libro{
    public:
        struct dlibro{
            string titulo;
            string autor;
            int categoria;
        }dl;
        libro();
        libro(string, string, int);
    };
    class libreria: public libro{
    public:
        dlibro vlibro[200];
        dlibro *pvlibro;
        libreria();
        void intro_libro();
        void eli_libro();
        void Buscar_libro();
        void vender_libro();
    };
}


#endif	/* LIBRERIA_HPP */

