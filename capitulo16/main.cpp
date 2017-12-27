/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 24 de diciembre de 2017, 7:13
 */

#include <cstdlib>
#include <iostream>//nose que le pasa pero funciona
#include <string>
using namespace std;

/*
 *  Este es una replica rapida de capitulo16 Implentar todo con fuciones virtuales
 */
void limpiar(){
    for(int i = 0; i < 100; i++){
        std::cout << "\n";
    }
}
struct Denfermera{
    bool e; //este es para saber si esta activo.....
    int Planta;
    string especial;//esta es para la especialidad;
    int H[2];//esta es para el horario;
};
struct Dlimpieza{
    bool e;
    int Planta;
    string especial;//esta es para la especialidad;
    int H[2];//esta es para el horario;
};
struct Dmedico{
    bool e;
    int Planta;
    string especial;//esta es para la especialidad;
    int H[2];//esta es para el horario;
};
struct datos{
    bool e;
    int telf;
    string nombre;
    struct Dmedico DAmedico;
    struct Dlimpieza DAlimpieza;
    struct Denfermera DAenfermera;
};
class persona{
public:
    datos Dpers;
    persona();
    persona(int Itel, string Inom);
    void Insertar(int Itel, string Inom);
    virtual void Ins(datos &D);
    virtual void Mos();
};
persona::persona(){
    Dpers.e = false;
}
persona::persona(int Itel, string Inom){
    Dpers.e = true;
    Dpers.nombre = Inom;
    Dpers.nombre = Itel;
}
void persona::Ins(datos& D){
    Dpers.e = true;
    Dpers.nombre = D.nombre;
    Dpers.telf = D.telf;
}
void persona::Insertar(int Itel, string Inom){
    Dpers.e = true;
    Dpers.nombre = Inom;
    Dpers.telf = Itel;
}
void persona::Mos(){
    std::cout << "Esto es una persona\n";
}
class medico : virtual public persona{
public:
    medico();
    medico(int Itel, string Inom, int Ipla, string Iesp, int H[2]);
    void InsPorf(int Itel, string Inom, int Ipla, string Iesp, int H[2]);
    void Ins(datos& D);
    void Mos();
};
void medico::Mos(){
    std::cout << "Hola soy un medico\n";
    std::cout << "Mis datos son: ";
    std::cout << "Nombre :" << Dpers.nombre << "\n";
    std::cout << "Telf   :" << Dpers.telf << "\n";
    std::cout << "Mi especialidad :" << Dpers.DAmedico.especial << "\n";
    std::cout << "Estoy en la planta :" << Dpers.DAmedico.Planta << "\n";
    std::cout << "I tengo el hoario\n";
    for(int i = 0; i < 2; i++){
        std::cout << Dpers.DAmedico.H[i];
        if( i != 1){
        std::cout << " a ";
        }
    }
    std::cout << "\n";
}
medico::medico(){
    Dpers.e = false;
}
void medico::Ins(datos& D){
        Dpers.e = true;
        Dpers.nombre = D.nombre;
        Dpers.telf = D.telf;
        Dpers.DAmedico.e = true;
        Dpers.DAmedico.especial = D.DAmedico.especial;
        Dpers.DAmedico.Planta = D.DAmedico.Planta;
        for(int i = 0; i < 2; i++){
            Dpers.DAmedico.H[i] = Dpers.DAmedico.H[i];
        }
}
medico::medico(int Itel, string Inom, int Ipla, string Iesp, int H[2]){
    Dpers.e = true;
    Dpers.nombre = Inom;
    Dpers.telf = Itel;
    Dpers.DAmedico.e = true;
    Dpers.DAmedico.Planta = Ipla;
    Dpers.DAmedico.especial = Iesp;
    for(int i = 0; i < 2; i++){
    Dpers.DAmedico.H[i] = H[i];
    }
}
class enfermero : virtual public persona{
public:
    enfermero();
    enfermero(int Itel, string Inom, int Ipla, string Iesp, int H[2]);
    void InsPorf(int Itel, string Inom, int Ipla, string Iesp, int H[2]);
    void Ins(datos& D);
    void Mos();
};
void enfermero::Ins(datos& D){
        Dpers.e = true;
        Dpers.nombre = D.nombre;
        Dpers.telf = D.telf;
        Dpers.DAenfermera.e = true;
        Dpers.DAenfermera.especial = D.DAenfermera.especial;
        Dpers.DAenfermera.Planta = D.DAenfermera.Planta;
        for(int i = 0; i < 2; i++){
            Dpers.DAenfermera.H[i] = D.DAenfermera.H[i];
        }
}
enfermero::enfermero(){
    Dpers.e = false;
}
enfermero::enfermero(int Itel, string Inom, int Ipla, string Iesp, int H[2]){
    Dpers.e = true;
        Dpers.nombre = Inom;
        Dpers.telf = Itel;
        Dpers.DAenfermera.e = true;
        Dpers.DAenfermera.especial = Iesp;
        Dpers.DAenfermera.Planta = Ipla;
        for(int i = 0; i < 2; i++){
            Dpers.DAenfermera.H[i] = H[i];
        }
}
void enfermero::Mos(){
    std::cout << "Hola soy una enfermera\n";
    std::cout << "Mis datos son: ";
    std::cout << "Nombre :" << Dpers.nombre << "\n";
    std::cout << "Telf   :" << Dpers.telf << "\n";
    std::cout << "Mi especialidad :" << Dpers.DAmedico.especial << "\n";
    std::cout << "Estoy en la planta :" << Dpers.DAmedico.Planta << "\n";
    std::cout << "I tengo el hoario\n";
    for(int i = 0; i < 2; i++){
        std::cout << Dpers.DAmedico.H[i];
        if( i != 1){
        std::cout << " a ";
        }
    }
    std::cout << "\n";
}
void enfermero::InsPorf(int Itel, string Inom, int Ipla, string Iesp, int H[2]){
        Dpers.e = true;
        Dpers.nombre = Inom;
        Dpers.telf = Itel;
        Dpers.DAenfermera.e = true;
        Dpers.DAenfermera.especial = Iesp;
        Dpers.DAenfermera.Planta = Ipla;
        for(int i = 0; i < 2; i++){
            Dpers.DAenfermera.H[i] = H[i];
        }//esta esta mal escrita ya que pone en tela que tine que ser una enfermera.
}
class limpieza : virtual public persona{
public:
    limpieza();
    limpieza(int Itel, string Inom, int Ipla, string Iesp, int H[2]);
    void InsPorf(int Itel, string Inom, int Ipla, string Iesp, int H[2]);
    void Ins(datos& D);
    void Mos();
};
limpieza::limpieza(){
    Dpers.e = false;
};
limpieza::limpieza(int Itel, string Inom, int Ipla, string Iesp, int H[2]){
        Dpers.e = true;
        Dpers.nombre = Inom;
        Dpers.telf = Itel;
        Dpers.DAlimpieza.e = true;
        Dpers.DAlimpieza.especial = Iesp;
        Dpers.DAlimpieza.Planta = Ipla;
        for(int i = 0; i < 2; i++){
            Dpers.DAlimpieza.H[i] = H[i];
        }   
}
void limpieza::InsPorf(int Itel, string Inom, int Ipla, string Iesp, int H[2]){
        Dpers.e = true;
        Dpers.nombre = Inom;
        Dpers.telf = Itel;
        Dpers.DAlimpieza.e = true;
        Dpers.DAlimpieza.especial = Iesp;
        Dpers.DAlimpieza.Planta = Ipla;
        for(int i = 0; i < 2; i++){
            Dpers.DAlimpieza.H[i] = H[i];
        }
}

