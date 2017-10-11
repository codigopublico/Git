#include "garaje.h"
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;
using namespace pasta;
void grafica(){
    int aux[2];
    aux[0] = 10;
    aux[1] = 10;
    int n[aux[0]][aux[1]];
        //std::cout << 0 << " ";
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
        for(int i = 0; i < 10; i++){
          std::cout  << " \n";
        }

}
garaje::garaje(){
    aux[2];
    aux[0] = 10;
    aux[1] = 10;
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

void  garaje::graf(){
    grafica();
    }
