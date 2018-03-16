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
struct punt{
int x;
int y;
}p;
class grafica{
public:
int x, y;
//estas son las variables de la tabla tengo que hacer en el destructor que se autodestruian
int *vx;
int *vy;
grafica(int ix, int iy){ x = ix; y = iy; vx = new int[x]; vy = new int[y];}; //uso de momoria dinamica
virtual void dibujar(punt *in);
};
void grafica::dibujar(punt *in){
std::cout << "Las entras son " << in->x << "  " << in->y << "\n";
int aux;
for(int i = 0; i < x; i++){
std::cout <<  i << " ";
}
for(int i = 0; i < x ; i++){
std::cout << "\n";
	for(int e = 0; e < y; e++){
		if(in->x == i && in->y == e){
			std::cout << i << " ";
		}
		if(in->x != i || in->y != e){
			std::cout << "- ";
		}
		aux = e;
	}
	std::cout << "aux" << i;
}
}
void p1(){
	int  *ix = new int[10];//aqi estava el error !!!!!!!!!!!!
	int *iy = new int[10];
	int x , y;
	x = 20;
	y = 20;
	//punt *in;
	punt *in = new punt[5];
	in->x = 5;
	in->y = 9;
	grafica Pg(x, y);
	Pg.dibujar(in);
}
int main(int argc, char** argv) {
	p1();
    	return 0;
}

