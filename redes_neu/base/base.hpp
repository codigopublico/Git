/* 
 * File:   base.hpp
 * Author: iper
 *
 * Created on 18 de marzo de 2018, 17:42
 */

using namespace std;
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <fstream>
#include <cmath>
#include <ctime>
#include <array>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#ifndef BASE_HPP
#define	BASE_HPP
/*
 Esta libreria tendra que tener una classe llamada red neurinal es para luego hacer
 * que nada mas disiendole que entrene i resultados haga lo dicho
 * Total una red neuronal que se adaptara automaticamente a la cantidad de imputs
 * i dificultad de resolver el problema. 
 */
using namespace std;
void prueva_lib(){
    std::cout << "La libreria funciona\n";
}

class red{
public:
	//variables de la red neuronal
	int Nneu;//este es el numero de neuronas
	float intervalos[19];
	float aprendizaje[9];
	float Umbral,defumbral;
	int i;
	int x1[5]; //este se tiene que pasar como el otro In i se tiene que pasar con doble 
	int x2[5]; //la variable para substituir este es In. Tiene que ser una matriz de dos dinmeciones
	int result[5];
	float *w;
	//fin
    int **In;
    int *Ou;
    int au;
    int au2;
    red(int *I, int *O, int &aux, int &aux2){
    
    //varaibles de la red neuronal...
 
 	   intervalos ={-0.98,-0.876,-0.654,-0.754,0.453,0.953,-0.322,-0.298,-0.11,-0.065,0.0234,0.232,0.2335,0.4674,0.675,0.7883, 0.752,0.823,0.9876}; //aqui tengo un error.... tengo que mirar como hacer para hacer que funcione bien los arrays de float a ver que pasa
	aprendizaje = {0.0234,0.232,0.2335,0.4674,0.675,0.7883, 0.752,0.823,0.9876};
    	Nneu = 200;
    	w = new float[Nneu];
    
    //fin
    
    
    //el I es para el numero de imputs  el O es para los ouptus el aux es para saber el total de imputs i ouputs 
    // el aux2 es para hacer los bloques de datos de I 
    int q = 0;
    In = new int*[aux];
    Ou = O;
    int z = 0;
    In[0] = new int[aux2];
    for(int i = 0; i < aux; i++){
        if(aux2 > q){
        q++;
	//std::cout << "  " << q << "  " << aux2 << "\n" ;
        }
        if(aux2 <= q){
            std::cout << "Este es un grupo de datos\n" << "numero " << z <<  "\n";
            q = 0;
	    z++;
	    In[z] = new int[aux2];
        }
        std::cout << " I ";
        In[z][q] = I[i];
	std::cout << In[z][q] << " "  <<  z << " " << q <<  "\n";
        }
	au = q;
	au2 = z;
   }

private:
   
/*
 * Este es un programa que simula dos neuronas.float alpha = aprendizaje[rand() % 9];
 */
	
