/* 
 * File:   calculadora.hpp
 * Author: iper
 *
 * Created on 21 de octubre de 2017, 13:12
 */

#ifndef CALCULADORA_HPP
#define	CALCULADORA_HPP
class Calculadora
{
public:
Calculadora(int);
void doblaNumero();
int getNumero();
void suma(int);
void suma(int, int);
void resta(int, int);
void resta(int);
void multi(int);
void multi(int, int);
void divi(int);
void divi(int, int);
void set(int);
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
    *numero = *numero + num;
}
void Calculadora::suma(int num, int num0){
    *numero = *numero + num + num0;

}
void Calculadora::resta(int num, int num0){
    *numero = *numero - num - num0;

}
void Calculadora::resta(int num){
    *numero = *numero - num;

}

void Calculadora::multi(int num){
    *numero = *numero * num;

}
void Calculadora::multi(int num, int num0){
    *numero = *numero * num * num0;

}
void Calculadora::divi(int num){
    *numero = *numero / num;

}
void Calculadora::divi(int num, int num0){
    *numero = *numero / num / num0;
}
void Calculadora::set(int num){
    *numero =  num;
}

#endif	/* CALCULADORA_HPP */

