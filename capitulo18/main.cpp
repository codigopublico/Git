/*  
 * 
 */
#include <iostream>
#include <string>
using namespace std;
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
    void Mostrar(int n);
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
   if(nodo){
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
   }else {
       std::cout << "No hay nada que borrar\n";
   }
}
void lista::Mostrar()
{
   pnodo nodo = actual;
   int n = 0;
   if(nodo){
   do {
      cout << nodo->valor << "-> ";
      if(nodo->disc.e){
      cout << "Esto es un disco\n";
      cout << "La duracion es de  :" <<  nodo->disc.n <<"  ";
      cout << "Con el titulo:  " <<  nodo->disc.titulo << " ";
      cout << "Con el autor:   " << nodo->disc.autor << "  ";
      cout << "\n";
      }//esto se deve hacer en todos. Para procecion cuando meta las classes virtuales.
      if(nodo->peli.e){
          cout << "Esto es una pelicula\n";
      cout << "La duracion es de  :" <<  nodo->peli.dura <<"  ";
      cout << "Con el titulo      :" <<  nodo->peli.titulo << "  ";
      cout << "Con el director:   :" << nodo->peli.director << "";
      }
      if(nodo->lib.e){
      cout << "Esto es un libro\n";
      cout << "El numero de paguinas es  :" <<  nodo->lib.n_pag <<"  ";
      cout << "Con el titulo:  " <<  nodo->peli.titulo << "  ";
      cout << "Con el autor:   " << nodo->lib.autor << "  ";
      }
      
      nodo = nodo->siguiente;
   } while(nodo != actual);
   }
   cout << endl;
}
void lista::Mostrar(int n){
    pnodo nodo = actual;
   //sint n = 0;
   if(nodo){
   do {
       if(n == 1){
      cout << nodo->valor << "-> ";
      if(nodo->disc.e){
      cout << "Esto es un disco\n";
      cout << "La duracion es de  :" <<  nodo->disc.n <<"  ";
      cout << "Con el titulo:  " <<  nodo->disc.titulo << " ";
      cout << "Con el autor:   " << nodo->disc.autor << "  ";
      cout << "\n";
      }//esto se deve hacer en todos. Para procecion cuando meta las classes virtuales.
       }
       if(n == 2){
      if(nodo->peli.e){
          cout << "Esto es una pelicula\n";
      cout << "La duracion es de  :" <<  nodo->peli.dura <<"  ";
      cout << "Con el titulo      :" <<  nodo->peli.titulo << "  ";
      cout << "Con el director:   :" << nodo->peli.director << "";
      }
       }
       if(n == 3){
      if(nodo->lib.e){
      cout << "Esto es un libro\n";
      cout << "El numero de paguinas es  :" <<  nodo->lib.n_pag <<"  ";
      cout << "Con el titulo:  " <<  nodo->peli.titulo << "  ";
      cout << "Con el autor:   " << nodo->lib.autor << "  ";
      }
       }
      nodo = nodo->siguiente;
   } while(nodo != actual);
   }
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
void menu1(){
    string aux;
    int n;
    do{
        limpiar();
        if(aux == "3"){
            if(n == 0){
            PUlist.Mostrar();
            }else{
                PUlist.Mostrar(n);
            }
        }
    std::cout << "Iniciando el menu\n";
    std::cout << "1) Para incertar\n, 2) Para borrar\n, 3)Para ver\n ";
    std::cin >> aux;
    if(aux == "1"){
        int n;
        std::cout << "Dime si es 1)disco\n, 2)una pelicula\n, 3)libro\n";
        std::cin >> n;
        if(n == 1){
            discos ID;
            std::cout << "Dime el titulo\n";
            std::cin >> ID.titulo;
            std::cout << "Dime el autor\n";
            std::cin >> ID.autor;
            std::cout << "Dime la duracion\n";
            std::cin >> ID.n;
            PUlist.Insertar(ID);
        }
        if(n == 2){
            pelis ID;
            string aux2;
            string aux3;
            std::cout << "Dime el titulo\n";
            std::cin >> aux2;
            std::cout << "Dime el autor\n";
            std::cin >>  aux3;
            std::cout << "Dime la duracion\n";
            std::cin >> n;
            ID.insert(aux2, aux3, n);
            //PUlist.Insertar(ID);
        }
        if(n == 3){
            libros ID;
            std::cout << "Dime el titulo\n";
            std::cin >> ID.titulo;
            std::cout << "Dime el autor\n";
            std::cin >> ID.autor;
            std::cout << "Dime la duracion\n";
            std::cin >> ID.n_pag;
            PUlist.Insertar(ID);
        }
    }
    if(aux == "2"){
        PUlist.Mostrar();
        int n;
        string aux;
        std::cout << "Dime si es 1)disco\n, 2)una pelicula\n, 3)libro\n";
        std::cin >> n;
        std::cout << "Dime el titulo\n";
        std::cin >> aux;
        PUlist.Borrar(aux, n);
    }
    if(aux == "3"){
        //1 es un disco
    //2 es un libro
    //3 es una pelicula
        std::cout << "Dime que quieres ver\n";
        std::cout << "1) disco\n, 2) Un libro\n, 3) Una pelicula(0 todo)\n";
        std::cin >> n;
    }
    }while(aux != "0");
}

int main(int argc, char** argv) {
    //final();
    menu1();
    return 0;
}