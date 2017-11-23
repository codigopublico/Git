#include "discoteca.hpp"
dis::disco::disco(){
    d.n = 0;
    d.nom = "0";
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
dis::disco dis::disco::operator =(dis::disco& a){
    a.d = d;
    
}
dis::fiesta::fiesta(int a){
    
    disc = new dis::disco[a];
    total[0] = a;
}
void dis::fiesta::crear(int a, int b, string c){
    disc->crear(a, b, c);
    //*disc++;
}
void dis::fiesta::ver(int &a, int &b, string &c){
    disc->ver(a, b, c);
}