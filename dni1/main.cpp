/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 21 de febrero de 2018, 17:48
 */

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

/*
 *Este es un archvio para hacer el caluclo del dni 
 */
string abc[] = {"t", "r", "w", "a", "g", "m", "y", "f", "p", "d", "x", "b", "n", "j", "z", "s", "q", "v", "h" , "l" , "c", "k", "e"};
int calc(int n){
    int r;
    r = n % 23; 
    return r;
}
class dni{
public:
    int n1;
    dni();
    dni(int);
    string cal();
    string cal(int);
};
dni::dni(){
    n1 = 0;
}
dni::dni(int In){
    n1 = In;
}
string dni::cal(int In){
     return  abc[calc(In)];
}
string dni::cal(){
    return abc[calc(n1)];
}
void p1(){
    dni p;
    std::cout << p.cal(23);
}
void space(){
    int x = 10;
    for(int i = 0; i < x; i++){
        std::cout << "\n";
    }
}
void space(int x){
    for(int i = 0; i < x; i++){
        std::cout << "\n";
    }
}
int menu2(string n){
    int n3;
    space(300);
    std::cout << "Tu numero es " << n3 << n << "\n";
    std::cout << "Dime el numero de tu dni(0 para salir)\n";
    std::cin >> n3;
    return n3;
}
void menu(){
    dni aux;
    bool e = true;
    int n;
    while(e){
        n = menu2(aux.cal(n));
    }
    
}
int main(int argc, char** argv) {
    //p1();
    menu();
    std::cout << "\n";
    return 0;
}

