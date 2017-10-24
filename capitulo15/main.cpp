/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 21 de octubre de 2017, 13:26
 */

#include <cstdlib>
#include <string>

using namespace std;

/*
 * 
 */
class vehiculo{
public:
    int r; 
    struct vehicul{
        string nombre;
        int dinero;
        int nreparacion;
    }vehi[500];
    vehiculo(){
        for(int i = 500; i > 0; i++){
            vehi[i].dinero = 0;
            vehi[i].nombre = NULL; //tengo que hacer lo el null
            vehi[i].nreparacion = 0;
        }
        r = 0;
    }
};
class taller : public vehiculo{
public:
    int id;
    void reparar(int d){
        vehi[id].dinero = vehi[id].dinero + d;
        vehi[id].nreparacion++;
    }
};
int main(int argc, char** argv) {

    return 0;
}