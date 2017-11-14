/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 21 de octubre de 2017, 13:26
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <mia/no_renderizadas/mis_funciones.hpp>
using namespace std;

/*
 * 
 */
void limpiar(){
    for(int i = 0; i < 1000; i++){
        std::cout << "\n";
    }
}
class vehiculo{
public:
    struct repa{
        bool n;//esta es la variable para saber si esta echa la reparcion.
        int dinero; //este es el dinero que se cobra por la reparcion.
        string nombrer; //esta es la variable del nombre de las reparciones...
    };
    struct vehicul{
        string nombre;
        int dinero;//este es el dinero que deve el cliente....
        repa q[200];//este es exclusivo del taller 200 es el numero maximo que puede soportar cada cohe.
        int nr;
    };
    vehicul d;
    vehiculo(){
        std::cout << "Construiendo el vehiculo";
    }
};
class taller : public vehiculo{
public:
    int id;
    vehicul tall[200]; //tall es el string de vehculos. 
    taller(){
        id = 200;
        for(int i = 0; i < id; i++){
        tall[i].dinero = 0;
        for(int ii = 0; ii < 200; ii++){
        tall[i].q[ii].dinero = 0;
        tall[i].q[ii].n = true;
        tall[i].q[ii].nombrer = "0";
        tall[i].nr = 0;
        }
        tall[i].nombre = "0";
        }
        id = 0;
    }
    void reparar(int d, int e){//el d es la varable para el coche el e es el numero de reparacion 
        tall[d].dinero = tall[d].q[e].dinero;
        tall[d].q[e].n = true;
        tall[d].nr--;
        
    }
    void areparacion(int d, int n){//d es la pasta i n es el numbre del coche.
        tall[n].q[tall[d].nr].dinero = d;
        tall[n].q[tall[d].nr].n = false;
        tall[n].nr++;
    }
        void areparacion(int d, int n, string no){//d es la pasta i n es el numbre del coche.
        tall[n].q[tall[d].nr].dinero = d;
        tall[n].q[tall[d].nr].n = false;
        tall[n].q[tall[d].nr].nombrer = no;
        tall[n].nr++;
    }
    void mrepacion(int d){
        std::cout << "Estes es el historial\n";
        for(int i = 0; i < 200; i++){
            if(tall[d].q[i].n && tall[d].q[i].dinero > 0){
                std::cout << "Nombre:  "<<tall[d].q[i].nombrer <<"\n";
                std::cout << "Dinero:  "<<tall[d].q[i].dinero <<"\n";
            }
        }
        std::cout << "Estas son las reparaciones que faltan\n";
        for(int i = 0; i < 200; i++){
            if(!tall[d].q[i].n){
                std::cout << "Nombre:  "<<tall[d].q[i].nombrer <<"\n";
                std::cout << "Dinero:  "<<tall[d].q[i].dinero <<"\n";
                std::cout << "id:      " << i;
            }
        }
    }
    void entrar(const vehiculo &en){
        tall[id].dinero = en.d.dinero;
        tall[id].nombre = en.d.nombre;
        id++;
}
    void mostrar(){
        int e = 0;
        std::cout << "\n";
        
        for(int i = 0; i < id; i++){
            for(int ii = 0; ii < tall[i].nr; ii++){
            if(!tall[i].q[ii].n){
                e++;
            }
        }
            std::cout << "Nombre:          " << tall[i].nombre << "\n";
            std::cout << "Pagar:           " << tall[i].dinero << "\n";
            std::cout << "id:              " << i << "\n";
            std::cout << "Reparaciones:    " << e;
            e = 0;
            for(int ii = 0; ii < 3; ii++){
                std::cout << "\n";
            }
        }
    }
    void cobrar(int d){
        tall[d].dinero = 0;
    }
    void cobrar(int d, int e){
        tall[d].dinero = tall[d].dinero - e;
    }
    void mostrar(int i){
        if(i > id){
            std::cout << "\nMe pasate un id incorrento, chao!!!!!!\n";
        }else{
        std::cout << "Nombre:          " << tall[i].nombre << "\n";
        std::cout << "Pagar:           " << tall[i].dinero << "\n";
        std::cout << "id:              " << i << "\n";
        }
    }
    void eliminar(string n){
        int c;
        for(int i = 0; i < id; i++){
            if(tall[i].nombre == n){
                tall[i].nombre = "0";
                tall[i].dinero = 0;
                c++;
            }
        }
        int q = 0;
        while(q < id){
            q = 0;
            for(int i = 0; i < id; i++){
                //std::cout << " tall " << tall[i].nombre << " tall2 " << tall[i + 1].nombre<<"\n" ;
                if(tall[i].nombre != "0"){
                    q--;
                }
                if(tall[i].nombre == "0"){
                    q++;
                    lib::inter(tall[i].nombre, tall[i + 1].nombre);
                    lib::inter(tall[i].dinero, tall[i + 1].dinero);
                    for(int ii = 0; ii < 200; ii++){
                        lib::inter(tall[i].q[ii].dinero, tall[i + 1].q[ii].dinero);
                        lib::inter(tall[i].q[ii].n, tall[i + 1].q[ii].n);
                    }
                }
            }
        }
        id = id - c;
    }
};
void p3(){
    string in;
    string aux;
    int n;
    vehiculo vcoche;
    taller autom;
    do{
        limpiar();
        std::cout << "\n Para crear un choche(c) \n";
        std::cout << "Para mostrar los coches(m) \n";
        std::cout << "Para eliminar un coches(e) \n";
        std::cout << "Modificar vehiculo(v), (Modificar Reparaciones)\n";//falta poner el nobmre de las repaarciones...
        std::cout << "Cobrar coche.(p)\n";
        std::cout << "Para salir Fin\n";
        std::cin >> in;
        if(in == "c"){
            std::cout << "Dime el dinero que debe\n";
            std::cin >> vcoche.d.dinero;
            std::cout << "Dime el nombre del vehiculo\n";
            std::cin >> in;
            vcoche.d.nombre = in;
            autom.entrar(vcoche);
        }
        if(in == "m"){
            autom.mostrar();
        }
        if(in == "e"){
            autom.mostrar();
            std::cout << "Dime el nombre a eliminar\n";
            std::cin >> in;
            autom.eliminar(in);
        }
        if(in == "v"){
            autom.mostrar();
            std::cout << "Dime el id del cohce a modificar las reparaciones";
            std::cin >> n;
            std::cout << "Eliguste:   \n";
            autom.mostrar(n);
            std::cout << "Quires cargare un reparacion pendiente(a),\n Quires repararlo(r),\n  O simplemente listar las reparaciones(v) \n";
            std::cin >> in;
            if(in == "a"){
                int d;
                std::cout << "Cuanto cuesta la nueva reparacion a hacer\n";
                std::cin >> d;
                std::cout << "Cual es la etiqueta que le quieres poner\n";
                std::cin >> in;
                autom.areparacion(d, n, in);
            }
            if(in == "r"){
                int d;
                autom.mrepacion(n);
                std::cout << "Que reparacion quieres hacer\n";
                std::cin >> d;
                autom.reparar(n, d);
            }
        }
        if(in == "p"){
            autom.mostrar();
            std::cout << "Dime el id del cohce al que quieres cobrar:\n";
            std::cin >> n;
            std::cout << "Te pago todo(s/n)\n";
            std::cin >> in;
            if(in =="s"){
                std::cout << "Bien\n";
                autom.cobrar(n);
            }else{
                int d;
                std::cout << "Cuanto te pago\n";
                std::cin >> d;
                autom.cobrar(n, d);
            }
        }
        if(in == "FIN"){
            std::cout << "Fin del programa\n";
        }
        else{
            std::cout << "Error!!!!";
        }
        if(in != "FIN"){
        std::cout << "dame un dato para continuar\n";
        std::cin >> aux;
        }
    }while(in != "FIN");
}
class cuenta{//Classe cuentacorriente
private:
    int d;
public:
    cuenta();
    cuenta(int n){
        d = n;
    };
    operator unsigned int(){
        return d;
    }
    
