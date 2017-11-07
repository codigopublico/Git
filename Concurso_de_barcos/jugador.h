/*
  Name: jugador.h
  Copyright: (C) Septiembre 2003
  Author: Salvador Pozo
  Date: 18/09/03 19:48
  Description: Clase base virtual pura Jugador:
*/

#ifndef B_JUGADOR
#define B_JUGADOR

#include "clases.h"

// Clase virtual pura para diseñar nuevas clases de jugadores.
// Existen cinco funciones virtuales que el programador del jugador
// debe definir:
// 1 
class Jugador {
  public:
   virtual void NuevaPartida()=0; 
   virtual DatosBarco PedirBarco(int n)=0; 
   virtual Coordenada PedirCoordenada()=0;
   virtual void Informar(Coordenada)=0;
   virtual void Responder(Coordenada, contenido)=0;
};

#endif