void limpieza::Ins(datos &D){
        Dpers.e = true;
        Dpers.nombre = D.nombre;
        Dpers.telf = D.telf;
        Dpers.DAlimpieza.e = true;
        Dpers.DAlimpieza.especial = D.DAlimpieza.especial;
        Dpers.DAlimpieza.Planta = D.DAlimpieza.Planta;
        for(int i = 0; i < 2; i++){
            Dpers.DAlimpieza.H[i] = D.DAlimpieza.H[i];
        }
}
void limpieza::Mos(){
    std::cout << "Hola soy una limpiadora\n";
    std::cout << "Mis datos son: ";
    std::cout << "Nombre :" << Dpers.nombre << "\n";
    std::cout << "Telf   :" << Dpers.telf << "\n";
    std::cout << "Mi especialidad :" << Dpers.DAmedico.especial << "\n";
    std::cout << "Estoy en la planta :" << Dpers.DAmedico.Planta << "\n";
    std::cout << "I tengo el hoario\n";
    for(int i = 0; i < 2; i++){
        std::cout << Dpers.DAmedico.H[i];
        if( i != 1){
        std::cout << " a ";
        }
    }
    std::cout << "\n";
}
class hospital : public medico{
public:
     persona *Ppersona[200];
public:
    hospital();
    void InsMedico(datos& D);
    void InsEnfermera(datos& D);
    void Inslimpiadora(datos& D);
    void InsPorf(datos& D);
    void Mos();
    void Mos(int n);//esta sobrecarga sirve para mostrar solo los que concidan con esta planta.
    void elimanar(string nom);
private:
    void orden();
};
hospital::hospital(){
    //aqui molaria hacer que se pudiera reducir el array pero me temo que para eso hace falta las listas
    //la cosa se puede hacer una referncia un puntero no se puede
    //persona *Ppersona[10];//De momento se hara estatico i se dira que cada
    for(int i = 0; i < 200; i++){
    Ppersona[i] = new persona;//aqui esta el punto de partida de todo
    }
}
void hospital::InsPorf(datos& D){
    if(D.DAenfermera.e){
        std::cout << "Printeadndo la funcion enfermera\n";
        hospital::InsEnfermera(D);
    }
    if(D.DAmedico.e){
        std::cout << "Prineteando la funcion medico\n";
        hospital::InsMedico(D);
    }
    if(D.DAlimpieza.e){
        std::cout << "Printeando la funcion limpieza\n";
        hospital::Inslimpiadora(D);
    }
}
void hospital::Inslimpiadora(datos& D){
    bool aux = false;
    if(!Ppersona[0]->Dpers.e){
    Ppersona[0] = new limpieza;
    Ppersona[0]->Ins(D);
    }else{
        for(int i = 0; i < 200; i++){
            if(!Ppersona[i]->Dpers.e){
            Ppersona[i] = new limpieza;
            Ppersona[i]->Ins(D);
            aux = true;
            }
            if(aux) break;
        }
    }
}
void hospital::InsMedico(datos& D){
    bool aux = false;
    if(!Ppersona[0]->Dpers.e){
    Ppersona[0] = new medico;
    Ppersona[0]->Ins(D);
    }else{
        for(int i = 0; i < 200; i++){
            if(!Ppersona[i]->Dpers.e){
            Ppersona[i] = new medico;
            Ppersona[i]->Ins(D);
            aux = true;
            }
            if(aux) break;
        }
    }
}
void hospital::InsEnfermera(datos& D){
    bool aux = false;
    if(!Ppersona[0]->Dpers.e){
    Ppersona[0] = new enfermero;
    Ppersona[0]->Ins(D);
    }else{
        for(int i = 0; i < 200; i++){
            if(!Ppersona[i]->Dpers.e){
            Ppersona[i] = new enfermero;
            Ppersona[i]->Ins(D);
            aux = true;
            }
            if(aux) break;
        }
    }
}
void hospital::Mos(){
   // Ppersona[1]->Mos();
    if(!Ppersona[0]->Dpers.e){
        std::cout << "No hay ningua persona en el hospital\n";
    }else{
        for(int i = 0; i < 199; i++){//Lo unico que pasava es que estava a 200 cuando es es 200-1
            if(Ppersona[i]->Dpers.e){//aqui hay un porque no funciona ya esta
                Ppersona[i]->Mos();
            }
        }
    }
    std::cout << "Finalizando la funcion Mostrar\n";
}
void hospital::Mos(int n){
    if(!Ppersona[0]->Dpers.e){
        std::cout << "No hay ningua persona en el hospital\n";
    }else{
        for(int i = 0; i < 199; i++){//Lo unico que pasava es que estava a 200 cuando es es 200-1
            if(Ppersona[i]->Dpers.e){//aqui hay un porque no funciona ya esta
                if(Ppersona[i]->Dpers.DAmedico.Planta == n){
                Ppersona[i]->Mos();
                }
                if(Ppersona[i]->Dpers.DAenfermera.Planta == n){
                    Ppersona[i]->Mos();
                }
                if(Ppersona[i]->Dpers.DAlimpieza.Planta == n){
                    Ppersona[i]->Mos();
                }
            }
        }
    }
    std::cout << "Finalizando la funcion Mostrar\n";
}
void hospital::elimanar(string nom){
    std::cout << "Se hace la funcion eliminar\n";
    if(!Ppersona[0]->Dpers.e){
        std::cout << "No hay ningua persona en el hospital\n";
    }else{
        persona *Paux[200];
        for(int i = 0; i < 200; i++){
            Paux[i] = Ppersona[i];
            //lo que hacer es hacer un grupo de personas auxilar i lo coparie todo alli.
            if(Ppersona[i]->Dpers.nombre == nom){//aqui hay un porque no funciona
               /*free(Ppersona[i]);//la cuestion es como pongo que ste haga eliminar el puntero.... i Como gestino ese error tengo que documentarme
                persona *Ppersona[i];
                Ppersona[i] = new persona(); //esto me tengo que mirar con calma 
                Ppersona[i]->Dpers.e = false;
                */
                Paux[i] = new persona;
            }
        }
        //delete *Ppersona;
        //persona *Ppersona[200];
        for(int i = 0; i < 200; i++){
                Ppersona[i] = Paux[i];//aqui esta el punto de partida de todo
        }
        //free(Paux);
    }
    std::cout << "Antes de hacer ir la funcion orden\n";
    hospital::orden();
    std::cout << "Se termina la funcion eliminar\n";
}
void hospital::orden(){
    //replica todo porque lo hace
    persona *aux;
    std::cout << "Haciendo la funcion de orden\n";
        for(int i = 0; i < 200; i++){
            if(!Ppersona[i]->Dpers.e){//aqui hay un porque no funciona
                aux = Ppersona[i + 1];
                Ppersona[i + 1] = Ppersona[i];
                Ppersona[i] = aux;
            }
        }
    std::cout << "Esta es la persona(borrado)    :" << Ppersona[1]->Dpers.nombre << "\n";
    std::cout << "Finalizando la funcion de orden\n";
}
datos Menu_datos(){
    datos D;
    string aux;
    std::cout << "Dime el nombre de la persona que quieres poner\n";
    std::cin >> D.nombre;
    std::cout << "Dime el telefono que quieres poner\n";
    std::cin >> D.telf;
    std::cout << "Cual es su profecion\n";
    std::cout << "Medica(0), Enfermera(1), limpiadora(2) ::";
    std:cin >> aux;
    if(aux == "0"){
        D.DAmedico.e = true;
        D.DAlimpieza.e = false;
        D.DAenfermera.e = false;
    }
    if(aux == "1"){
        D.DAenfermera.e = true;
        D.DAmedico.e = false;
        D.DAlimpieza.e = false;
    }
    if(aux == "2"){
        D.DAlimpieza.e = true;
        D.DAenfermera.e = false;
        D.DAmedico.e = false;
    }
    std::cout << "Dime su especialidad\n";
    if(aux == "0"){
        std::cin >> D.DAmedico.especial;
    }
    if(aux == "1"){
        std::cin >> D.DAenfermera.especial;
    }
    if(aux == "2"){
        std::cin >> D.DAlimpieza.especial;
    }
    std::cout << "Dime su horario\n";
    for(int i = 0; i < 2; i++){
    if(aux == "0"){
        std::cin >>D.DAmedico.H[i];
    }
    if(aux == "1"){
        std::cin >> D.DAenfermera.H[i];
    }
    if(aux == "2"){
        std::cin >> D.DAlimpieza.H[i];
    }
    std::cout << " De ";
    }
    std::cout << "Dime a que planta \n ";
    if(aux == "0"){
        std::cin >> D.DAmedico.Planta;
    }
    if(aux == "1"){
        std::cin >> D.DAenfermera.Planta;
    }
    if(aux == "2"){
        std::cin >> D.DAlimpieza.Planta;
    }
    return D;
}
void test(){
     std::cout << "Hola \n";
    datos In;
    In.nombre = "Cris";
    hospital Stcris;
    Stcris.InsMedico(In);
    In.nombre = "Esmeralda";
    Stcris.InsEnfermera(In);
    In.nombre = "PiterPan";
    In.DAlimpieza.e = true;
    In.DAenfermera.e = false;
    In.DAmedico.e = false;
    Stcris.InsPorf(In);
    std::cout << Stcris.Ppersona[0]->Dpers.nombre << "\n";
    In.nombre = "Olga";
    Stcris.InsMedico(In);
    std::cout << Stcris.Ppersona[1]->Dpers.nombre << "\n";
    std::cout << Stcris.Ppersona[10]->Dpers.nombre << "\n";
    Stcris.Mos();
    std::cout << "Aqui se encalla\n";
    for(int i = 0; i < 3; i++){
        std::cout << "\n";
    }
    std::cout << "Mostrando los nombres\n";
    Stcris.elimanar("Cris");
    std::cout << "Mostrando los nombres\n\n\n";
    Stcris.Mos();
    std::cout << "Mostrando los nombres por planta\n";
    limpiar();
    Stcris.Mos(0);
    std::cout << "Fin\n";
}

void menu(){
    string aux;
    hospital Stcris;
    do{
        std::cout << "Hola al menu\n";
        std::cout << "1) Para Inscribir un profecional\n2)Borrar persona\n3)Mostrar\n4)Mostrar una planta(0 para salir)   ::";
        std::cin >> aux;
        limpiar();
        if(aux == "1" ){
            datos D;
            D = Menu_datos();
            Stcris.InsPorf(D);
        }
        if(aux == "2"){
            std::cout << "Dime el nombre  que quieres eliminar\n";
            std::cin >> aux;
            Stcris.elimanar(aux);
        }
        if(aux == "3"){
            Stcris.Mos();
        }
        if(aux == "4"){
            int n;
            std::cout << "Dime en que planta quieres mostrar\n";
            std::cin >> n;
            Stcris.Mos(n);
        }
                
    }while(aux != "0");
}
//nada mas falta poner la funcion de estar.
int main(int argc, char** argv) {
    test();
    menu();
   //esto se pondra en una funcion que se llame test();
    return 0;
}
//tengo un error con las plantas i los horarios falta de corregir