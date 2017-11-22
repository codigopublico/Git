#include "discoteca.hpp"
dis::disco::disco(){
    
}
dis::disco::~disco(){
    
}

dis::lugar::lugar(int p){
    dis::disco *PNdiscos = new dis::disco[p];
    *Pdiscos = &PNdiscos[0];
}