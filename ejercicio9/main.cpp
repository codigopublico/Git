/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 27 de septiembre de 2017, 19:03
 */

#include <cstdlib>
#include <iostream>
#include <stdlib.h> // esta es la liberria de rand()

using namespace std;

/*
 *Esto se ha de pasar e a limpio. 
 */

char aux[5] = "0FIN";
class equipo{
public:
    char nombre[200][200];
    int aux = 0;
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
            std::cout << "  La referencia es  " << i <<"\n";
        }
    }
};
int setnombres(equipo *constante){
//De esto tengo que hacer una funcion genereica...... ademas me permite hacer como entrar objectos en una funcion.
    //tengo que hacer una mejor funcion de esto.
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
        constante->setnombrar(cambio);
        constante->getmonstar();
        std::cout << "La im vale:   "<< im << "\n";
        i = 0;
        for(int ii = 1; ii < i; ii++){
                if(im[ii - 1] == aux[0] && im[ii] == aux[1]){
                    //d++;
                }
            }
        }while(d > 0);
    return 0; //aqui se tiene que consegir retornar un objeto por referencia.

}
class partidos : public equipo  {
public:
    //0  significa que perdio i 1 significa que gano el partido de modo que se tiene que hacer la estructura. 
    int n[200][1];//esta es uno de los enfretamientos el 0 es la refernecia que deven ser en las elecciones
    int n2[200][1];//esta es la otra lista de enfrentamientos
    partidos() :  equipo() {
        
    }
    void jugarand(){
        //Este es para realizar los partidos se hara el azar i se tienen que refernciar.
        for(int t = 0; t < aux; t++){
        if(rand() % 2 == 0){
            n[t][1] = 0;
            n2[t][1] = 1;
        }else{
            n2[t][1] = 0;
            n[t][1] = 1;
        }
        }
    }
    int getpart(){
    //esta es la seccion en la que se muestran los partidos los partidos.
        
    }
};
class liga : public partidos   {
public:
    // es por las funciones virtuales o porque es para hcerlo lo que se tiene que hacer es simplenemte es hacer que las classes hagan las variables las herencias i todo lo demas i hacer una super funcion que los gestione todo.
    liga() : partidos(){
        
    }
    void systema(){
        for(int i = 0; i < aux; i++){
            if(i%2 == 0){
                n[i][0] = i;
            }else{
                n2[i][0] = i;
            }
        }
    }
};
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
    setnombres(joan);//Aqui hay un error que se tiene que resolver para la funcion de salida del char.
    std::cout << "Este se sale de la funcion\n";
    joan->getmonstar();
        
}
void p2(){


}
int main(int argc, char** argv) {
    p1();//Equipo.
    p2();
    return 0;
}

