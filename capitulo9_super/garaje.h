/* 
 * File:   agenda.h
 * Author: iper
 * Tengo que arreglar la libreria ademas de hacer que se pueda hacer un std i retornar el string de char.
 * Hacer el tren.
 * Created on 16 de septiembre de 2017, 12:38
 */
#define	garaje_H
#ifdef	__cplusplus
extern "C" {
#endif
#include <iostream>
#include <string>
    
    using namespace std;
    string h;
    void hol(){//esta funcion es para hacer la prueva de biblieteca
	std::cout << "Hola bibleoteca\n";
    }
    class garaje{
    public:
    int aux[2];
    int n[200][200];
    int fil;
    int col;
    garaje(int fil, int col);
    garaje();
    void grafica();
    void cambio(int p[2], int r){
        if( r == n[p[0]][p[1]]){
            std::cout << "No se puede realizar el cambio de  \n" << p[0] << "  " << p[1] << "  " << r << "\n";
        }else{
        if(r > 0){
            
            std::cout << "entro el coche de la possicion: " << p[0] << "  " << p[1] << "\n";
        }else{
            std::cout << "Salio el coche de la possicion " << p[0] << "  " << p[1] << "\n";
        }
        }
        n[p[0]][p[1]] = r;
}
};
class vehiculo{
public:
    string color;
    int caballos;
    string marca;
    string modelo;
    vehiculo(){};
    vehiculo(string incolor, int incaballos, string inmarca, string inmodelo){
        color = incolor;
        caballos = incaballos;
        marca = inmarca;
        modelo = inmodelo;
    };
    void setcolor(string incolor){
        color = incolor;
    }
    void setcaballos(int incaballos){
        caballos = incaballos;
    }
    void setmarca(string inmarca){
        marca = inmarca;
    }
    void setmodelo(string inmodelo){
        modelo = inmodelo;
    }
    string getcolor(){
        return color;
    }
    int getcaballos(){
        return caballos;
    }
    string getmarca(){
        return marca;
    }
    string getmodelo(){
        return modelo;
    }
    //~vehiculo(){};
};

   
   

};
#ifdef	__cplusplus



#endif


	/* garaje_h */

