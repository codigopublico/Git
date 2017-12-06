#include "hospi.hpp"
using namespace hos;
void hos::limpia(){
    for(int i = 0; i < 2; i++){
        std::cout << "\n";
    }
}
void hos::limpia(const int &a){
    for(int i = 0; i < a; i++){
        std::cout << "\n";
    }
}
//esta es la seccion de persona
persona::persona(){
    std::cout << "Estas ejecuntado el el constructor de Persona\n";
};
persona::persona(const string &a, const int &b){
    persona::Spers.Nombre = a; 
    persona::Spers.telf = b;
    std::cout << "Constructor.....\n";
    std::cout << "Nombre   :" << persona::Spers.Nombre << "\n";
    std::cout << "telefono :" << persona::Spers.telf << "\n";
}
void persona::ver(string &a, int &b){
    a = persona::Spers.Nombre;
    b = persona::Spers.telf;
}
//esta es la seccion de profecional
profecional::profecional(){
    std::cout << "Estas ejecutando el construcotior de profecional\n";
};
profecional::profecional(const string &a, const int &b){
        std::cout << "Estas ejecutando el construcotior de profecional\n";
        persona::Spers.Nombre = a;
        persona::Spers.telf = b;
        std::cout << "Constructor.....\n";
    std::cout << "Nombre   :" << persona::Spers.Nombre << "\n";
    std::cout << "telefono :" << persona::Spers.telf << "\n";
};
profecional::profecional(const string &a, const int &b, const float &c, const int d[2]){
        std::cout << "Estas ejecutando el construcotior de profecional\n";
    persona::Spers.Nombre = a;
        persona::Spers.Nombre = b;
        profecional::Sprof.Planta = c;
        for(int i = 0; i < 2; i++){
        profecional::Sprof.horario[i] = d[i];
        }
        std::cout << "Constructor.....\n";
    std::cout << "Nombre   :" << persona::Spers.Nombre << "\n";
    std::cout << "telefono :" << persona::Spers.telf << "\n";

};
profecional profecional::operator=(const profecional &a){
    profecional res;
    res.Spers.Nombre = a.Spers.Nombre;
    res.Spers.telf = a.Spers.telf;
    res.Sprof.Planta = a.Sprof.Planta;
    res.Sprof.especialidad = a.Sprof.especialidad;
    for(int i = 0; i < 2; i++){
    res.Sprof.horario[i] = a.Sprof.horario[i];
    }
}
/*profecional* profecional::ver(){
    *Hprof->Spers.Nombre = profecional::Spers.Nombre;
    *Hprof->Spers.telf = profecional::Spers.telf;
    *Hprof->Sprof.Planta = profecional::Sprof.Planta;
    *Hprof->Sprof.especialidad  = profecional::Sprof.especialidad;
    for(int i = 0; i < 2; i++){
    *Hprof->Sprof.horario[i] = profecional::Sprof.horario[i];
    }
    return *Hprof;
}*///esto es una cajada que no sirve para nada.....

