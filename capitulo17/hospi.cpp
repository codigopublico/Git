#include "hospi.hpp"
dis::Bdisco::Bdisco(){
    std::cout << "Estas ejecutado el constructor de disco\n";
}
dis::Bdisco::Bdisco(int &a, string &b, string &d){
    //aqui se a de crear un constructor de copias del principio
}
dis::Bdisco::~Bdisco(){
    std::cout << "Estas ejecutado el destructor\n";
}
dis::lista::lista(int n){
    for(int i = 0; i < n; i++){
     Disco = new Ddisco[i];  //aqui esta el error me cago en todo  
    }
    total[0] = n;
    total[1] = 0;
}
dis::lista::lista(){
    std::cout << "Creando una lista vacia\n";
    Disco = new Ddisco[10]; 
}
//Redefinicion de las funciones virtuales
dis::Bdisco::Ddisco* dis::lista::get(){
    return *Disco;
}
void dis::lista::put(Ddisco &a){
    for(int i = 0; i < total[1]; i++){
        *Disco++;
    }
    Disco->autor = a.autor;
    Disco->dura = a.dura;
    Disco->n = a.n;
    Disco->nivel = a.nivel;
    Disco->single = a.single;
    Disco->titulo = a.titulo;
    for(int i = 0; i < total[1]; i++){
        *Disco--;
    }
}