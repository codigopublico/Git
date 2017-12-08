/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 8 de diciembre de 2017, 8:27
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
namespace punt{
    struct tresd{
        int x;
        int y;
        int z;
        tresd(){
            x = 0;
            y = 0;
            z = 0;
        }
        tresd(int a, int b, int c){
            this->x = a;
            this->y = b;
            this->z = 0;
        }//la resulcion del problema es que se necessita hacer un puntero this en toda la estructura...
        tresd operator=(const tresd &a){
            tresd res;
            res.x = a.x;
            res.y = a.y;
            res.z = a.z;
            return res;
        }
        /*tresd* operator=(const tresd &a){
            this->x = a.x;
            this->y = a.y;
            this->z = a.z;
            return this;
        }**/
    };
}
void p1(){
    int n = 10;
    punt::tresd *esfera;
    esfera = new punt::tresd[n];
    esfera->x = 100;
    cout << "Esta es la esfera  " <<esfera->x << "\n";
    esfera++;
    cout << "Esta es la esfera  " <<esfera->x << "\n";
    esfera--;
    cout << "Esta es la esfera  " <<esfera->x << "\n";
    punt::tresd cubo(2, 5, 10);
    esfera->x = cubo.x;
    esfera->y = cubo.y;
    esfera->z = cubo.z;//esta es una manera un poco arcaica 
    cout << "Esta es la esfera  " <<esfera->x << "\n";
}
int main(int argc, char** argv) {
    p1();
    return 0;
}

