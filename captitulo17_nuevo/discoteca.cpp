#include "discoteca.hpp"
dis::disco::disco(){
    d.n = 0;
    d.nom = "0";
}
dis::disco::disco(int a, int c, string b){
    d.n = a;
    d.nom = b;
    d.dura = c;
}
void dis::disco::crear(int a, int c, string b){
 d.n = a;
 d.nom = b;
 d.dura = c;
}
void dis::disco::ver(int &a, int &c, string &b){
    a = d.n;
    b = d.nom;
    c = d.dura;
} 
dis::fiesta::fiesta(int a){
    *Pd =  new struct Dis[a];
    total[2] = a;
}