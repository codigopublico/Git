#include "discoteca.hpp"
is::disco::disco(){
    d.n = 0;
    d.nom = "0";
}
is::disco::disco(int a, int c, string b){
    d.n = a;
    d.nom = b;
    d.dura = c;
}
void is::disco::crear(int a, int c, string b){
 d.n = a;
 d.nom = b;
 d.dura = c;
}
void is::disco::ver(int &a, int &c, string &b){
    a = d.n;
    b = d.nom;
    c = d.dura;
} 
is::fiesta::fiesta(int a){
    Pd =  new is::disco::Dis[a];
    total[1] = a;
    total[0] = 0;
}
void is::fiesta::crear(int a, int c, string b){
    for(int i = 0; i < total[0]; i++){
        Pd++;
    }
    Pd->dura = c;
    Pd->nom = b;
    Pd->n = a;
    for(int i = 0; i < total[0]; i++){
        Pd--;    
    }
        total[0]++;

}
void is::fiesta::ver(int *a, int *b, string *c){
    std::cout << "La classe derivada\n";
    a = new int[total[0]];
    b = new int[total[0]];
    c = new string[total[0]];
        for(int i = 0; i < total[0]; i++){
            *a = Pd->dura;
            *c = Pd->nom;
            *b = Pd->n;
            Pd++;
        }
         for(int i = 0; i < total[0]; i++){
        Pd--;    
    }
}