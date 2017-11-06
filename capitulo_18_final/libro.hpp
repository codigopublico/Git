/* 
 * File:   libro.hpp
 * Author: iper
 *
 * Created on 3 de noviembre de 2017, 21:40
 */

#ifndef LIBRO_HPP
#define	LIBRO_HPP
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
            int stock;
            int id;
        };
        dlibro uno;
        libro();
        libro(string, string, int);
    };
    class peliculas{
        struct dpelicula{
            string titulo;
            string autor;
            int duracion;
            int stock;
            int id;
        };
    };
    class libreria : public libro{
    public:
        dlibro vlibro[200];
        dlibro *pvlibro;
        int total;
        libreria();
        void mostrar();
        void intro_libro(libro);//aqui se tiene que hacer el polimorfismo
        int Buscar_libro(string);
        int Buscar_libro(int);//si tengo tiempo hare otra classe si es 0 no encontro si es 1 encontro.
        void vender_libro();
        void stock(int, int);
        void astock(int, int);
        void eliminar(string);
        void vender(int);
        void vender(string);
    };


}




#endif	/* LIBRO_HPP */

