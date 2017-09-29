/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 27 de septiembre de 2017, 19:03
 */

#include <cstdlib>
#include <iostream>
using namespace std;
void set(){


}

/*
 * 
 */
class equipo{
public:
    char nombre[200][200];
    int aux;
    char *pn;
    equipo(){
        //*pn = &nombre;
        aux = 0;
    }
    void setnombrar(char nom[200]){
        int i = 0;
        do{
            nombre[aux][i] = nom[i];
            i++;
        }while(nom[i - 1] != 0);
        aux++;
    }
    void getmonstar(){
        //tiene que retornar lo de la char con lo de los puneteros una vez echo se tiene que hacer un metodo para destruir.
        int ii = 0;
        for(int i = 0; i < aux; i++){
            std::cout << "Los nombres de los equipos son:    ";
            ii = 0;
            do{
                std::cout << nombre[i][ii];
                ii++;
            }while(nombre[i][ii] != 0);
            std::cout << "\n";
        }
    }
};
void p1(){
    equipo joan;
    char nom[] = "jona0";
    char nom2[] = "Alejandria";
    char im[200];
    char aux[] = "0FIN";
    joan.setnombrar(nom);
    joan.setnombrar(nom2);
    joan.getmonstar();
    std::cout << "Para salir es ......:   " << aux[0] << "\n";
//esto es para hacer la entrada de equipos
        int i; 
        do{
                int e = 0;
        do{
            std::cin >> im[i];
            i++;
            for(int ii = 0; ii < i; ii++){
                if(im[ii] == aux[0]){
                    e++;
                }
            }
        }while(e == 0);
        std::cout << "la i es :    " << i << "\n";
        char cambio[i - 2];
        for(int g = 0; g < i - 1; g++){
            cambio[g] = im[g];
            std::cout << "La g es: " << g << "\n";
        }
        joan.setnombrar(cambio);
        joan.getmonstar();
        std::cout << "La im vale:   "<< im << "\n";
        i = 0;
        }while(im[i] != aux[0] || im[i - 1] != aux[0]);
}
int main(int argc, char** argv) {
    p1();
    return 0;
}

