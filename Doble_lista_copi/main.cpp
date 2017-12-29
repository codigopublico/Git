/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 28 de diciembre de 2017, 17:52
 */

#include <cstdlib>

using namespace std;

/*
 * 
 */


#include <iostream>
#include <string>
using namespace std;

#define ASCENDENTE 1
#define DESCENDENTE 0
void sepa(){
    std::cout << "\n";
    for(int i = 0; i < 10; i++){
        std::cout << "-";
    }
    std::cout << "\n";
}
struct libros{
    bool e;  //esta es interna i que dice si existe este objecto en la lista.
    string titulo;
    string autor;
    int n_pag;
    libros(){
        titulo = "0";
        autor = "0";
        n_pag = 0;
        e = false;
    }
};
struct peliculas{
    bool e;
    string titulo;
    string director;
    int dura; //esta es la duracion de la cancion.....
    peliculas(){
        titulo = "0";
        director = "0";
        dura = 0;
        e = false;
    }
};
struct discos{
    bool e;
    string titulo;
    string autor;
    int n; //este es para el numero de duracion;
    discos(){
        titulo = "0";
        autor = "0";
        e = false;
        n = 0;
    }
};
class material{
public:
    material() { }//que mierdas pasa con las vtable.
    virtual void insert(string, string, int) = 0;
    virtual void mostrar() = 0;
    virtual void eliminar(string) = 0; //se eliminara por el titulo....
};
class nodo {
   public:
    nodo(int v, nodo *sig = NULL, nodo *ant = NULL) :
       valor(v), siguiente(sig), anterior(ant) {}
    nodo(discos ID, nodo *sig = 0, nodo *ant = 0)
    {
        disc.autor = ID.autor;
        disc.n = ID.n;
        disc.titulo = ID.titulo;
        disc.e = true;
        anterior = ant;
        //std::cout << "Estoy creado un disco en la lista de discos\n";
        siguiente = sig;
    }
    nodo(peliculas ID, nodo *sig = 0, nodo  *ant = 0)
    {
        peli.director = ID.director;
        peli.dura = ID.dura;
        peli.titulo = ID.titulo;
        peli.e = true;
        //std::cout << "Estoy crando un disco\n";
        siguiente = sig;
        anterior = ant;
    }
    nodo(libros ID, nodo *sig = 0, nodo *ant = 0){
        lib.autor = ID.autor;
        lib.n_pag = ID.n_pag;
        lib.titulo = ID.titulo;
        lib.e = true;
        //std::cout << "Estoy creando un libro\n";
        siguiente = sig;
        anterior = ant;
    }

   private:
    int valor;
    nodo *siguiente;
    nodo *anterior;
    discos disc;
    peliculas peli;
    libros lib;
        
   friend class lista;
};

typedef nodo *pnodo;

class lista {
   public:
    lista(){ plista = NULL; c = 0; }
    ~lista();
    
    void Insertar(int v);
    void Insertar(libros ID);
    void Insertar(peliculas ID);
    void Insertar(discos ID);
    void Borrar(int v);
    void Borrar(libros ID);
    bool ListaVacia() { return plista == NULL; } 
    void Mostrar(int);
    void Siguiente();
    void Anterior();
    void Primero();
    void Ultimo();
    bool Actual() { return plista != NULL; }
    int ValorActual() { return plista->valor; }
    
   private:
    pnodo plista;
    int c;
};

