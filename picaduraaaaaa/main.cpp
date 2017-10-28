/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 9 de octubre de 2017, 15:21
 */

#include <cstdlib>
#include <mi_teclado>

using namespace std;

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


int main(int argc, char** argv) {
    //std::cout << det() << "\n";
    //p1();
    //p2();
    p3();
    return 0;
}

