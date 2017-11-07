/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 9 de octubre de 2017, 15:21
 */

#include <cstdlib>
#include <mi_teclado>
#include <mis_funciones.hpp>
using namespace std;
using namespace lib;

/*
 * Este arcivo son las pruevas de mis librerias.......
 */
void p1(){
    int x = 5;
int &y = x;
int &z = y;
x = 7;
cout << x;
cout << y;

cout << z << endl;
//7
y = 8;
cout << x;
cout << y;
cout << z << endl;
z = 9;
cout << x;
cout << y;
cout << z << endl;


} 
void p2(){
   // int &x = 9;
  //std::cout << x; //esto es ilegal ......
    
}
void p3(){
    void doblar(int &numero);

int x = 5;
doblar(x);
cout << x;
}
void doblar(int &numero)
{
numero = numero * 2;
}
/*int* p(int n[10]){
    int *n = new int[10];
    for(int i = 0; i < 10; i++){
        *n = i + i;
        n++;
    }
    return n;
}
void p4(){
    int n2[10];
    int *n = p(n2);
    n++;
    std::cout << *n;
}*/
int& doblaNumero(int&);
int& doblaNumero(int& numero)
{
numero = numero * 2;
return numero;
}

void p5(){
    int num1 = 25;
int& num2 = doblaNumero(num1);
num1 = 100;
cout << "num2: " << num2;

}
void hola(const int &n){
    //n = n  * 2; //no se pude hacer ya que da una referncia mala porque es constante-
}
void p6(){
    int n1 = 2;
    hola(n1);
    std::cout << n1;
}
using namespace std; 
class Calculadora 
{ 
public: 
Calculadora(int); 
Calculadora();
void doblaNumero(); 
int* getNumero();
~Calculadora();
Calculadora(const Calculadora &a);
private: 
int *numero; 
}; 
Calculadora::Calculadora(){
    numero = new int;
    *numero = 0;
}
Calculadora::Calculadora(int num) 
{ 
numero = new int; 
*numero = num; 
} 
void Calculadora::doblaNumero() 
{ 
*numero = *numero * 2; 
} 
int* Calculadora::getNumero() 
{ 
    //int num = *numero;
return numero; 
}
Calculadora::~Calculadora(){
delete numero;    
}
Calculadora::Calculadora(const Calculadora &a){
    //numero = new int;
//    *numero = a.numero;
}
void p7(){
Calculadora calc1(15); 
calc1.doblaNumero(); 
cout << "1: " << calc1.getNumero() << endl; 
Calculadora calc2(calc1); //aqui esta el error es un error de copia de copia de  classes
calc2.doblaNumero(); 
cout << "2: " << calc2.getNumero() << endl; 
cout << "3: " << calc1.getNumero() << endl;
calc2.doblaNumero();
cout << "4: " << calc2.getNumero() << endl;
}
void p8(){
    std::cout << "Este es el p8(), bienbiendo\n";
            string h;
            string b;
            h = "hola";
            b = "adios";
            int n[2] = {1, 2};
            std::cout << "h   " << h << " b   " << b << "\n";
            //lib::inter(h, b);
            std::cout << "h   " << h << " b   " << b << "\n";
            lib::inter(n[0], n[1]);

}
int main(int argc, char** argv) {
    //std::cout << det() << "\n";
    //p1();
    //p2();
    //p3();
    //p4();
    //p5();
    //p6();
    //p7();
    p8();//Este esta echo para provar el interncambio de variables de la libreria inter
    return 0;
}

