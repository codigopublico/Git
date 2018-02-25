/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 14 de febrero de 2018, 13:13
 */

#include <cstdlib>
#include <string>
using namespace std;

/*
 *Esto es para los archvios i como manegarlos
 */
class  Vbase{
Vbase(){
std::cout << "haciendo uso de la unidad base";
}
virtual escribir(string aux, int n) = 0;
};
class base : public Vbase{
};
class Cesc : public base{
int Mesc(string aux, int n);
};
int Cesc::Mesc(string aux, int n){
std::cout << "Llamando al metodo de escritura\n";
return 5;//Valor tonto, tiene que ser el numero de caracteres escritos
}
void p1(){
base *a1();
a1 = new Cesc;
a1.Mesc();
}
int main(int argc, char** argv) {
p1();
    return 0;
}

