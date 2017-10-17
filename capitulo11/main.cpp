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
//int max = 200;
class banco : public cuenta {
public:
    
   
    void select(int inid){
        id = inid;
    }
    
}; 
class cuenta : public operar {
public:
    int r = 0;
    
    void crear(string nom){
        cuentas[r].titular = nom;
        r++;
    }
};
class operar{//esta es la base de datos i las operaciones matematicas.....
public:
    int r;
    int id;
    struct cuento{
        int d;
        string titular;
    }cuentas[200];//aqui se define todo el nombre de la estructrua del array
    operar(){
    r = 0;
    id = 0;
    };
    void ingresar(int n){
        cuentas[id].d = cuentas[id].d + n;
    
    }
};
void p1(){
    banco by;
    //by.crear("joan");
    
}
int main(int argc, char** argv) {
    p1();

    return 0;
}

