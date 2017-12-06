#include <cstdlib>
#include "hospi.hpp"
#include "hospi.cpp"
using namespace std;
using namespace hos;
/*
 * 
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
    Prog--;
    Prog.ver(a, b);
    cout << "Nombre:  " << a << "\n";
    cout << "telf:    " << b << "\n";
    hos::limpia(100);
    hos::hospital Stcatarina(a);
}
int main(int argc, char** argv) {
    p8();
    return 0;
}
