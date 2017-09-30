/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 27 de septiembre de 2017, 19:03
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
char aux[5] = "0FIN";
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
int setnombres(equipo *constante){
//De esto tengo que hacer una funcion genereica...... ademas me permite hacer como entrar objectos en una funcion.
    std::cout << "Intentado hacer el la funcion (), el paso por referencia de un objeto \n";
    constante->getmonstar();
    int i; 
    int d = 0;
    char im[200];
        int e = 0;
        do{
                int e = 0;
        do{
            std::cin >> im[i];
            i++;
            std::cout << "11111\n"; 
            for(int ii = 0; ii < i; ii++){
                std::cout << "For\n";
                if(im[ii] == aux[0]){ 
                    std::cout << "11111\n"; 
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
        constante->setnombrar(cambio);
        constante->getmonstar();
        std::cout << "La im vale:   "<< im << "\n";
        i = 0;
        for(int ii = 0; ii < i; ii++){
                if(im[ii] == aux[0] || im[ii] == aux[1]){
                    d++;
                }
            }
        }while(d > 0);
    return 0; //aqui se tiene que consegir retornar un objeto por referencia.

}

void p1(){
    equipo *joan = new equipo;
    equipo consta;
    joan = &consta;
    char nom[] = "jona0";
    char nom2[] = "Alejandria";
    joan->setnombrar(nom);
    joan->setnombrar(nom2);
    joan->getmonstar();
    std::cout << "Para salir es ......:   " << aux[0] << "\n";
//esto es para hacer la entrada de equipos
    //primero es pasar el objecto referenciado a la funcion.
    setnombres(joan);
        
}
int main(int argc, char** argv) {
    p1();
    return 0;
}

