/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 20 de diciembre de 2017, 18:28
 * Es igual que la lista simple lo que se implementa la fucnion para antras de la lista....
 * Haber esta funcion compila ahra falta que funcione
 */

#include <cstdlib>

using namespace std;

/*
 * 
 */
class node{
public:
    node(int a, node *sig = 0, node *ant = 0) { v = a; siguiente = sig; anterior = ant; }//aqui esta la magia
    node(){
        //i si sobrecargo esto....
        v = 0;
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
private:
    Pnodo Pnode;//esto esta bien que pasa.....
};
lista::lista(){
    //Pnode(NULL); I si no lo apunto a nada esto creo que funcionara ......:P
}
void lista::Primero(){
    while(Pnode && Pnode->anterior) Pnode = Pnode->anterior;
}
void lista::Ultimo(){
    while(Pnode && Pnode->siguiente) Pnode = Pnode->siguiente;
}
void lista::insertar(int Iv){
    Primero();
    if(Pnode == NULL){
     //Pnode = node;//se pone que los punteros de delante i detras estan vacios no se si dara error en compilacion
     //demomento lo da no se que hacer.
        Pnode = new node(Iv);//raramente fucniona pero tengo que ver como va todo....
    }else{
    while(Pnode->v < Iv &&  Pnode){
        Pnode = Pnode->siguiente;
    }
    Pnodo nuevo = new node(Iv, Pnode->siguiente, Pnode->anterior);
    Pnode->siguiente = nuevo;
    //aqui se hace que no se pueda hacer todo
    }
    Primero();
    
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
int main(int argc, char** argv) {
//vale ahora tengo que provar las cosas que funcionen...........
    
    return 0;
}

