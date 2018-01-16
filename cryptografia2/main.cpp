/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 7 de enero de 2018, 13:01
 */

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

/*
 * 
 */
class base{
public:
    int *d;
    base();
    string abc;
    int* tranformar(string);//tranforma un string en un int aunque esto se puede hacer con el operador de sbrecarga
    int* cifra(int *i, int c);//c es la contrasenya i esta i es la numeracion transformada anque en una version superior se puede hacer directo con el string
    int* descifra(int *i, int c);
    string string_to_int(int *i);
};
base::base(){
       abc = "abcdefghijklmnoupkqrstvwxyz";//esto se ha de assignar en el contructor
}
string base::string_to_int(int* i){
    string r;
    int q = 0;
    for(; *i != -1; q++){
        while(*i > 26){ *i = *i - 27;}
        while(*i < 0){ *i = *i + 27;}
        r = r + abc[*i];
        i++;
    }
    for(int w = 0; w < q; w++){
        i--;
    }
    return r;
}
int* base::tranformar(string a){ //Se le tiene que pasar un pasar un parametro que se llama final i es -1
    string c;
    string aux;
    //primero se tine que hacer 
    //esto es para hacer que funcione bien 
    int e = 0;
    bool boo;
    for(; boo == true;e++){
        c = a[e];
        aux = a[e + 1];
        d = new int;
        d++;
        if(aux == "1" && c == "-" ) boo = false;
        if(e > 200) break;
        //std::cout << "Abc" << c << "\n";
    }
    //std::cout << e << "\n";
    for(int q = 0; q < e; q++){
            d--;
            //std::cout << "Esto se repite....." << "\n";
    }
    std::cout << "Esto se acaba\n";
    for(int i = 0; i < e; i++){
        c = a[i];
        //std::cout << "Cuantas veces se repite\n";
        for(int q = 0; q < 27; q++){
            aux = abc[q];
            if(c == aux){
                *d = q;
                std::cout << "Resultado de tranformar: " << *d << "\n";
                d++;
            }
            if(c == aux) break;
            //std::cout << "Este es el bucle infito\n";
        }
    }
    *d = -1;//este es el numero que marca el final
    for(int i = 0; i < e; i++){
        d--;
        //i--;
    }
    return d;

}

int* base::cifra(int* i, int c){
    int e = 0;
    //delete d;
    for(; *i != -1;e++){
        i++;
    }
    for(int q = 0; q < e; q++){
        i--;
    }
    d = new int[e];
    for(int q = 0; q < e; q++){
        *d = *i + c;
        std::cout << "Resultado:  " << *d << "\n"; 
        d++;
        i++;
    }
    *d = -1;
    for(int q = 0; q < e; q++){
        d--;
    }
    return d;
}
int* base::descifra(int* i, int c){
    int e = 0;
    std::cout << "Descifrado el mensaje....\n";
    //delete d;
    for(; *i != -1;e++){
        i++;
    }
    for(int q = 0; q < e; q++){
        i--;
    }
    d = new int[e];
    for(int q = 0; q < e; q++){
        *d = *i - c;
        std::cout << "Resultado:  " << *d << "\n"; 
        d++;
        i++;
    }
    *d = -1;
    for(int q = 0; q < e; q++){
        d--;
    }
    return d;
}
class crypto : private base{
public:
    crypto();
    string encrypt(string, int); //int es la contrasenya
    string decrypt(string, int);
};
crypto::crypto(){
        abc = "abcdefghijklmnoupkqrstvwxyz";
}
string  crypto::encrypt(string a, int c){
    int *z;
    z = tranformar(a + "-1");
    z = cifra(z, c);
    return string_to_int(z);
}
string crypto::decrypt(string a, int c){
    int *z;
    z = tranformar(a + "-1");
    z++;
    z++;
    z = descifra(z , c);
    return string_to_int(z);
}
void pruevas(){
    base hola;
    string a = "quiero-1";
    int *b;
    int c = 99999999;
    b = hola.tranformar(a);
    //std::cout << "Estoy tonto\n";
    std::cout << "La b vale: " << *b << "\n";
    b = hola.cifra(b, c);
    std::cout << "La b vale: " << *b << "\n";
    std::cout << "El mensaje encriptado es: " << hola.string_to_int(b) << "\n";
    a = hola.string_to_int(b);
    a = a + "-1";
    std::cout << a << "\n";
    b = hola.tranformar(a);
    b++;
    std::cout << *b << "\n";
    b = hola.descifra(b, c);
    std::cout << "Que pasa aqui...";
    std::cout << "El mensaje descirtado es: " << hola.string_to_int(b) << "\n";
}
void pruevas_crypt(string a){
    crypto hola;
    a = hola.encrypt(a, 2);
    std::cout << "Encypt : "<< a << "\n";
    std::cout << "Descifra:  " << hola.decrypt(a, 2) << "\n";
    std::cout << "Que pasa joder\n";
}
void encrypt(string a){
    crypto b;
    cout << b.encrypt(a, 2) << "\n";
}
void decrypt(string a){
    crypto b;
    cout << b.decrypt(a, 2) << "\n";//de momento se usa 2 pero se ha de hacer 
}
int main(int argc, char** argv) {
    //pruevas();
	if(argc < 1){
	std::cout << "El primer caracter es para cifrar o descifrar";
            std::cout << "e para cifrar";
            std::cout << "d para descifrar";
	std::cout << "help para mostrar este meni\n";
}
    if(argc > 1){
        if(argv[1] == "help"){
            std::cout << "El primer caracter es para cifrar o descifrar";
            std::cout << "e para cifrar";
            std::cout << "d para descifrar";
        }
    }
    if(argc > 2){
        if(argv[1] == "e"){
            encrypt(argv[2]);
        }
        if(argv[1] == "d"){
            std::cout << "esto es d  " << argv[2] << "\n"; 
            decrypt(argv[2]);
        }
        else{
            std::cout << "Se esta ejecutado puevas\n";
            pruevas_crypt(argv[1]);
        }
    //pruevas_crypt(argv[1]);
    }
    else{
        std::cout << "Haz help para mostrar las opiciones";
    }
    for(int i = 0; i < argc; i++){
        std::cout << "argv " << argv[i] << "  " << i << "\n" ;
    }
    return 0;
}//la clase base se tiene que llamar base.....
//En la funcion de string_to_int tengo que poner estatico adeams de si es mayor que el abecedario restar esl numero
//elrpoblemaesta cuando es mas grande que 24 como se puede codificar eso se tiene que hacer con numeros 
//dicho de otro modo se son mas grades de 24 lo que se tiene que hacer es dar la vuleta hasta que no sean
//lo que tengo que hacer que se deven vueltas al rededor del string hasta encontrar
//un numero menor o igual a 24
//vale i si pruevo un codigo real