    cuenta operator +(int n){
        cuenta res(d + n);
        return res;
    }
    cuenta operator-(int n){
        cuenta res(d - n);
        return res;
    }
   
    cuenta operator+(const cuenta &p1){//este para hacer la sobre carga de operadores de classes
        cuenta res(p1.d + d);
        return res;
    }
    cuenta operator-(const cuenta &p1){//este para hacer la sobre carga de operadores de classes
        cuenta res(p1.d - d);
        return res;
    }
    cuenta operator*(int n){
        cuenta res(d * n);
        return res;
    }
    cuenta operator=(int n){
        cuenta res(d = n);
        return res;
    }
    int getd(){
        return d;
    }
};
cuenta::cuenta(){
    d = 0;
}
void p1(){
    cuenta joan;
    joan = joan + 10;
    cuenta alex;
    alex = alex + 200;
    alex = alex - 0;
    std::cout << "alex  " << alex.getd() << "\n ";
    cuenta banco = alex + joan;
    banco = banco * 2;
    std::cout << "d  " << banco.getd() << "\n  ";
    cuenta ale(10);
    ale = ale = 1000;
    //int x = ale;
    //std::cout << x;
    int x = ale;
    std::cout << x << "\n";
    
}
class Rectangulo 
{ 
public: 
double ancho; 
double alto; 
Rectangulo(double ina, double inb){
    alto = ina;
    ancho = inb;
}
Rectangulo(){
    ancho = 0;
    alto = 0;
}
Rectangulo operator+(const Rectangulo &b) 
{ 
    Rectangulo res(b.alto + alto, b.ancho + ancho);
    return res;
} 
double getArea() 
{ 
return ancho * alto; 
} 
}; 
void p2(){
    
Rectangulo c1; 
Rectangulo c2; 
Rectangulo c3; 
c1.ancho = 2,0; 
c1.alto = 20,0; 


c2.ancho = 2,0; 
c2.alto = 4,0; 
c3= c1 + c2; 
cout << "caja 1: " << c1.getArea() <<endl; 
cout << "caja 2: " << c2.getArea() <<endl; 
cout << "caja 3: " << c3.getArea() <<endl; 
cout << "caja 3: " << c3.ancho <<endl;

}

int main(int argc, char** argv) {
    p1();
    p2();
    p3();
    std::cout << "\n";
    return 0;
}