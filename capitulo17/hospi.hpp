/* 
 * File:   hospi.hpp
 * Author: iper
 *
 * Created on 8 de diciembre de 2017, 6:58
 */

#ifndef HOSPI_HPP
#define	HOSPI_HPP
#include <iostream>
#include <string>
using namespace std;
namespace dis{
class Bdisco{
public:
    struct Ddisco{
        int n; //este es el numero de disco el indice;
        int dura;//esta es la duracion del disco
        string titulo;//esta es el titulo de la cancion;
        string autor;//esta es para el autor;
        int nivel; //este es el volumen de la cancion
        bool single; //este es si es sigle o no;
        Ddisco(){
            n = 0;
            dura = 0;
            titulo = "0";
            autor = "0";
            nivel = 0;
            single = false;
        }
    }Ddi;
    Bdisco();
    Bdisco(int&, string&, string&);
    virtual Ddisco get() = 0;
    //virtual void single(bool&) = 0;
    virtual void put(Ddisco&) = 0;
    virtual ~Bdisco();
};
class lista : public Bdisco{
public:
    lista(int);
    Ddisco get();
    void put(Ddisco&);
private:
    Ddisco *Disco;
};

}


#endif	/* HOSPI_HPP */

