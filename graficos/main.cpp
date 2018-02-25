/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 15 de febrero de 2018, 12:51
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * Este es un arch ivos para hacer que  los graficos funcionen....
 */
class grafica{
public:
int x, y;
//estas son las variables de la tabla tengo que hacer en el destructor que se autodestruian
int *vx;
int *vy;
grafica(int ix, int iy){ x = ix; y = iy; vx = new int[x]; vy = new int[y];}; //uso de momoria dinamica
virtual void dibujar(int *ix, int *iy);
};
void grafica::dibujar(int *ix, int *iy){
std::cout << "Las entras son " << ix[0] << "  " << iy[0] << "\n";
int aux;
for(int i = 0; i < x; i++){
std::cout << "i" << i << "\n";
}
for(int i = 0; i < x ; i++){
std::cout << "\n";
	for(int e = 0; e < y; e++){
		if(ix[i] > 5){
		if(iy[e] > 5){
			std::cout << "*";
		}}
		if(ix[i] < 5){
		if(iy[e] < 5){
			std::cout << "-";
		}}
		aux = e;
	}
	std::cout << "aux" << aux;
}
}
void p1(){
int  *ix = new int[5];
int *iy = new int[10];
int x , y;
x = 10;
y = 10;
iy[5] = 10;
ix[5] = 10;
grafica Pg(x, y);
Pg.dibujar(ix, iy);
}
int main(int argc, char** argv) {
	p1();
    	return 0;
}

