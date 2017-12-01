/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 23 de noviembre de 2017, 17:36
 */

#include <cstdlib>
#include "discoteca.hpp"
using namespace std;

/*
 *      Esto parece que funciona.
 */
const int total = 2;
void p1(){
    int a;
    string b;
    int c;
    int *q;
    int *d;
    string *e;
    is::disco alan;
    alan.crear(1, 2, "a");
    alan.ver(a, c, b);
    std::cout << a << "  " << b <<"   " << c << "\n";
    is::fiesta piscina(total);
    piscina.crear(0, 0, "a");
    piscina.crear(0,0,"b");//aqui ay un error
        std::cout << "\n11111111111\n";
    piscina.ver(q, d, e);
    std::cout << "\n11111111111\n";
    cout << "   " << e  << "   \n";
    e++;
    cout << "   " << *e  << "   \n";

    
}
int main(int argc, char** argv) {
    p1();
    return 0;
}

