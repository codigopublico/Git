/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 20 de diciembre de 2017, 18:28
 * Es igual que la lista simple lo que se implementa la fucnion para antras de la lista....
 * Haber esta funcion compila ahra falta que funcione
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
class node{
public:
    node(int a, node *sig = 0, node *ant = 0) { v = a; siguiente = sig; anterior = ant;  e = true;}//aqui esta la magia
    node(node *sig = 0, node *ant = 0){
        //i si sobrecargo esto....
        v = 0; //falta lo de node();
        siguiente = sig;
        anterior = ant;
        e = false;
    }
    /*node(int a, node *sig = 0, node *ant = 0){
        v = a;
        //lo que no se si modificando el v funcionara ...
        siguiente = 0;
        anterior = 0;//esto es para arreglar el prblema de la implementacion....
        
    }*/
    friend class lista;
private:
    int v;
    bool e;//este es para saber si esta vacio o no 
    node *siguiente;
    node *anterior;
};
typedef node *Pnodo;
class lista{
public:
    lista();
    void insertar(int Iv);
    void borrar(int Iv);
    void mostrar();
    void Primero();
    void Ultimo();
    int valor_actual();
    void siguiente();
    bool vacia(){ return Pnode == NULL;  }
    //antes de entragar mirar las fugas de memoria
private:
    Pnodo Pnode;//esto esta bien que pasa.....
};
lista::lista(){
    //Pnode(NULL); I si no lo apunto a nada esto creo que funcionara ......:P
}
void lista::Primero(){
    while(Pnode->e && Pnode->anterior->e) Pnode = Pnode->anterior;//la pregunta es la misma a ver me tragare todo lo de c++
}
void lista::Ultimo(){
    while(Pnode->e && Pnode->siguiente->e) Pnode++;
}
void lista::insertar(int Iv){
     
    std::cout << "1.2\n";
    //Primero();
    std::cout << "1.3\n";
    if(Pnode->e != false){//la pregunta es como detectar que esta igualado a 0 aqui tengo un error como saber si la lista esta vacia...
        std::cout << "1.5\n La lista no esta vacia....\n";
        int a = 0;
    while(Pnode->v < Iv &&  Pnode->e){
        ++a;
        Pnode = Pnode->siguiente;
        std::cout << "Me temo que aqui la lista no llega.....! " << a <<  "\n";
    }
        std::cout << "Creando el nuevo nodo\n";
    Pnodo aux = new node(Pnode->v, Pnode->siguiente, Pnode->anterior);
    Pnode->siguiente = new node(Iv, aux, aux); //tiene que ser un nodo que apunte aplguna parte;
    Pnode->anterior = new node(Pnode->anterior->v, aux, aux);
    std::cout << "Llegara\n";
    //aqui se hace que no se pueda hacer todo
    }
    if(!Pnode->e){//puse esto para hacer que a ver si funciona
     //Pnode = node;//se pone que los punteros de delante i detras estan vacios no se si dara error en compilacion
     //demomento lo da no se que hacer.
        std::cout << "Aqui llegara la lista..\n";
        Pnodo aux = new node(Pnode->v, Pnode->siguiente, Pnode->anterior);
        Pnode = new node(Iv, aux, aux);//raramente fucniona pero tengo que ver como va todo....
        std::cout << "1.4\n";
    }
    std::cout << "Inicio de Primero\n";
    //Primero();//este codigo se ha de pasar a limpio.....
    std::cout << "Fin de la lista\n";
}
void lista::siguiente(){
    if(Pnode) Pnode = Pnode->siguiente;
}
void lista::borrar(int Iv){
    Primero();
    while(Pnode->v != Iv){
        siguiente();//esta es la orden que cada vez que se mueve el puntero apunta hacia otro lado.
    }
    Pnode = new node(Pnode->siguiente->v, Pnode->siguiente->siguiente, Pnode->anterior->anterior);
    Primero();
}
int lista::valor_actual(){
    return Pnode->v;
}
void lista::mostrar(){
    std::cout << "Pnode: " << Pnode->e << "Pensar\n";
    Ultimo(); //aqui es donde falla
    //std::cout << "Pnode: " << Pnode->anterior->e << "Pensar\n";
    //std::cout << "Tengo violacion \n";
    int a = 0;
    while(Pnode->e && a < 5){
    std::cout << "Valor :" << Pnode->v << "\n";
    std::cout << "Valor :" << Pnode->siguiente->v << "\n";
    std::cout << "Valor :" << Pnode->v << "\n";
    std::cout << "Hola  :\n"; 
    //Pnode = Pnode->siguiente;
    a++;
    }
    Primero();
}
int main(int argc, char** argv) {
//vale ahora tengo que provar las cosas que funcionen...........
    std::cout << "Esta es una vilocion de si\n";
    lista prueva;
    std::cout << "1\n";
    prueva.insertar(5);
    prueva.insertar(10);
    prueva.insertar(20);
    //prueva.borrar(20);
    std::cout << "2\n";
    prueva.mostrar();
    return 0;
}

//A veces es mejor poner un boleano para comporvar los nodos