/*  
 * 
 */
#include <iostream>
#include <string>
using namespace std;
struct libros{
    bool e;  //esta es interna i que dice si existe este objecto en la lista.
    string titulo;
    string autor;
    int n_pag;
};
struct peliculas{
    bool e;
    string titulo;
    string director;
    int dura; //esta es la duracion de la cancion.....
};
struct discos{
    bool e;
    string titulo;
    string autor;
    int n; //este es para el numero de canciones;
};
class material{
    virtual void insert(string, string, int) = 0;
    virtual void mostrar() = 0;
};
class nodo {
   public:
    nodo(int v, nodo *sig = 0)
    {
       valor = v;
       std::cout << "Aqui esta la violacion de segmento?\n";
       siguiente = sig;
    }
    nodo(discos ID, nodo *sig = 0)
    {
        disc = ID;
        disc.e = true;
        std::cout << "Estoy creado un disco en la lista de discos\n";
        siguiente = sig;
    }
    nodo(peliculas ID, nodo *sig = 0)
    {
        peli = ID;
        peli.e = true;
        std::cout << "Estoy crando un disco\n";
        siguiente = sig;
    }
    nodo(libros ID, nodo *sig = 0){
        lib = ID;
        lib.e = true;
        std::cout << "Estoy creando un libro\n";
        siguiente = sig;
    }
   private:
    int valor; // es la referencia del material;
    nodo *siguiente;
    discos disc;
    peliculas peli;
    libros lib;
   friend class lista;
};

typedef nodo *pnodo;

class lista {
   public:
    lista() { std::cout << "Aqui esta el error\n"; actual = NULL; std::cout << "Sigue o no \n"; }
    ~lista();
    
    void Insertar(int v);
    void Insertar(discos ID);
    void Insertar(peliculas ID);
    void Insertar(libros ID);
    void Borrar(int v);
    bool ListaVacia() { return actual == NULL; }
    void Mostrar();
    void Siguiente();
    bool Actual() { return actual != NULL; }
    int ValorActual() { return actual->valor; }
    
   private:
    pnodo actual;
};

lista::~lista()
{
    std::cout << "Llamando al destructor de universos\n";
   pnodo nodo;

   // Mientras la lista tenga más de un nodo
   while(actual->siguiente != actual) {
      // Borrar el nodo siguiente al apuntado por lista
      nodo = actual->siguiente;
      actual->siguiente = nodo->siguiente;
      delete nodo;
   }
   // Y borrar el último nodo
   delete actual;
   actual = NULL;
}

void lista::Insertar(int v)
{
   pnodo Nodo;

   // Creamos un nodo para el nuevo valor a insertar
   Nodo = new nodo(v);

   // Si la lista está vacía, la lista será el nuevo nodo
   // Si no lo está, insertamos el nuevo nodo a continuación del apuntado
   // por lista
   if(actual == NULL) actual = Nodo;
   else Nodo->siguiente = actual->siguiente;
   // En cualquier caso, cerramos la lista circular
   actual->siguiente = Nodo;
}
void lista::Insertar(discos ID){
   pnodo Nodo;

   // Creamos un nodo para el nuevo valor a insertar
   Nodo = new nodo(ID);

   // Si la lista está vacía, la lista será el nuevo nodo
   // Si no lo está, insertamos el nuevo nodo a continuación del apuntado
   // por lista
   if(actual == NULL) actual = Nodo;
   else Nodo->siguiente = actual->siguiente;
   // En cualquier caso, cerramos la lista circular
   actual->siguiente = Nodo;
}
void lista::Insertar(peliculas ID){
       pnodo Nodo;

   // Creamos un nodo para el nuevo valor a insertar
   Nodo = new nodo(ID);

   // Si la lista está vacía, la lista será el nuevo nodo
   // Si no lo está, insertamos el nuevo nodo a continuación del apuntado
   // por lista
   if(actual == NULL) actual = Nodo;
   else Nodo->siguiente = actual->siguiente;
   // En cualquier caso, cerramos la lista circular
   actual->siguiente = Nodo;
}
void lista::Insertar(libros ID){
       pnodo Nodo;

   // Creamos un nodo para el nuevo valor a insertar
   Nodo = new nodo(ID);

   // Si la lista está vacía, la lista será el nuevo nodo
   // Si no lo está, insertamos el nuevo nodo a continuación del apuntado
   // por lista
   if(actual == NULL) actual = Nodo;
   else Nodo->siguiente = actual->siguiente;
   // En cualquier caso, cerramos la lista circular
   actual->siguiente = Nodo;
}
void lista::Borrar(int v)
{
   pnodo nodo;

   nodo = actual;

   // Hacer que lista apunte al nodo anterior al de valor v
   do {
      if(actual->siguiente->valor != v) actual = actual->siguiente;
   } while(actual->siguiente->valor != v && actual != nodo);
   // Si existe un nodo con el valor v:
   if(actual->siguiente->valor == v) {
      // Y si la lista sólo tiene un nodo
      if(actual == actual->siguiente) {
         // Borrar toda la lista
         delete actual;
         actual = NULL;
      }
      else {
         // Si la lista tiene más de un nodo, borrar el nodo  de valor v
         nodo = actual->siguiente;
         actual->siguiente = nodo->siguiente;
         delete nodo;
      }
   }
}

void lista::Mostrar()
{
   pnodo nodo = actual;
   int n = 0;
   do {
       std::cout << "Este es un nodo :"<< n <<"\n";
      cout << nodo->valor << "-> ";
      if(nodo->disc.e){
          cout << "Esto es un disco\n";
      cout << nodo->disc.n << "  ";
      }//esto se deve hacer en todos. Para procecion cuando meta las classes virtuales.
      nodo = nodo->siguiente;
   } while(nodo != actual);

   cout << endl;
}

void lista::Siguiente()
{
   if(actual) actual = actual->siguiente;
}

void final(){
    discos ID;
    ID.autor = "0";
    ID.n = 10000000;
    ID.titulo = "0";
    lista Lista;//vale faltava esto.....
    Lista.Insertar(10);
    Lista.Insertar(ID);
    Lista.Mostrar();
    std::cout << "Acabado de mostrar\n";
}
int main(int argc, char** argv) {
    final();
    return 0;
}

