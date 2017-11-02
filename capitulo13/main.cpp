/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 29 de octubre de 2017, 12:27
 */

#include <cstdlib>
#include <iostream>
#include "libreria.hpp"
using namespace std;
using namespace lib;
/*
 * 
 */
void limpiar(){
    for(int i = 0; i < 10000; i++){
    std::cout << "\n";
    }
}
void final(){

    std::cout << "final"; 
    libro orwell("o", "1984", 1);
    libro mundo_feliz("orwell", "mundo", 2);
    libreria sintitulo;
    for(int i = 0; i < 20; i++){
    sintitulo.intro_libro(orwell);
    sintitulo.intro_libro(mundo_feliz);
    }
    sintitulo.mostrar();
    sintitulo.stock(38, 100);
    sintitulo.astock(38, 20);
    sintitulo.Buscar_libro("mundo");
    sintitulo.Buscar_libro(21);
    sintitulo.eliminar("o");
    sintitulo.stock(40, 1000);

    //sintitulo.eliminar("orwell");
    std::cout << "Mostrando la biblioteca final\n";
    for(int i = 0; i < 250; i++){
        std::cout << ".";
    }
    sintitulo.mostrar();
}
void final2(){
    string in;
    string aux2;
    int n;
    int aux;
    libreria menu;
    libro v;
    do{
        limpiar();
        std::cout << "Fin para salir \n";
        std::cout << "Para mostrar(m) \n";
        std::cout << "Para crear_libro(c) \n";
        std::cout << "Para cambiar_stock(s) \n";
        std::cout << "\n";
        std::cin >> in;
        if(in == "m"){
            menu.mostrar();
        }
        if(in == "c"){
            std::cout << "\nDame tu libro\n";
            std::cout << "\nDime el autor\n";
            std::cin >> in;
            v.uno.autor == in;
            std::cout << "\nDime el titulo\n";
            std::cin >> in;
            v.uno.titulo = in;
            std::cout << "\nDime la categoria, tienes estas: \n";
            std::cin >> n;
            v.uno.categoria = n;
            std::cout << "\nDime el stock\n";
            std::cin >> n;
            v.uno.stock = n;
            menu.intro_libro(v);
        }
        if(in == "s"){
            menu.mostrar();
            std::cout << "Time la ref a usar:  \n";
            std::cin >> n; 
            std::cout << "Dime si quieres anayadir(a), o modificar(m)";
            std::cin >> in;
            if(in == "a"){
                
            }
        }
        
        std::cout << "Dame un dato para continuar\n";
        std::cin >> aux2;
    }while(in != "FIN");
}
int main(int argc, char** argv) {
    final();
    final2();
    return 0;
}

