#include "discoteca.hpp"
dis::disco::disco(){
    d.dura = 0;
    d.n = 0;
    d.titulo = "0";
    d.autor = "0";
}
dis::disco::~disco(){
    
}
dis::disco::operator =(disco& disc){
    disc.d.dura = d.dura;
    disc.d.n = d.n;
    disc.d.autor = d.autor;
    disc.d.titulo = d.titulo;
}
dis::lugar::lugar(int p){
    dis::disco *PNdiscos = new dis::disco[p];
    **Pdiscos = &PNdiscos[0];
}
dis::lugar::lugar(){
    dis::disco *PNdiscos = new dis::disco[300];
    **Pdiscos = &PNdiscos[0];
}
dis::lugar::~lugar(){
    delete *Pdiscos;
}