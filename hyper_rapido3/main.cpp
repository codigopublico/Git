#include <iostream>
using namespace std;

#define ASCENDENTE 1
#define DESCENDENTE 0
void limpiar(){
    for(int i = 0; i < 10; i++){
    std::cout << "\n";
    }
}
struct libros{
    bool e;  //esta es interna i que dice si existe este objecto en la lista.
    string titulo;
    string autor;
    int n_pag;
    libros(){
        e = false;
        titulo = "0";
        autor = "0";
        n_pag = 0;
    }
};
struct peliculas{
    bool e;
    string titulo;
    string director;
    int dura; //esta es la duracion de la cancion.....
    peliculas(){
        e = false;
        titulo = "0";
        director = "0";
        dura = 0;
    }
};
struct discos{
    bool e;
    string titulo;
    string autor;
    int n; //este es para el numero de duracion;
    discos(){
        e = false;
        titulo = "0";
        autor = "0";
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
    nodo(nodo *sig = 0, nodo *ant = 0)
    {
       v = true;
       //std::cout << "Aqui esta la violacion de segmento?\n";
       siguiente = sig;
       anterior = ant;
    }
    nodo(discos ID, nodo *sig = 0, nodo *ant = 0)
    {
        anterior = ant;
        disc = ID;
        disc.e = true;
        //std::cout << "Estoy creado un disco en la lista de discos\n";
        siguiente = sig;
        v = true;
    }
    nodo(peliculas ID, nodo *sig = 0, nodo *ant = 0)
    {
        peli = ID;
        peli.e = true;
        //std::cout << "Estoy crando un disco\n";
        siguiente = sig;
        anterior = ant;
        v = true;
    }
    nodo(libros ID, nodo *sig = 0, nodo *ant = 0){
        lib = ID;
        lib.e = true;
        //std::cout << "Estoy creando un libro\n";
        siguiente = sig;
        anterior = ant;
        v = true;
    }
   private:
    bool v; // es la referencia del material;
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
    lista() : plista(NULL) {}
    ~lista();
    
    void Insertar(int v);
    void Insertar(discos ID);//teoricamente esta echo nada falta que se comprueven.
    void Insertar(peliculas ID); //teoricamente estan echos falta mirar si hay algun error
    void Insertar(libros ID); //teoricamnete ya esta
    void Borrar(int v);
    void Borrar(string Is); //este esta por hacer
    bool ListaVacia() { return plista == NULL; } 
    void Mostrar(int);
    void Mostrar();//este tambien esta por hacer
    void Siguiente();
    void Anterior();
    void Primero();
    void Ultimo();
    bool Actual() { return plista != NULL; }
    bool ValorActual() { return plista->v; }
    
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
 void lista::Insertar(discos ID){
  pnodo nuevo(ID);
  
   Primero();
   // Si la lista est� vac�a
   if(ListaVacia()) {
      // Asignamos a lista un nuevo nodo de valor v y
      // cuyo siguiente elemento es la lista actual                    
      nuevo = new nodo(plista);
      if(!plista) plista = nuevo;
      else plista->anterior = nuevo;
   }
   else {
      // Buscar el nodo de valor menor a v 
      // Avanzamos hasta el �ltimo elemento o hasta que el siguiente tenga 
      // un valor mayor que v 
      while(plista->siguiente && plista->siguiente->v) Siguiente();
      // Creamos un nuevo nodo despu�s del nodo actual
      nuevo = new nodo(plista->siguiente, plista);
      plista->siguiente = nuevo;// esta es la solucion
      if(nuevo->siguiente) nuevo->siguiente->anterior = nuevo;
   }
 }
  void lista::Insertar(peliculas ID){
  pnodo nuevo(ID);
  
   Primero();
   // Si la lista est� vac�a
   if(ListaVacia()) {
      // Asignamos a lista un nuevo nodo de valor v y
      // cuyo siguiente elemento es la lista actual                    
      nuevo = new nodo(plista);
      if(!plista) plista = nuevo;
      else plista->anterior = nuevo;
   }
   else {
      // Buscar el nodo de valor menor a v 
      // Avanzamos hasta el �ltimo elemento o hasta que el siguiente tenga 
      // un valor mayor que v 
      while(plista->siguiente && plista->siguiente->v) Siguiente();
      // Creamos un nuevo nodo despu�s del nodo actual
      nuevo = new nodo(plista->siguiente, plista);
      plista->siguiente = nuevo;// esta es la solucion
      if(nuevo->siguiente) nuevo->siguiente->anterior = nuevo;
   }
 }
 void lista::Insertar(libros ID){
 pnodo nuevo(ID);
  
   Primero();
   // Si la lista est� vac�a
   if(ListaVacia()) {
      // Asignamos a lista un nuevo nodo de valor v y
      // cuyo siguiente elemento es la lista actual                    
      nuevo = new nodo(plista);
      if(!plista) plista = nuevo;
      else plista->anterior = nuevo;
   }
   else {
      // Buscar el nodo de valor menor a v 
      // Avanzamos hasta el �ltimo elemento o hasta que el siguiente tenga 
      // un valor mayor que v 
      while(plista->siguiente && plista->siguiente->v) Siguiente();
      // Creamos un nuevo nodo despu�s del nodo actual
      nuevo = new nodo(plista->siguiente, plista);
      plista->siguiente = nuevo;// esta es la solucion
      if(nuevo->siguiente) nuevo->siguiente->anterior = nuevo;
   }
 
 }
void lista::Insertar(int v)
{
   pnodo nuevo;
 
   Primero();
   // Si la lista est� vac�a
   if(ListaVacia()) {
      // Asignamos a lista un nuevo nodo de valor v y
      // cuyo siguiente elemento es la lista actual                    
      nuevo = new nodo(plista);
      if(!plista) plista = nuevo;
      else plista->anterior = nuevo;
   }
   else {
      // Buscar el nodo de valor menor a v 
      // Avanzamos hasta el �ltimo elemento o hasta que el siguiente tenga 
      // un valor mayor que v 
      while(plista->siguiente && plista->siguiente->v) Siguiente();
      // Creamos un nuevo nodo despu�s del nodo actual
      nuevo = new nodo(plista->siguiente, plista);
      plista->siguiente = nuevo;// esta es la solucion
      if(nuevo->siguiente) nuevo->siguiente->anterior = nuevo;
   }
}


void lista::Borrar(int v)
{
   pnodo nodo;
   
   nodo = plista;
   while(nodo && nodo->v) nodo = nodo->siguiente;
   while(nodo && nodo->v) nodo = nodo->anterior;

   if(!nodo || nodo->v) return;
   // Borrar el nodo 
   
   if(nodo->anterior) // no es el primer elemento 
      nodo->anterior->siguiente = nodo->siguiente;
   if(nodo->siguiente) // no el el �ltimo nodo
      nodo->siguiente->anterior = nodo->anterior;
   delete nodo;
}

void lista::Mostrar(int orden)
{
if(orden == ASCENDENTE) {
    Primero();
     if(plista){
   do {
      //cout << nodo->valor << "-> ";
      if(plista->disc.e){
      cout << "Esto es un disco\n";
      cout << "La duracion es de  :" <<  plista->disc.n <<"  ";
      cout << "Con el titulo:  " <<  plista->disc.titulo << " ";
      cout << "Con el autor:   " << plista->disc.autor << "  ";
      cout << "\n";
      }//esto se deve hacer en todos. Para procecion cuando meta las classes virtuales.
      if(plista->peli.e){
          cout << "Esto es una pelicula\n";
      cout << "La duracion es de  :" <<  plista->peli.dura <<"  ";
      cout << "Con el titulo      :" <<  plista->peli.titulo << "  ";
      cout << "Con el director:   :" << plista->peli.director << "";
      }
      if(plista->lib.e){
      cout << "Esto es un libro\n";
      cout << "El numero de paguinas es  :" <<  plista->lib.n_pag <<"  ";
      cout << "Con el titulo:  " <<  plista->peli.titulo << "  ";
      cout << "Con el autor:   " << plista->lib.autor << "  ";
      }
      //nodo = nodo->siguiente;
      plista = plista->siguiente;//parece que va
      if(!plista) break;
   } while(!plista);
   }
  /* else {
      Ultimo();
      nodo = plista;
      while(nodo) {
         cout << nodo->v << "-> ";
         nodo = nodo->anterior;
      }
   }
   cout << endl;
}*/
}
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

int main()
{
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

   cin.get();
   return 0;
}