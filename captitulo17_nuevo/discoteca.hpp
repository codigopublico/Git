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
    disco(int, int, string);
    disco operator=(disco &a){
        disco res(a.d.n, a.d.dura, a.d.nom);
        return res;
    }
    virtual void crear(int, int, string); 
    virtual void ver(int&, int&, string&);
};
class fiesta : public disco{
public:
    int total[2];
    disco *disc;
    fiesta(int);
};
}

#endif	/* DISCOTECA_HPP */

