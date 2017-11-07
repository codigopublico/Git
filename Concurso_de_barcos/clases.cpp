/*
  Name: clases.cpp
  Copyright: (C) Septiembre 2002
  Author: Salvador Pozo
  Date: 18/09/03 20:02
  Description: Implementación de clases auxiliares
*/

#include "clases.h"
#include "const.h"

void Coordenada::Incrementar(direccion dir, int n) {
   switch(dir) {
      case derecha: 
         x+=n; break;
      case izquierda: 
         x-=n; break;
      case abajo:
         y+=n; break;
      case arriba:
         y-=n; break;
   }
}

Barco::Barco(Coordenada c, int l, direccion dir)
  throw(ErrorBarco, std::bad_alloc) : 
  longitud(l) {
   // Sólo se pueden construir barcos válidos
   // Verificamos si el barco cabe en el tablero:
   Coordenada final;
   switch(dir) {
      case derecha: 
         final = c + Coordenada(l-1, 0); break;
      case izquierda: 
         final = c + Coordenada(-l+1, 0); break;
      case abajo:
         final = c + Coordenada(0, l-1); break;
      case arriba:
         final = c + Coordenada(0, -l+1); break;
   }
   if(final.X() >= cte::ancho || final.Y() >= cte::alto ||
      final.X() < 0 || final.Y() < 0) throw ErrorBarco();
   try {
      posicion = new Coordenada[longitud];
      estado = new bool[longitud];
   }
   catch(std::bad_alloc) {
      throw;
   }
   for(int i = 0; i < longitud; i++) {
      posicion[i] = c;
      posicion[i].Incrementar(dir, i);
      estado[i] = true;
   }
}

Barco::~Barco() {
  delete[] posicion;
  delete[] estado;
}

int Barco::Pertenece(Coordenada c) const {
   for(int i = 0; i < longitud; i++)
      if(posicion[i] == c) return i;
   return -1;
}

Coordenada Barco::Posicion(int x) const {
   if(x >= 0 && x < longitud) return posicion[x];
   return Coordenada(-1,-1);
}

void Barco::Marcar(Coordenada c) {
   int p = Pertenece(c);
   if(p != -1) estado[p] = false; // Tocado
}
 
bool Barco::Hundido() const {
   bool h = false;
   for(int i = 0; i < longitud; i++) h |= estado[i];
   return !h;
}

