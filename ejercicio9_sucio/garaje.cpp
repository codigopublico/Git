#include "garaje.hpp"
using namespace g;
gara::gara(){
    std::cout << "Constructor de la classe";
    aux[2];
    aux[0] = 20;
    aux[1] = 20;
    std::cout << "La dimencion por defecto es: ";
    for(int i = 0; i < 2; i++){
        std::cout << aux[i] <<"  ";
    }
    std::cout << "\n";
    n[aux[0]][aux[1]];
 for(int i = 0; i < aux[0]; i++){
        for(int ii = 0; ii < aux[1]; ii++){
            n[i][ii] = 0;
            
        }
    }

}
void gara::grafica(){
    std::cout << "Iniciando la grafica \n el x es vacio \ni el * es lleno\n ";
    for(int i = 0; i < aux[0]; i++){
        
        std::cout << i;
        if(i < 10){
            std::cout << "  ";
        }else{
            std::cout << " ";
        }
        
    }
    std::cout << "\n";
    for(int i = 0; i < aux[0]; i++){
        for(int ii = 0; ii < aux[1]; ii++){
            if(n[i][ii] == 0){
                std::cout << " x ";
            }else{
            std::cout << " * ";
            }
        }
        std::cout << i <<"\n";
    }
}
void gara::get(int col, int fil){
    aux[0] = col;
    aux[1] = fil;
    
    
}
void gara::cambio(int p[2], int r){
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