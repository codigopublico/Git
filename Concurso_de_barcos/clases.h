/*
  Name: Clases.h
  Copyright: (C) Septiembre 2003
  Author: Salvador Pozo
  Date: 18/09/03 20:00
  Description: Clases y tipos auxiliares
*/

#ifndef B_CLASES
#define B_CLASES

#include <iostream>

// Tipos enumarados para codificar direcciones y contenidos:
enum direccion {derecha=0, abajo, izquierda, arriba};
enum contenido {libre=0, agua, buque, tocado, hundido, novalido};

// Clase Coordenada, encapsula coordenadas en 2D.
class Coordenada {
  public:
   Coordenada(int _x=0, int _y=0) : x(_x), y(_y) {}
   Coordenada operator+(const Coordenada &c) {
      Coordenada temp;
      temp.x += x + c.x;
      temp.y += y + c.y;
      return temp;
   }
   bool operator==(const Coordenada &c) {
      return (x == c.x) && (y == c.y);
   }
   void Incrementar(direccion, int=1);
   int X() const {return x;}
   int Y() const {return y;}
  private:
   int x;
   int y;
};

// Estructura para pedir datos de un barco al jugador.
// Incluye la coordenada de inicio y la dirección a partir de ella.
struct DatosBarco {
   Coordenada inicio;
   direccion dir;
};

// Clase ErrorBarco, derivada de exception, sirve para
// generar excepciones por errores en colocación en barcos.
class ErrorBarco: public std::exception {
  public:
   ErrorBarco() : exception() {}
   const char* what() const throw() {
      return "Barco fuera de tablero";
   } 
};

// Clase Barco
class Barco {
  public:
   Barco(Coordenada c, int l, direccion d) throw(ErrorBarco, std::bad_alloc);
  ~Barco();
   // Devuelve -1 si la coordenada no pertenece al barco
   // o la posición si pertenece
   int Pertenece(Coordenada c) const;
   Coordenada Posicion(int) const;
   void Marcar(Coordenada);
   bool Hundido() const;
  private:
   int longitud;
   Coordenada *posicion;
   bool *estado;
};

#endif

