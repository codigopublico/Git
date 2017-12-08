#include <cstdlib>
#include "hospi.hpp"
#include "hospi.cpp"
using namespace std;
using namespace hos;
/*
 * Tengo que saber como se hace un constructor de capias a un puntero......
 */
void p8(){
    string a;
    int b;
    hos::persona joel("joel", 972);
    joel--;
    joel.ver(a, b);
    //joel = new hos::profecional;
    cout << "Nombre:  " << a << "\n";
    cout << "telf:    " << b << "\n";
    hos::profecional Prog("Progrmador", 971);
    Prog.ver(a, b);
    cout << "Nombre:  " << a << "\n";
    cout << "telf:    " << b << "\n";
    hos::limpia(20);
    cout << "Chiquito de la calzada\n";
    Prog--;//Tengo que encontrar uno que no entre en conflicto con los punteros. Lo voy a provar para haber si funciona bien...
    Prog.ver(a, b);
    cout <<  "Nombre:  " << a << "\n";
    cout << "telf:    " << b << "\n";
    hos::limpia(100);
    hos::hospital Stcatarina(b);
    int c[2] = {0, 0};
    hos::limpia();
    Stcatarina.alta("joana", 0, 0, c);
}
int main(int argc, char** argv) {
    p8();
    return 0;
}
