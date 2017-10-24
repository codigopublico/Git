#include <cstdlib>
#include <iostream>
#include <string>
#include "garaje.h"

/*
 * Hola mundo cybernetico
 */
 
 void def(){
 std::cout << "Hola soy la definicion del programa\n";
 }
garaje::garaje(int fil, int col){
std::cout << "Ejecutado el constructor del programa";
    aux[0] = fil;
    aux[1] = col;
    n[aux[0]][aux[1]];
 for(int i = 0; i < aux[0]; i++){
        for(int ii = 0; ii < aux[1]; ii++){
            n[i][ii] = rand() % 5;
            if(n[i][ii] > 0){
                n[i][ii] == 1;
            }
        }
    }

}
garaje::garaje(){
std::cout << "Ejecutado el constructor del programa";
  aux[0] = 20;
    aux[1] = 20;
    n[aux[0]][aux[1]];
 for(int i = 0; i < aux[0]; i++){
        for(int ii = 0; ii < aux[1]; ii++){
            n[i][ii] = rand() % 5;
            if(n[i][ii] > 0){
                n[i][ii] == 1;
            }
        }
    }

}
void garaje::grafica(){
	std::cout << 0 << " ";
        for(int i = 0; i < aux[1]; i++){
            std::cout << i << " ";
        }
        std::cout << "\n";
        for(int i = 0; i < aux[0]; i++){
            std::cout << i << " ";
        for(int ii = 0; ii < aux[1]; ii++){        
            if(n[i][ii] == 0){
            std::cout << "0" << " ";
            }else{
                std::cout << "X" << " "; 
            }
        }
        std::cout << " \n"; 
    }
    aux[2];
    aux[0] = fil;
    aux[1] = col;
    n[aux[0]][aux[1]];
 for(int i = 0; i < aux[0]; i++){
        for(int ii = 0; ii < aux[1]; ii++){
            n[i][ii] = rand() % 5;
            if(n[i][ii] > 0){
                n[i][ii] == 1;
            }
        }
        for(int i = 0; i < 10; i++){
        std::cout  << " \n";
        }
    }
}
