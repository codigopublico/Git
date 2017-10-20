/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 20 de octubre de 2017, 14:56
 */

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

/*
 * 
 */
class Calculadora
{
public:
Calculadora(int);
void doblaNumero();
int getNumero();
void suma(int);
void suma(int, int);
private:
int *numero;
};
Calculadora::Calculadora(int num)
{
numero = new int;
*numero = num;
}
void Calculadora::doblaNumero()
{
*numero = *numero * 2;
}
int Calculadora::getNumero()
{
return *numero;
}
void Calculadora::suma(int num){

}
void Calculadora::suma(int num, int num2){

}
void calc(){
    Calculadora oclac(0);
    oclac.getNumero();
}
int main(int argc, char** argv) {
    calc();
    return 0;
}

