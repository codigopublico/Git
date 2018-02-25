/*
 * File:   main.cpp
 * Author: iper
 *
 * Created on 14 de febrero de 2018, 13:13
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

/*
 *Esto es para los archvios i como manegarlos i de paso hacer lo de las virtuales i los punteros
 */
class  Vbase{
public:
Vbase(){
std::cout << "haciendo uso de la unidad base";
}
virtual int Mesc(char *aux, int n) = 0;
virtual void Mlec(char *aux, int n) = 0;
};
class base : public Vbase{
public:
base(){
std::cout << "Haciendo uso de la base\n";
}
};
class Cesc : public base{
public:
int Mesc(char *aux, int n);
void Mlec(char *aux, int n);
};
void Cesc::Mlec(char *aux, int n){//esto esta mal lo devo definir entro classe
std::cout << "Llamando a la funcion de lectura\n";
}
int Cesc::Mesc(char *aux, int n){
std::cout << "Llamando al metodo de escritura para hacer todo ...\n";
std::cout << "El archivo es: " << aux << "  " << "el numero a escribir es...  " << n << "\n";
ofstream fs(aux);//el problema es este que no puedo poner un string voy a mirar i leer las librerias 
//i/o como convertir en char el string 
fs << "El archvo es ... " << aux << endl;
fs.close();
return 5;//Valor tonto, tiene que ser el numero de caracteres escritos
}
void p1(){
char *a = new char;
*a = "hola";
base *a1;
a1 = new Cesc;
a1->Mesc("hola", 5);//vale ya esta al menos la escritura ahora solo falta hacer la lectura
a1->Mlec(*a, 5);//Este es para la lecstura no se que le pasa a esta funcion
}
int main(int argc, char** argv) {
p1();
    return 0;
}

//devo hacer las variables de los archvios globales.......................