lista::~lista()
{
   pnodo aux;
   
   Primero();
   while(plista) {
      aux = plista;
      plista = plista->siguiente;
      delete aux;
   }
}
void lista::Insertar(peliculas ID)
{
   pnodo nuevo;
   std::cout << "Esto se ejecuta\n";
   Primero();
   std::cout << "Esto es despues de Primero\n";
   // Si la lista está vacía
   if(ListaVacia() == true) {
       std::cout << "Esta la lista vacia\n ";
      // Asignamos a lista un nuevo nodo de valor v y
      // cuyo siguiente elemento es la lista actual                    
      nuevo = new nodo(ID, plista);
      if(!plista) plista = nuevo;
      else plista->anterior = nuevo;
   }else {
      // Buscar el nodo de valor menor a v 
      // Avanzamos hasta el último elemento o hasta que el siguiente tenga 
      // un valor mayor que v 
      std::cout << "La lista no esta vacia\n";
      while(plista->siguiente && plista->siguiente->valor <= c) c++; Siguiente();
      // Creamos un nuevo nodo después del nodo actual
      nuevo = new nodo(ID, plista->siguiente, plista);
      plista->siguiente = nuevo;
      if(nuevo->siguiente) nuevo->siguiente->anterior = nuevo;
   }
}
void lista::Insertar(discos ID)
{
   pnodo nuevo;
   std::cout << "Esto se ejecuta\n";
   Primero();
   std::cout << "Esto es despues de Primero\n";
   // Si la lista está vacía
   if(ListaVacia() == true) {
       std::cout << "Esta la lista vacia\n ";
      // Asignamos a lista un nuevo nodo de valor v y
      // cuyo siguiente elemento es la lista actual                    
      nuevo = new nodo(ID, plista);
      if(!plista) plista = nuevo;
      else plista->anterior = nuevo;
   }else {
      // Buscar el nodo de valor menor a v 
      // Avanzamos hasta el último elemento o hasta que el siguiente tenga 
      // un valor mayor que v 
      std::cout << "La lista no esta vacia\n";
      while(plista->siguiente && plista->siguiente->valor <= c) c++; Siguiente();
      // Creamos un nuevo nodo después del nodo actual
      nuevo = new nodo(ID, plista->siguiente, plista);
      plista->siguiente = nuevo;
      if(nuevo->siguiente) nuevo->siguiente->anterior = nuevo;
   }
}
void lista::Insertar(libros ID)
{
   pnodo nuevo;
   std::cout << "Esto se ejecuta\n";
   Primero();
   std::cout << "Esto es despues de Primero\n";
   // Si la lista está vacía
   if(ListaVacia() == true) {
       std::cout << "Esta la lista vacia\n ";
      // Asignamos a lista un nuevo nodo de valor v y
      // cuyo siguiente elemento es la lista actual                    
      nuevo = new nodo(ID, plista);
      if(!plista) plista = nuevo;
      else plista->anterior = nuevo;
   }else {
      // Buscar el nodo de valor menor a v 
      // Avanzamos hasta el último elemento o hasta que el siguiente tenga 
      // un valor mayor que v 
      std::cout << "La lista no esta vacia\n";
      while(plista->siguiente && plista->siguiente->valor <= c) c++; Siguiente();
      // Creamos un nuevo nodo después del nodo actual
      nuevo = new nodo(ID, plista->siguiente, plista);
      plista->siguiente = nuevo;
      if(nuevo->siguiente) nuevo->siguiente->anterior = nuevo;
   }
}
void lista::Insertar(int v)
{
   pnodo nuevo;
 
   Primero();
   // Si la lista está vacía
   if(ListaVacia() || plista->valor > v) {
       std::cout << "Esta la lista vacia default\n";
      // Asignamos a lista un nuevo nodo de valor v y
      // cuyo siguiente elemento es la lista actual                    
      nuevo = new nodo(v, plista);
      if(!plista) plista = nuevo;
      else plista->anterior = nuevo;
   }
   else {
      // Buscar el nodo de valor menor a v 
      // Avanzamos hasta el último elemento o hasta que el siguiente tenga 
      // un valor mayor que v 
      while(plista->siguiente && plista->siguiente->valor <= v) Siguiente();
      // Creamos un nuevo nodo después del nodo actual
      nuevo = new nodo(v, plista->siguiente, plista);
      plista->siguiente = nuevo;
      if(nuevo->siguiente) nuevo->siguiente->anterior = nuevo;
   }
   std::cout << "Fin de la insercion\n";
}

