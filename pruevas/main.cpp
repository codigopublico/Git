/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 27 de noviembre de 2017, 19:43
 */

#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

/*
 * 
 */
int maxxx = 20;
void p1(){//tengo que hacer que todo bien aqui
    const int max = 20;
    struct prueva{
        int n;
        int n1;
        float n2[max];
        prueva(){
         n = 0;
         n1 = 0;
         for(int i = 0; i < max; i++){
             n2[i] = 0;
         }
        }
        prueva operator=(const prueva &a){
            prueva r;
            r.n = a.n;
            r.n1 = a.n1;
            for(int i = 0; i < max; i++){
                r.n2[i] = a.n2[i];
            }
        }
    };
   
    //aqui empieza la juerga:
    prueva *Pp = new prueva[20];
    for(int i = 0; i < max; i++){
    Pp->n = i;
    cout << Pp->n << "\n";
    Pp++;
    }
}
namespace h{
    int maxxx = 20;
    class cla{
    public:
        int n;
        struct prueva{
        int n;
        int n1;
        float n2[20];
        prueva(){
         n = 0;
         n1 = 0;
         for(int i = 0; i < maxxx; i++){
             n2[i] = 0;
         }
        }
        prueva operator=(const prueva &a){
            prueva r;
            r.n = a.n;
            r.n1 = a.n1;
            for(int i = 0; i < maxxx; i++){
                r.n2[i] = a.n2[i];
            }
        }
    }a;
    cla(){
        n = 0;
    };
    virtual int get();
    };
    int cla::get(){
        return n;
    }
}
void p2(){
    
}
int main(int argc, char** argv) {
    p1(); //esta es una prueva de structuras
    p2();//vamos a provar con las classes
    return 0;
}

