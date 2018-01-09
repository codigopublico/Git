/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 4 de enero de 2018, 13:19
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
using namespace std;

/*
 * Este es un archivo para hacer la cryptografia de cesar en base a la suma
 */
class encriptar{
public:
    int *d;
    string abc = "abcdefghijklmnopkrstvwxyz";//esto se ha de assignar en el contructor
    int* tranformar(string);//tranforma un string en un int aunque esto se puede hacer con el operador de sbrecarga
    int* cifra(int *i, int c);//c es la contrasenya i esta i es la numeracion transformada anque en una version superior se puede hacer directo con el string
    int* descifra(int *i, int c);
    string string_to_int(int *i);
};
string encriptar::string_to_int(int* i){
    string r;
    for(int q = 0; *i != 0; q++){
        r = r + abc[*i];
        i++;
    }
    return r;
}
int* encriptar::tranformar(string a){
    int i = 0;
    string b;
    string c;
    //primero se tine que hacer 
    for(int e = 0; c != "0" ;e++){
        c = a[e];
        d = new int;
        d++;
        for(int q = 0; q < e; q++){
            d--;
        }
    }
    while(true){
     std::cout << "Empezando por el principio\n" << a[i] << "\n";   
     b = a[i];
      if(b == "0"){//porque esto no va
         break;
     }
     //std::cout << "String copy\n" << strcmp(a[i], "0"); 
     for(int e = 0; e < 24; e++){
         c = abc[e];
         if(b == c){
             std::cout << "El numero es " << e << "\n";
             *d = e;
             d++;
         }
     }
    
     //a++;
     ++i;
     if(i > 20) break;
    }
    for(int e = 0; e < i; e++){
        d--;
    }
    for(int e = 0; e < 5; e++){
         std::cout << *d << "  ";
         d++;
     }
    for(int e = 0; e < i; e++){
        d--;
        std::cout << "abc:   " << abc[*d] << "\n"; 
    }
    return d;
}
int* encriptar::descifra(int* i, int c){
      int cont = 0;
    //int s = i[1];
    int q;
    int *r;
    i++;
    q = *i;
    for(; q != 0; cont++){
        q = *i;
        i++;
    }
    for(q = 0; q < cont; q++){
        i--;
    }
    i--;
    r = new int[cont];
    for(q = 0; q < cont; q++){
        int e = *i;
        *r = e - c;
        r++;
        i++;
    }
    for(q = 0; q < cont; q++){
        r--;
        i--;
    }
    return r;
}
int* encriptar::cifra(int* i, int c){
    int *r;
    int e = 0;
    std::cout << "La i vale " << *i << "\n";
    int cont = 0;
    //int s = i[1];
    int q;
    i++;
    q = *i;
    for(; q != 0; cont++){
        q = i[cont];
    }
    std::cout << "Cont vale  " << cont << "\n";
    r = new int[cont];
    int s[cont];
    std::cout << "Se salta " << "\n";
    for(int q = 0; q < cont; q++){
        e = *i;
        *r = e + c;
        std::cout << "La i vale: " << *i << "\n"; 
        std::cout << "La r vale: " << *r << "\n";
        std::cout << "La e vale: " << e << "\n";
        std::cout << "Debria valer: " << e + c << "\n";
        i++;
        r++;
    }
    for(int q = 0; q < cont; q++){
        r--;
        i--;
    }
    return r;//nada mas falta saber devoler los numeros que  que estan en z + c
}
int main(int argc, char** argv) {
    encriptar prueva;
    int *b;
    string a = "hola0";
    b = prueva.tranformar(a);
    b--;//esto es un arreglo para hacer que funcione bien
    std::cout << "\nb   " << *b << "\n";
    b++;
    std::cout << "b   " << *b << "\n";
    b--;
    b--;
    b = prueva.cifra(b, 2);
    //b++;
    //b++;
    std::cout << "La b vale " << *b << "\n";
    b = prueva.descifra(b, 2);
    //b++;
    //b--;
    std::cout << "La b vale " << *b << "\n";
    std::cout << "La palabra desencriptada es:  " << prueva.string_to_int(b) << "\n"; 
    return 0;
}//tengo que camviar el 0 por -1 o algo de ese modo se tiene que hacer con las varibales que se usan para devolver glovales de modo que no haya violaciones de segmento
//En resumen cambiar el 0 por el -1 de final de txt i hacer que las variables de retorno sean globales..