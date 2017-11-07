/*
  Name: jugador1.cpp
  Copyright: (C) Septiembre 2003
  Author: Salvador Pozo
  Date: 18/09/03 19:51
  Description: Clase derivada de Jugador para probar estrategias
*/

#include <cstdlib>
#include <cstring>
#include "jugador1.h"

void Jugador1::NuevaPartida() {
   // Inicializar arrays:  
   for(int y = 0; y < cte::alto+2; y++)
      for(int x = 0; x < cte::ancho+2; x++) {
         contrario[x][y] = libre;
         tablero[x][y] = libre;
      }

   // Colocar barcos:
   for(int i = 0; i < cte::nBarcos; i++) {
      // Para cada barco elegir una dirección: derecha o abajo
      // y unas coordenadas válidas según la dirección y el tamaño
      // repetir hasta que el barco entre:
      do {
         if(Alea(0, 2)) {
            dir[i] = derecha;
            coor[i] = Coordenada(Alea(1, 1+cte::ancho-cte::lBarco[i]), 
                                 Alea(1, 1+cte::alto));
         }
         else {
            dir[i] = abajo;
            coor[i] = Coordenada(Alea(1, 1+cte::ancho), 
                                 Alea(1, 1+cte::alto-cte::lBarco[i]));
         }
      } while(Colision(i));
      if(dir[i] == derecha)
         for(int j = -1; j < cte::lBarco[i]+1; j++) {
            tablero[coor[i].X()+j][coor[i].Y()-1] = buque;
            tablero[coor[i].X()+j][coor[i].Y()] = buque;
            tablero[coor[i].X()+j][coor[i].Y()+1] = buque;
         }
      else
         for(int j = -1; j < cte::lBarco[i]+1; j++) {
            tablero[coor[i].X()-1][coor[i].Y()+j] = buque;
            tablero[coor[i].X()][coor[i].Y()+j] = buque;
            tablero[coor[i].X()+1][coor[i].Y()+j] = buque;
         }
   }
   for(int y = 0; y < cte::alto+2; y++)
      for(int x = 0; x < cte::ancho+2; x++)
         tablero[x][y] = libre;
}

bool Jugador1::Colision(int n) {  
   if(dir[n] == derecha) {
      for(int i = 0; i < cte::lBarco[n]; i++) 
         if(tablero[coor[n].X()+i][coor[n].Y()]) return true;
   } else {
      for(int i = 0; i < cte::lBarco[n]; i++)
         if(tablero[coor[n].X()][coor[n].Y()+i]) return true;
   }
   return false;
}

int Jugador1::Alea(int min, int max) {
   int valores = max - min;
   
   return min + valores*rand()/(RAND_MAX+1);
}

DatosBarco Jugador1::PedirBarco(int n) {
   DatosBarco actual;
   
   actual.inicio = Coordenada(coor[n].X()-1, coor[n].Y()-1);
   actual.dir = dir[n];
   return actual;
}

Coordenada Jugador1::PedirCoordenada() {
   Coordenada c;
   
   do {
      c = Coordenada(Alea(0, cte::ancho), Alea(0, cte::alto));
   } while(contrario[c.X()+1][c.Y()+1]);
   return Coordenada(c.X(), c.Y());
}

void Jugador1::Responder(Coordenada c, contenido cont) {
   if(cont == tocado || cont == hundido) {
      contrario[c.X()][c.Y()] = agua;
      contrario[c.X()+2][c.Y()] = agua;
      contrario[c.X()+2][c.Y()+2] = agua;
      contrario[c.X()][c.Y()+2] = agua;
      contrario[c.X()+1][c.Y()+1] = tocado;
      if(cont == hundido) {
         Coordenada c2;
         // Buscar y cerrar extremos del barco
         // Buscar primer agua o libre hacia arriba:
         c2 = Coordenada(c.X()+1, c.Y());
         while(contrario[c2.X()][c2.Y()] == tocado) c2.Incrementar(arriba, 1);
         contrario[c2.X()][c2.Y()] = agua;
         // Buscar primer agua o libre hacia derecha:
         c2 = Coordenada(c.X()+2, c.Y()+1);
         while(contrario[c2.X()][c2.Y()] == tocado) c2.Incrementar(derecha, 1);
         contrario[c2.X()][c2.Y()] = agua;
         // Buscar primer agua o libre hacia abajo:
         c2 = Coordenada(c.X()+1, c.Y()+2);
         while(contrario[c2.X()][c2.Y()] == tocado) c2.Incrementar(abajo, 1);
         contrario[c2.X()][c2.Y()] = agua;
         // Buscar primer agua o libre hacia izquierda:
         c2 = Coordenada(c.X(), c.Y()+1);
         while(contrario[c2.X()][c2.Y()] == tocado) c2.Incrementar(izquierda, 1);
         contrario[c2.X()][c2.Y()] = agua;
      }
   }
   else {
      contrario[c.X()+1][c.Y()+1] = cont;
   }
}

void Jugador1::Informar(Coordenada c) {
   // Esto sólo es para saber dónde dispara el enemigo
   // y cómo está nuestra flota, pero no influye en el
   // juego para nada.
}

