/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 5 de diciembre de 2017, 20:23
 */

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

/*
 * 
 */
namespace p1{
   class persona{
   public:
       persona(){
           std::cout << "Estas haciendo la classe persona\n";
       }
       struct Spersona{
           string nom;
           Spersona(){
               nom = "0";
           }
   }pres; 
   virtual void ver();
   persona operator=(const persona &a){
       persona res;
       res.pres.nom = a.pres.nom;
   }
   };
class profecional : public persona{
    public:
        profecional operator=(const profecional &a){
            profecional res;
            res.pres.nom = a.pres.nom;
            res.pres.prof = res.pres.prof;
        }
        struct Spersona{
            string nom;
            string prof;
        }pres;
};
}
void p2(){
    p1::persona *jose;
    jose = new p1::profecional;
    std::cout << jose->pres.nom << "\n";
}
int main(int argc, char** argv) {
    p2();
    return 0;
}

