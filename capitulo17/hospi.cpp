#include "hospi.hpp"
dis::Bdisco::Bdisco(){
    std::cout << "Estas ejecutado el constructor de disco\n";
}
dis::Bdisco::Bdisco(int &a, string &b, string &d){
    Ddi.dura = a;
    Ddi.titulo = b;
    Ddi.autor = d;
}
dis::Bdisco::~Bdisco(){
    std::cout << "Estas ejecutado el destructor\n";
}
dis::lista::lista(int n){
    for(int i = 0; i < n; i++){
     *Disco = new Ddisco[i];  //aqui esta el error me cago en todo  
    }
}