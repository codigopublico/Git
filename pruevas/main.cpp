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
namespace head{
    class Chead{
    public:
        struct Shead{
            int n;
            float f;
            string cha;
            Shead(){
                n = 0;
                f = 0;
                cha = "0";
            }
            Shead operator=(const Shead &a){
                Shead res;
                res.n = a.n;
                res.f = a.f;
                res.cha = a.cha;
                return res;
            }
        };
    };
    class Ehead : public Chead{
    public:
        Shead *Ps;
        int total[2];//el primero es para los virtuales i el segundo es para hacer los reales.
        Ehead(int);
        void crear(int&, float&, string&);
    };
    Ehead::Ehead(int In){
        Ps = new Shead[In];
        total[1] = In;
        total[0] = 0;
    }
    void Ehead::crear(int &a, float &b, string &c){
        for(int i = 0; i < total[0]; i++){
            *Ps++;
            std::cout << "Ps   " << Ps->n << "\n"; 
        }
        Ps->n = a;
        Ps->f = b;
        Ps->cha = c;
        for(int i = 0; i < total[0]; i++){
            *Ps--;//vale lo uinico que falta es hacer el 
                        std::cout << "Ps   " << Ps->n << "\n"; 

        }
        total[0]++;
    }
}
void p2(){
    
}
void p3(){
    int a = 2;
    float b = 30;
    string c = "a";
    int *P;
    head::Ehead Ohead(2);
    Ohead.crear(a, b, c);
    *P = Ohead.Ps->n;
    std::cout << P << "\n";
}
int main(int argc, char** argv) {
    //p1(); //esta es una prueva de structuras
    //p2();//vamos a provar con las classes
    p3(); //este es una prueva de las objectos al head.
    return 0;
}

