/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 30 de diciembre de 2017, 21:59
 */

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

/*
 * 
 */
void hola(string);
void adios(string);
void conversacion(void (*)(string), void (*)(string), string, string);
void hola (string nombre)
{
cout << "¡ Hola " << nombre << " !" << endl;
}
void adios(string nombre)
{
cout << "¡ Adiós " << nombre << " !" << endl;
}
void conversacion(void (*fun1)(string), void (*fun2)(string), string mensaje1, string mensaje2)
{
fun1(mensaje1);
fun2(mensaje2);
}
class Acciones{
public:
virtual void saludo(string) = 0;
};
class Chola : public Acciones{
public:
void saludo(string a){
hola(a);
}
};
class Cadios : public Acciones{
public:
void saludo(string a){
adios(a);
}
};
/*void b(){
void (*f1) (string) = hola;
void (*f2) (string) = adios;
conversacion(sol, luna, "Jordi", "Maria");
}*/
void c(){
Acciones *ptr;
ptr = new Cadios;
ptr->saludo("juan");
}
void d(){
Acciones *ptr[20];
string hola[20];
for(int i = 0; i < 20; i++){
if(i%2 == 0){
ptr[i] = new Cadios;
hola[i] = "Sol";
}else{
ptr[i] = new Chola;
hola[i] = "Luna";
}
ptr[i]->saludo(hola[i]);
}
}
int main(int argc, char** argv) {
	//b();
	c();
	d();
    return 0;
}
