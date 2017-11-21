#include "hospital.hpp"
hospi::persona::persona(){
    per.nombre = "0";
    per.telefono = 0;
}
hospi::persona::persona(string IN, int I){
    per.nombre = IN;
    per.telefono = I;
}


hospi::enfermero::enfermero(){
    nomesp = "Enfermero";
    enf.Esp = 0;
    enf.h = 0;
    enf.n = 0;
}
hospi::enfermero::enfermero(int n, int n1, int n3){
    nomesp = "Enfermero";
    if(n > maxesp){//esto lo tengo que mejorar para ello lo que hara es ...
        enf.Esp =  maxesp;
    }else{
        enf.Esp = n;
    }
    enf.h = n1;
    enf.n = n3;
}


hospi::limpieza::limpieza(){
    nomesp = "Limpiador";
    limp.Esp = 0;
    limp.h = 0;
    limp.n = 0;
}
hospi::limpieza::limpieza(int n, int n1, int n2){
    nomesp = "Limpiador";
    limp.Esp = n;
    limp.h = n1;
    limp.n = n2;
}
hospi::medicos::medicos(){
    nomesp = "Medico";
    medi.Esp = 0;
    medi.h = 0;
    medi.n = 0;
}
hospi::medicos::medicos(int n, int n1, int n2){
    nomesp = "Medico";
    medi.Esp = n;
    medi.h = n1;
    medi.n = n2;
}
hospi::hosipta::hospita(int ip){
    p = ip;
    persona* personal = new persona[p];
    *Ppers = &persona[0]; //esto es un poco raro.
}
hospi::hosipta::alta(int n, int n1, string nom){
    if(n == 0){
        Ppers = new medicos;
    }
    if(n == 1){
        Ppers = new limpieza;
    }
    if(n == 2){
        Ppers = new enfermero;
    }
    Ppers->per.nombre = nom;
    //como es que no tengo la hacer es lo del polimorfismo..
}