/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 19 de diciembre de 2017, 13:13
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
class base{
public:
    virtual void print() = 0;
};
class derivada : public base{
    virtual void print(){
        std::cout << "Por fin polimorfisomo dos setmanas, haver si lo puedo implementar en la base del codigo\n";
    }
};
void vtables(){
    base *Obase = new derivada;
    Obase->print();
}
int main(int argc, char** argv) {
    vtables();
    return 0;
}

