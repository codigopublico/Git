/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 23 de septiembre de 2017, 12:34
 */

#include <cstdlib>
#include <iostream>
#include <stdlib.h>
using namespace std;

/*
 * 
 */
void cuadricula(int aux[]){
    int n[aux[0]][aux[1]];
    for(int i = 0; i < aux[0]; i++){
        for(int ii = 0; ii < aux[1]; ii++){
            if(n[i][ii] == 0){
            std::cout << "0" << " ";
            }else{
                std::cout << "X" << " "; 
            }
        }
        std::cout  << " \n";
    
    }

}
class garaje{
    public:
    int aux[2];
    int n[200][200];
    garaje(int fil, int col);
    void grafica(){
    
    }

};
void garaje::garaje(int fil, int col){
    aux[2] = {fil, col};
    n[aux[0]][aux[1]];
 for(int i = 0; i < aux[0]; i++){
        for(int ii = 0; ii < aux[1]; ii++){
            n[i][ii] = rand() % 2;
        }
    }
}
void juego(){
    int p[2] = {10, 10};
    garaje aleatrio(p);
}
int main(int argc, char** argv) {
    juego();
    cin.get();
    return 0;
}

