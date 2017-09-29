/*
  Name: Jugador1.h
  Copyright: (C) Septiembre 2003
  Author: Salvador Pozo
  Date: 18/09/03 20:12
  Description: Cabecera de Jugador1, de prueba
*/

#include "jugador.h"
#include "clases.h"
#include "const.h"

class Jugador1 : public Jugador {
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
