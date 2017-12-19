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
    int n; //este es para el numero de duracion;
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
    nodo(int v, nodo *sig = 0)
    {
       valor = v;
       //std::cout << "Aqui esta la violacion de segmento?\n";
       siguiente = sig;
    }
    nodo(discos ID, nodo *sig = 0)
    {
        disc = ID;
        disc.e = true;
        //std::cout << "Estoy creado un disco en la lista de discos\n";
        siguiente = sig;
    }
    nodo(peliculas ID, nodo *sig = 0)
    {
        peli = ID;
        peli.e = true;
        //std::cout << "Estoy crando un disco\n";
        siguiente = sig;
    }
    nodo(libros ID, nodo *sig = 0){
        lib = ID;
        lib.e = true;
        //std::cout << "Estoy creando un libro\n";
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
    lista() { //std::cout << "Aqui esta el error\n"; 
     actual = NULL; 
     //std::cout << "Sigue o no \n"; 
    }
    ~lista();
    
    void Insertar(int v);
    void Insertar(discos ID);
    void Insertar(peliculas ID);
    void Insertar(libros ID);
    void Borrar(int v);
    void Borrar(string IT, int n);
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
    //std::cout << "Llamando al destructor de universos\n";
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
void lista::Borrar(string IT, int n){
        pnodo nodo;
//la lista comprovara que se ingreso que tipo de dato se deve borrar si es 
        //1 es un disco 
        //2 peli
        //3 libro
   nodo = actual;

   // Hacer que lista apunte al nodo anterior al de valor v
   if(n == 1){
   do {
      if(actual->siguiente->disc.titulo != IT) actual = actual->siguiente;
   } while(actual->siguiente->disc.titulo != IT && actual != nodo);
   // Si existe un nodo con el valor v:
   if(actual->siguiente->disc.titulo == IT) {
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
   if(n == 2){
       do {
      if(actual->siguiente->peli.titulo != IT) actual = actual->siguiente;
   } while(actual->siguiente->peli.titulo != IT && actual != nodo);
   // Si existe un nodo con el valor v:
   if(actual->siguiente->peli.titulo == IT) {
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
   if(n == 3){
   do {
      if(actual->siguiente->peli.titulo != IT) actual = actual->siguiente;
   } while(actual->siguiente->peli.titulo != IT && actual != nodo);
   // Si existe un nodo con el valor v:
   if(actual->siguiente->peli.titulo == IT) {
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
}
void lista::Mostrar()
{
   pnodo nodo = actual;
   int n = 0;
   do {
      cout << nodo->valor << "-> ";
      if(nodo->disc.e){
      cout << "Esto es un disco\n";
      cout << "La duracion es de  :" <<  nodo->disc.n <<"\n";
      cout << "Con el titulo:  " <<  nodo->disc.titulo << "\n";
      cout << "Con el autor:   " << nodo->disc.autor << "\n";
      cout << "\n";
      }//esto se deve hacer en todos. Para procecion cuando meta las classes virtuales.
      if(nodo->peli.e){
          cout << "Esto es una pelicula\n";
      cout << "La duracion es de  :" <<  nodo->peli.dura <<"\n";
      cout << "Con el titulo      :" <<  nodo->peli.titulo << "\n";
      cout << "Con el director:   :" << nodo->peli.director << "\n";
      }
      if(nodo->lib.e){
      cout << "Esto es un libro\n";
      cout << "El numero de paguinas es  :" <<  nodo->lib.n_pag <<"\n";
      cout << "Con el titulo:  " <<  nodo->peli.titulo << "\n";
      cout << "Con el autor:   " << nodo->lib.autor << "\n";
      }
      else{
                std::cout << "Este es un nodo :"<< nodo->valor <<"\n";
      }
      nodo = nodo->siguiente;
   } while(nodo != actual);

   cout << endl;
}

void lista::Siguiente()
{
   if(actual) actual = actual->siguiente;
}
lista PUlist;
//esta es la classe de disco voy a hacer las otras.
class Cdisco : public material{
public:
    //Cdisco() :: material { }//si tengo tiempo hare que gestione la lista pero da igual. me cago en las vtabbles. Aisalre el problema i lo escribire en otro programa.
    void insert(string, string, int);
    void mostrar();
    void eliminar(string);//esta funcion sera para los que se crean por new.
    //si se llama al destructor se eliminaran por alli. Pero creo que no hara falta.
};
void Cdisco::insert(string IA, string IT, int n){
    discos ID;
    ID.autor = IA;
    ID.titulo = IT;
    ID.n = n;
    PUlist.Insertar(ID);
}
void Cdisco::mostrar(){
    PUlist.Mostrar();
}
void Cdisco::eliminar(string It){
    PUlist.Borrar(It, 1);
}
//este es para las peilis
class pelis : public material {
public:
    void insert(string, string, int);
    void mostrar();
    void eliminar(string);
}; 
void pelis::insert(string IA, string IT, int n){
    peliculas ID;
    ID.titulo = IA;
    ID.director = IT;
    ID.dura = n;
    PUlist.Insertar(ID);
}
void pelis::eliminar(string IA){
    PUlist.Borrar(IA, 2);
}
void pelis::mostrar(){
    PUlist.Mostrar();
}
class libro : public material {
public:
    void insert(string, string, int);
    void mostrar();
    void eliminar(string);
};
void libro::insert(string Ia, string It, int n){
    libros ID;
    ID.autor = Ia;
    ID.titulo = It;
    ID.n_pag = n;
    PUlist.Insertar(ID);
}
void libro::mostrar(){
    PUlist.Mostrar();
}
void libro::eliminar(string IA){
    PUlist.Borrar(IA, 3);
}
void final(){
    std::cout << "Inicio de final \n";
    Cdisco nuevo;
    nuevo.insert("a", "a", 666);
    libro viejo;
    pelis hola;
    hola.insert("Mundo feliz", "19", 90);
    viejo.insert("1984", "Orwell", 999);//Aqui falla orwell
    //std::cout << "Adiso \n";
    discos ID;
    ID.autor = "0";
    ID.n = 10000000;
    ID.titulo = "0";
    PUlist.Insertar(10);
    PUlist.Insertar(ID);
    PUlist.Mostrar();
    std::cout << "Replica de polimorfismo\n";
    nuevo.mostrar();
    nuevo.eliminar("a");
    std::cout << "Despues de borrar\n";
    nuevo.mostrar();
    std::cout << "Acabado de mostrar\n";//falta  un menu() pero primero se haran las estructuras
}
int main(int argc, char** argv) {
    final();
    return 0;
}