void lista::Borrar(int v)
{
   pnodo nodo;

   nodo = plista;
   while(nodo && nodo->valor < v) nodo = nodo->siguiente;
   while(nodo && nodo->valor > v) nodo = nodo->anterior;

   if(!nodo || nodo->valor != v) return;
   // Borrar el nodo 
   
   if(nodo->anterior) // no es el primer elemento 
      nodo->anterior->siguiente = nodo->siguiente;
   if(nodo->siguiente) // no el el último nodo
      nodo->siguiente->anterior = nodo->anterior;
   delete nodo;
}
void lista::Borrar(libros ID)
{
   pnodo nodo;
   Primero();
   nodo = plista;
   /*while(nodo && nodo->valor < v) nodo = nodo->siguiente; // de momento esto es mierda
   if(nodo->anterior) // no es el primer elemento 
      nodo->anterior->siguiente = nodo->siguiente;
   if(nodo->siguiente) // no el el último nodo
      nodo->siguiente->anterior = nodo->anterior;
   delete nodo;*/
   while(nodo){
       std::cout << "While de borrado\n";
       if(!nodo->lib.e){
       }else{
       if(nodo->lib.e){
           if(nodo->lib.titulo == ID.titulo){
               std::cout << "\nLibro encontrado\n";
               break;
           }
       }
       }
       if(!nodo->siguiente) std::cout << "No esta lo que buscas\n";
       if(!nodo->siguiente) break;
       nodo = nodo->siguiente;
   }
   if(nodo->lib.e && nodo->lib.titulo == ID.titulo){
       std::cout << "Borrando nodo\n";
       //aqui es donde se borra el nodo
       if(nodo->anterior) // no es el primer elemento 
      nodo->anterior->siguiente = nodo->siguiente;
   if(nodo->siguiente) // no el el último nodo
      nodo->siguiente->anterior = nodo->anterior;
   delete nodo;
   }
}
void lista::Mostrar(int orden)
{
   pnodo nodo;
   if(orden == ASCENDENTE) {
      Primero();
      nodo = plista;
      while(nodo) {
          if(!nodo->lib.e && !nodo->disc.e && !nodo->peli.e){
         cout << nodo->valor << "-> " << nodo->lib.e << "  ";
          }
          if(nodo->lib.e){
              sepa();
              std::cout << "Esto es un libro\n";
              std::cout << "El autor es:  " << nodo->lib.autor << "\n";
              sepa();
          }
          if(nodo->disc.e){
              sepa();
              std::cout << "Esto es un disco\n";
              std::cout << "El titulo es: " << nodo->disc.titulo << "\n";
              sepa();
          }
          if(nodo->peli.e){
              sepa();
              std::cout << "Esto es una pelicula\n";
              std::cout << "El titulo es: " << nodo->peli.titulo << "\n";
              sepa();
          }
          nodo = nodo->siguiente;
         /*if(nodo->lib.e){
             std::cout << " " << nodo->lib.e << "\n";
         }*/
      }
   }
   else {
      Ultimo();
      nodo = plista;
      while(nodo) {
         cout << nodo->valor << "-> ";
         nodo = nodo->anterior;
      }
   }
   cout << endl;
}

void lista::Siguiente()
{
   if(plista) plista = plista->siguiente;
}

void lista::Anterior()
{
   if(plista) plista = plista->anterior;
}

void lista::Primero()
{
   while(plista && plista->anterior) plista = plista->anterior;
}

void lista::Ultimo()
{
   while(plista && plista->siguiente) plista = plista->siguiente;
}

int main(int argc, char** argv) {
  lista Lista;
   libros ID;
   peliculas I;
   discos A;
   ID.autor = "Orwell";
   I.titulo = "1984";
   A.titulo = "Mundo feliz";
   //Lista.Insertar(ID);
   Lista.Insertar(20);
   Lista.Insertar(10);
   Lista.Insertar(40);
   Lista.Insertar(30);
   Lista.Insertar(20);
   Lista.Insertar(ID);
   Lista.Insertar(I);
   Lista.Insertar(A);
   Lista.Mostrar(ASCENDENTE);
   Lista.Mostrar(DESCENDENTE);

   Lista.Primero();
   cout << "Primero: " << Lista.ValorActual() << endl;
   Lista.Ultimo();
   cout << "Ultimo: " << Lista.ValorActual() << endl;
   Lista.Borrar(10);
   Lista.Borrar(45);
   sepa();
   Lista.Borrar(40);
   sepa();
   Lista.Borrar(ID);
   sepa();
   Lista.Borrar(ID);
   Lista.Mostrar(ASCENDENTE);
   Lista.Mostrar(DESCENDENTE);

    return 0;
}

//tengo un error en borrar lo unico que habia que hacer es simplemente es poner un break en caso de que no fucione