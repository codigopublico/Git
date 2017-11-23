/* 
 * File:   discoteca.hpp
 * Author: iper
 *
 * Created on 23 de noviembre de 2017, 17:37
 */

#ifndef DISCOTECA_HPP
#define	DISCOTECA_HPP
#include <iostream>
#include <string>
using namespace std;
namespace dis{
class disco{
public:
    struct Dis{
      int n;//este es el indice;
      int dura; //esta es la duracion de la cancion;
      string nom;
    }d;
    disco();
    disco operator=(disco&);
    virtual void crear(int, int, string); 
    virtual void ver(int&, int&, string&);
};
class fiesta{
public:
    disco &disc;
    int total[2]; //el primero es para el virtual es el sugdo para real.
    fiesta(int);
    void crear(int, int, string);
    void ver(int&, int&, string&);
};
}

#endif	/* DISCOTECA_HPP */

