/* 
 * File:   grafica.hpp
 * Author: iper
 *
 * Created on 19 de octubre de 2017, 16:33
 * Esta funcion se debe poner en la lista de funciones predeminadas.
 */

#ifndef GRAFICA_HPP
#define	GRAFICA_HPP
using namespace std;
#include <iostream>
void grafica(int iaux[2], int in[200][200]){//esta funcion se debe incluir en las librerias....
    for(int i = 0; i < 300; i++){
        std::cout << "\n";
    }
        std::cout << "Iniciando la grafica" << "\n";
        std::cout << "El 0 es vacio i la X es lleno\n";
        std::cout << "\n";
        for(int i = 0; i < iaux[0]; i++){
        for(int ii = 0; ii < iaux[1]; ii++){        
            if(in[i][ii] == 0){
            std::cout << "0" << " ";
            }else{
                std::cout << "X" << " "; 
            }
        }
        std::cout << " \n"; 
    
    }
        for(int i = 0; i < 10; i++){
        std::cout  << " \n";
        }
    }
void limpiar(){
for(int i = 0; i < 300; i++){
        std::cout << "\n";
    }
}


#endif	/* GRAFICA_HPP */