	//este es para hacer que funcione todo lo anterior ...
	//nada mas falta exportar todas las variables i ya........
void learn(){
	for(int ui = 0; ui < Nneu; ui++){
		w[ui] = intervalos[rand() % 18],intervalos[rand() % 18]; //este es numero aletorio de cada neurona
	}
	float alpha = aprendizaje[rand() % 9];
	Umbral = intervalos[rand() % 18];
	defumbral = 1;
	int verdad = 0;
	int op;
	int cont = 0;
	int n = 0;
	int qw = 0;
//////////// ENTRENAMIENTO DEL PERCEPTRON;
/////////// se tendria que hacer que averiguar como crear las neuronas de forma dinamica
	while(verdad == 0){
		n++;
		for(i=0;i<5;i++){//este es para recorrer los imputs
			op = (defumbral*Umbral);
                        for(int ui = 0; ui < Nneu; ui++){
                                //op = x1[i]*w[ui] + op;
                                //op = x2[i]*w[ui] + op;//este tiene que ser un sub indice para poder hacer tal fin
                                //seria de este forma:
                                for(int zi = 0; zi < au2; zi ){
                                op = In[zi][i]*w[ui] + op;//creo que seria de este modo .... Nose
                                }
                        }
			//op = ((x1[i]*w[0])+(x2[i]*w[1])) + (defumbral*Umbral);//esta es la original
			if(op >= 0){
				op = 1;
			}
			else{
				op = -1;
			}
			if(op != result[i]){
				for(int ui = 0; ui < Nneu; ui++){
					w[ui] = w[ui] + (2*alpha)*(x1[i]*result[i]);
				}
				//w[0] = w[0] + (2*alpha)*(x1[i]*result[i]);//estas son las dos funciones madres
				//w[1] = w[1] + (2*alpha)*(x2[i]*result[i]);//aqui tiene que ir la memria dinamica
				Umbral = Umbral + (2*alpha)*(defumbral*result[i]);
			}
		}
		for(i=0;i<5;i++){
			//op = ((x1[i]*w[0])+(x2[i]*w[1])) + (defumbral*Umbral);//esta es la funcion madre de creacion de neuronas
			op = (defumbral*Umbral);
                        for(int ui = 0; ui < Nneu; ui++){
                                //op = x1[i]*w[ui] + op;
                                //op = x2[i]*w[ui] + op;//este tiene que ser un sub indice para poder hacer tal fin
                                //seria de este forma:
                                for(int zi = 0; zi < au2; zi ){
                                op = In[zi][i]*w[ui] + op;//creo que seria de este modo .... Nose
                                }
                        }//de este es para recorrer todos los datos
			if(op >= 0){
                                op = 1;
                        }
                        else{
                                op = -1;
                        }
			if(op == result[i]){
				cont++;
			}
			if(cont == 10){
				verdad = 1;
			}
		}
		if(n > 100){
			//printf("[!] Demasiadas epocas realizadas!\n");
			//printf("[!] Intente nuevamente con otros pesos sinapticos.\n");
			float alpha = aprendizaje[rand() % 9];
			qw++;
		}
		if(qw > 1000000){
			std::cout << "Mierda!!!!!!!!!!!!!!!\n";
		}
		if(qw > 1000000){
			break;
		}
	}
	}
void print(){
/////////// MOSTRAR RESULTADOS FINALES
	int op;
	system("clear");
	printf("\n[*] FINALIZANDO ENTRENAMIENTO...\n");
	printf("[*] PERCEPTRON SIMPLE [ENTRENADO]\n");
	printf("\n--------------- DATOS FINALES --------------------------------\n\n");
	printf("[*] Total de epocas: (%i)\n",au);//esta varable no esta bien
	for(int ui = 0; ui < Nneu; ui++){
	printf("[*] Peso Sinaptico 1 w[1]\t\t--> %2.2f\n",w[ui]);
}
	printf("[*] Umbral(Polarizacion)\t\t--> %2.2f\n",Umbral);
	printf("\n\n--------------- VERFICIACION DE ENTRENAMIENTO ------------------\n\n");
	for(i=0;i<5;i++){
		//op = ((x1[i]*w[0])+(x2[i]*w[1])) + (defumbral*Umbral);
			op = (defumbral*Umbral);
                        for(int ui = 0; ui < Nneu; ui++){
                                //op = x1[i]*w[ui] + op;
                                //op = x2[i]*w[ui] + op;//este tiene que ser un sub indice para poder hacer tal fin
                                //seria de este forma:
                                for(int zi = 0; zi < au2; zi ){
                                op = In[zi][i]*w[ui] + op;//creo que seria de este modo .... Nose
                                }
                        }
		if(op >= 0){
			op = 1;
		}
		else{
			op = -1;
			}
		printf("\n[*] Entradas: (%2i,%2i) --> Salida: %2i",x1[i],x2[i],op);
		if(op != result[i]){
			//system("clear");
			printf("\n[!] Error \n");
			//printf("[!] Intente nuevamente con otros pesos sinapticos.\n");
			//exit(1);
			//Perceptron();
			}
	}
}

};


#endif	/* BASE_HPP */

