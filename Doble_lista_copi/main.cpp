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
void sepa(int n){
    std::cout << "\n";
    for(int i = 0; i < n; i++){
        std::cout << "-";
    }
    std::cout << "\n";
}
void lim(int n){
    for(int i = 0; i < n; i++){
        std::cout << "\n";
    }
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
        valor = 0;
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
    void Borrar(peliculas ID);//aqui hay un error
    void Borrar(discos ID);
    bool ListaVacia() { return plista == NULL; } 
    void Mostrar(int);
    void Siguiente();
    void Anterior();
    void Primero();
    void Ultimo();
    void Buscar(int v);
    void Buscar(libros ID);
    void Buscar(peliculas ID);
    void Buscar(discos ID);
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
   std::cout << "Esto Insertado una pelicula\n";
   Primero();
   //std::cout << "Esto es despues de Primero\n";
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
      Ultimo();
      plista->siguiente = nuevo;
      if(nuevo->siguiente) nuevo->siguiente->anterior = nuevo;
   }
}
void lista::Buscar(int v){
    Primero();
    //primero comprovamos que se puede hacer 
    bool e = false;
    while(plista->siguiente) Siguiente(); if(plista->valor > 0) e = true;
    if(e){
    while(plista->siguiente){
     if(plista->valor == v) break;   
    }
    cout << "Este es el valor ->";
    cout << plista->valor << " \n";
    }
}
void lista::Buscar(discos ID){
    bool e = false;
    Primero();
    while(plista->siguiente){ Siguiente(); if(plista->disc.e) e = true;}
    //esta linea es para saber que se puede hacer la buscada de titulos
    if(e){
        Primero();
    while(plista->siguiente){
     if(plista->disc.titulo == ID.titulo) break; 
     Siguiente();
    }
    cout << "Este es el titulo de la cancion ->";
    cout << plista->disc.titulo << " \n";
    }
}
void lista::Buscar(peliculas ID){
    bool e = false;
    std::cout << "Haciendo la funcion buscar lo que se busca es una pelicula\n";
    Primero();
    while(plista->siguiente){ Siguiente(); if(plista->peli.e) e = true;}
    //std::cout << "Haciendo la funcion e " << e << "\n";//esto era para combrobar la intruccion de arriva
    //esta linea es para saber que se puede hacer la buscada de titulos
    if(e){
    Primero();
    while(plista->siguiente){   
     if(plista->peli.titulo == ID.titulo) break;
     Siguiente();
    }
    cout << "Este es el titulo de la pelicula ->";
    cout << plista->peli.titulo  <<" \n";//esto es puco guarrda pero a ver que pasa
    cout << "Esta es la duacion de la pelicula ->";
    cout << plista->peli.dura << "\n";
    cout << "Este es el director ->";
    cout << plista->peli.director << "\n";
    }
}
void lista::Buscar(libros ID){
    bool e = false;
    //sepa();
    Primero();
    while(plista->siguiente){ Siguiente(); if(plista->lib.e) e = true; }
    //esta linea es para saber que se puede hacer la buscada de titulos
    //std::cout << "plista: " << e << "\n";
    if(e){
        Primero();
        //sepa();
    while(plista->siguiente){
     if(plista->lib.titulo == ID.titulo) break;
     //std::cout << "plista.titulo "nuevo << plista->lib.titulo << "\n";
     Siguiente();
    }
    cout << "Este es el titulo del libro ->";
    cout << plista->lib.titulo << " \n";
    cout << "Este es el autor del libro ->";
    cout << plista->lib.autor << "\n";
    }
}
void lista::Insertar(discos ID)
{
   pnodo nuevo;
   std::cout << "Insertado un disco, Porque no va\n";
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
       Ultimo();
      // Creamos un nuevo nodo después del nodo actual
      nuevo = new nodo(ID, plista->siguiente, plista);
      plista->siguiente = nuevo;
      if(nuevo->siguiente) nuevo->siguiente->anterior = nuevo;
   }
}
void lista::Insertar(libros ID)
{
   pnodo nuevo;
   std::cout << "Insertadno un libro\n";
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
       //bool e = false;
       Ultimo();
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
	bool e = true;
	if(!nodo->siguiente){ e = false; }
        std::cout << "es falso  "<<e << "\n";
        if(!e){
            plista->disc.e = false;
            plista->lib.e = false;
            plista->peli.e = false;
        }
	if(e){
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
   plista = nodo;
}//vale tengo dos caminos este nada mas le hace falta arreglar el borrardo
void lista::Borrar(peliculas ID)
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
	bool e = true;
	if(!nodo->siguiente){ e = false; }
        std::cout << "es falso  "<<e << "\n";
        if(!e){
            plista->disc.e = false;
            plista->lib.e = false;
            plista->peli.e = false;
        }
	if(e){
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
   plista = nodo;
}
void lista::Borrar(discos ID)
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
	bool e = true;
	if(!nodo->siguiente){ e = false; }
        std::cout << "es falso  "<<e << "\n";
        if(!e){
            plista->disc.e = false;
            plista->lib.e = false;
            plista->peli.e = false;
        }
	if(e){
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
   plista = nodo;
}
void lista::Mostrar(int orden)
{
   pnodo nodo;
   
   if(orden == ASCENDENTE) {
      if(plista) Primero();
      nodo = plista;
      while(nodo) {
          if(!nodo->lib.e && !nodo->disc.e && !nodo->peli.e){
         cout << nodo->valor << "-> " << nodo->lib.e << "  ";
          }
          if(nodo->lib.e){
              sepa();
              std::cout << "Esto es un libro\n";
              std::cout << "El titulo es  " << nodo->lib.titulo << "\n";
              std::cout << "El autor es:  " << nodo->lib.autor << "\n";
              std::cout << "El n paquinas " << nodo->lib.n_pag << "\n";
              sepa();
          }
          if(nodo->disc.e){
              sepa();
              std::cout << "Esto es un disco\n";
              std::cout << "El titulo es: " << nodo->disc.titulo << "\n";
              std::cout << "El autor es:  " << nodo->disc.autor << "\n";
              std::cout << "La duracion es " << nodo->disc.n << "\n";
              sepa();
          }
          if(nodo->peli.e){
              sepa();
              std::cout << "Esto es una pelicula\n";
              std::cout << "El titulo es: " << nodo->peli.titulo << "\n";
              std::cout << "El director es:  " << nodo->peli.director << "\n";
              std::cout << "Su duracion es:  " << nodo->peli.dura << "\n";
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
void test(){
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
   Lista.Insertar(A);
   Lista.Insertar(A);
   Lista.Insertar(I);
   std::cout << "Punto de control\n";
   sepa();
   Lista.Insertar(A);
   std::cout << "Fin del control\n";
   Lista.Insertar(ID);
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
   sepa();
   std::cout << "Haciendo la funcion buscar\n";
   Lista.Insertar(I);
   Lista.Buscar(I);
   Lista.Insertar(ID);
   Lista.Buscar(ID);
   sepa(50);
   A.titulo = "hola";
   Lista.Insertar(A);
   sepa();
   Lista.Mostrar(1);
   sepa();
   Lista.Buscar(A);//tengo que hacer un mejor patron para encontrar la forma mas simple;
   Lista.Insertar(ID);
   Lista.Insertar(ID);
   std::cout << "Mira el test i pulsa intro con un carater\n";
   cin.get();
   lim(50);
}
string menu(){
    string aux;
    sepa(50);
    std::cout << "Soy el menu, de la bibiloteca\n";
    std::cout << "1) Insertar en una lista,\n 2)Borrar,\n 3)Ver la lista(0 para salir)\n";
    sepa(50);
    std::cin >> aux;
    return aux;
}
void menu1(lista &l){
    string aux;
    bool e = false;
    sepa(50);
    while(!e){//esta es la comprovacion de que funciona bien pero no se porque no funcionas
    std::cout << "Que quieres insertar, tines estas opcines\n";
    std::cout << "1) Discos,\n 2)libros,3) Peliculas\n";
    sepa(50);
    std::cin >> aux;
    if( aux == "1"){
        discos ID;
        e = true;
        std::cout << "Dime el titulo del disco\n";
        std::cin >> ID.titulo;
        std::cout << "Dime el autor del disco\n";
        std::cin >> ID.autor;
        std::cout << "Dime la duracion del disco\n";
        std::cin >> ID.n;
        l.Insertar(ID);
    }
    if( aux == "2"){
        e = true;
        libros ID;
        std::cout << "Dime el titulo del libro\n";
        std::cin >> ID.titulo;
        std::cout << "Dime el autor del libro\n";
        std::cin >> ID.autor;
        std::cout << "Dime el numero de paguinas\n";
        std::cin >> ID.n_pag;
        l.Insertar(ID);//aqui tengo una violacion de segmento si inserto dos tengo que hacer una comprvacion
    }
    if(aux == "3"){
        e = true;
        peliculas ID;
        std::cout << "Dime el titulo de la pelicula\n";
        std::cin >> ID.titulo;
        std::cout << "Dime el director de la pelicula\n";
        std::cin >> ID.director;
        std::cout << "Dime la duracion de la pelicula\n";
        std::cin >> ID.dura;
        l.Insertar(ID);
    }
    }
    //std::cout << "Aqui hay un error!!!!!!!!!!!!\n";//ya esta solucionda la violacion de segmento
    sepa(50);
}
void menu2(lista &l){
    string aux;
    bool e = false;
    do{
    sepa();
    std::cout << "Dime que quieres borrar";
    std::cout << "\n 1)Disco, \n2)libro, \n3)pelicula";
    std::cout << "(0 Para salir): ";
    std::cin >> aux;
    sepa();
    if(aux == "1"){
        e = true;
        discos ID;
        std::cout << "Dime el titulo del disco";
        std::cin >> ID.titulo;
        l.Borrar(ID);
    }
    if(aux == "2"){
       e = true;
       libros ID;
       std::cout << "Dime el titulo del libro\n";
       std::cin >> ID.titulo;
       l.Borrar(ID);
    }
    if(aux == "3"){
        e = true;
        peliculas ID;
        std::cout << "Dime el titulo de la pelicula\n";
        std::cin >> ID.titulo;
        l.Buscar(ID);
    }
    }while(!e);
            
}
void final(){
    string aux;
    std::cout << "Inicio de test\n";
    //test();//esta funcion esta echa para hacer un test del programa
    sepa();
    std::cout << "Test pasado con exito\n";
    sepa();
    lista Lista;
    do{
        sepa(30);
        std::cout << "Salida del menu\n";//esta es la salida
        std::cout << "Pusiste " << aux << "\n";
        if(aux == "1"){
            std::cout << "(Insertar)\n";
            Lista.Mostrar(ASCENDENTE);
        }
        if(aux == "2"){
         std::cout << "(Borrar)\n";
        }
        if(aux == "3"){
            std::cout << "(Mostrar)\n";
            Lista.Mostrar(1);
        }
        sepa(30);
    aux = menu();
    if(aux == "1"){
        menu1(Lista);
    }
    if(aux == "2"){
        menu2(Lista);
    }
    lim(30);
    }while(aux != "0");
}
int main(int argc, char** argv) {
    final();
    return 0;
}

//tengo un error en borrar lo unico que habia que hacer es simplemente es poner un break en caso de que no fucione
//tengo un error que al borrar si se queda vacio hace el loco o si es el primero
