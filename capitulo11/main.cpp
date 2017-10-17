/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 17 de octubre de 2017, 15:16
 */

#include <cstdlib>
#include <string>
using namespace std;

/*
 * 
 */
int max;
class banco{
public:
    int r;
    banco(){
        r = 0;
    }
    struct cuentas{//aqui tiene que ser un array.
        int d;
        string titular;
    };
    
}; 
class cuenta : public banco{
public:
    void crear(string nom){
        cuentas.titular = nom;
        r++;
    }
};
class operar : public cuenta{
public:
     
    operar(){};
    void ingresar(int n){
        cuentas.d = cuentas.d + n;
    
    }
};

int main(int argc, char** argv) {

    return 0;
}

