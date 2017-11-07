/*
  Name: humano.h
  Copyright: (C) Septiembre 2003
  Author: Salvador Pozo
  Date: 24/09/03 20:45
  Description: Cabecera de jugador humano
*/

#include "jugador.h"
#include "clases.h"
#include "const.h"

class Humano : public Jugador {
  public:
   void NuevaPartida();
   DatosBarco PedirBarco(int n); 
   Coordenada PedirCoordenada();
   void Informar(Coordenada);
   void Responder(Coordenada, contenido);
   
  private:
   contenido tablero[2+cte::alto][2+cte::ancho];
   contenido contrario[2+cte::alto][2+cte::ancho];
   Coordenada coor[cte::nBarcos];
   direccion dir[cte::nBarcos];
   
   // Devuleve un valor aleatorio entre min y max-1
   int Alea(int min, int max);
   bool Colision(int); 
};
