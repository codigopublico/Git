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

class nodo {
   public:
    nodo(int v, nodo *sig = NULL, nodo *ant = NULL) :
       valor(v), siguiente(sig), anterior(ant) {}

   private:
    int valor;
    nodo *siguiente;
    nodo *anterior;
        
   friend class lista;
};

typedef nodo *pnodo;

class lista {
   public:
    lista() : plista(NULL) {}
    ~lista();
    
    void Insertar(int v);
    void Borrar(int v);
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

void lista::Insertar(int v)
{
   pnodo nuevo;
 
   Primero();
   // Si la lista está vacía
   if(ListaVacia() || plista->valor > v) {
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

void lista::Mostrar(int orden)
{
   pnodo nodo;
   if(orden == ASCENDENTE) {
      Primero();
      nodo = plista;
      while(nodo) {
         cout << nodo->valor << "-> ";
         nodo = nodo->siguiente;
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
   
   Lista.Insertar(20);
   Lista.Insertar(10);
   Lista.Insertar(40);
   Lista.Insertar(30);

   Lista.Mostrar(ASCENDENTE);
   Lista.Mostrar(DESCENDENTE);

   Lista.Primero();
   cout << "Primero: " << Lista.ValorActual() << endl;
   
   Lista.Ultimo();
   cout << "Ultimo: " << Lista.ValorActual() << endl;
   
   Lista.Borrar(10);
   Lista.Borrar(15);
   Lista.Borrar(45);
   Lista.Borrar(40);
   
   Lista.Mostrar(ASCENDENTE);
   Lista.Mostrar(DESCENDENTE);

    return 0;
}

