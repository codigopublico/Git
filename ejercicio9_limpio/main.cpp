/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 1 de octubre de 2017, 15:04
 */

#include <cstdlib>
#include <iostream>
#include <stdlib.h> // esta es la liberria de rand()


using namespace std;

/*
 * Este es para hacer la limpieza de ejercicio9 De modo que se hara de forma progresiva.
 */
//variables publicas.
char aux2[5] = "0FIN";
char aux3[4] = "FIN";
class equipo{
    //eta classe es la del equipo con todos sus metodos i funciones que se heradara de todas las demas.
    public:
    char nombre[200][200]; //Este es el arry de arrays que verifica que todo funcione bien.
    int aux = 0;//Esta es la que cuenta el numero de equipos introducidos.
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
            std::cout << "  La referencia es  " << i << "\n";
        }
    }
};
int setnombres(equipo *constante){
    //eta es la funcion que se encarga de escanear  todo lo del teclado.
    //tengo que hacer que se haga todo por teclado.
    int e = 0;
    std::cout << "\nPara poner un equipo terminar con un 0, Para terminar de poner eqipos usar la palabra FIN0\n";
    while(e < 2){//El bucle ya esta echo
     int i = 0; //Esta es la que cuenta los caracteres,
     e = 0; //Esta es la variable que verifica si el final del string con un 0.
     char im[200]; //Esta es la que se pone es la que  caputra el teclado.
        do{
            std::cin >> im[i];
            i++;
            for(int ii = 0; ii < i; ii++){
                if(im[ii] == aux2[0]){  
                    e++;
                }
            }
        }while(e == 0);
        e = 0;
        char cambio[i - 2];
        for(int g = 0; g < i -1; g++){
            cambio[g] = im[g];
        }
        e = 0;
        for(int g = 0; g < 4; g++){
            if(cambio[g] == aux3[g]){
                e++;
            }
        
        }
        if(e > 2){
            std::cout << "FIN" << "\n";
            e = 3;
        }else{
        constante->setnombrar(cambio);//tiene que haber una funcion recrusiva.
        }
        std::cout << "\n Monstrado los nombres introducidos \n";
        constante->getmonstar();
    }
    
    }
class partidos : public equipo  {
public:
    // Esta se carga de jugar los partidos.
    int n[2]; 
    int r;
    partidos() : equipo(){
       
    }
    void jugar(){
        if(rand()%2 == 0){
            n[1] = 0;
            n[0] = 1;
        }else{
                n[1] = 1;
                n[0] = 0;
        }
        
    }
};
class liga : public partidos   {
public:
    //este se encarga de organizar de esquematizar los partidos en base a una liga
    liga(){
        aux = 0;
    }
    void crearliga(){
        int l[2][200]; //Aqui tienen que ir los id's de los que se tienen que enfrentar.
        int ii;
        for(int i = 0; i < aux; i++){
            if(i%2 == 0){
                l[1][i] = i;
                //std::cout << "   Un bando a enfertar es .. ";
                //ii = 0;
                /*while(nombre[i][ii] != 0) {
                    std::cout << nombre[i][ii];
                ii++;*/
            //}
        }else{
                l[0][i - 1] = i; 
            }
            std::cout << "\n";
        }
        for(int i = 0; i < aux / 2; i++){
            for(int e = 0; e < 2; e++){
                if(e == 0){
                    std::cout << "     El equipo    ";
                }else{
                    std::cout << "     el equipo    ";
                }
                
            ii = 0;
            while(nombre[i][ii] != 0) {
                std::cout << nombre[l[e][i]][ii];
                ii++;
            }
            if( e < 1 ){
            std::cout << "   se enfrenta a   ";
            }
            }
            std::cout << "\n";
        }
    }
};
void fliga(){
//Esta es la funcion madre de todo el proyecto que organizara todas las classes de arriva en objetos.
    //sobre todo lo que hara es hacer ir el menu.
    liga *base = new liga;
    std::cout << "\nCreacion de una liga \n" << "Para empezar pon los nombres de los equipos \n";
    setnombres(base);
    //base->getmonstar();
    base->crearliga();
}
int main(int argc, char** argv) {
    fliga();
    return 0;
}