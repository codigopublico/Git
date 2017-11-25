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
 * 
 */
void p1(){
    int a;
    string b;
    int c;
    dis::disco alan;
    alan.crear(1, 2, "a");
    alan.ver(a, c, b);
    std::cout << a << "  " << b <<"   " << c << "\n";
    dis::fiesta piscina(2);
    
}
int main(int argc, char** argv) {
    p1();
    return 0;
}

