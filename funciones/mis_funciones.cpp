#include "mis_funciones.hpp"
void inter(int& n, int& n1){
    int aux;
    aux = n;
    n = n1;
    n1 = aux;
}
void inter(std::string& n, std::string& n1){
    string aux;
    aux = n;
    n = n1;
    n1 = aux;
}
