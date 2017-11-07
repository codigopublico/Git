/*
  Name: Tablero de Barquitos
  Copyright: (C) Agosto 2003
  Author: Salvador Pozo Coronado
  Date: 16/08/03 17:31
  Description: Centro de control de juego de barquitos.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "const.h"
#include "clases.h"
#include "jugador.h"
#include "jugador1.h"
#include "humano.h"

using namespace std;

// Clase Tablero:
// Contiene la información de un jugador relativa a una partida en juego.
// En un array "celda" se almacenan las posiciones de los barcos, y las
// jugadas, ya sea conteniendo agua o tocados.
// Además se almacena un array de punteros a objetos de tipo Barco, que
// contienen la información relativa a los barcos: coordenadas y estado.
// El interfaz se compone de:
// 1 Tablero: constructor.
//   Las tareas de inicialización se transfieren a la función Iniciar,
//   de modo que no es necesario destruir el objeto para cada partida.
// 2 ~Tablero: destructor, libera el array de barcos.
// 3 Iniciar: prepara el tablero para una nueva partida.
// 4 LeerCelda: lee el contenido de una celda.
// 5 ModificarCelda: modifica el contenido de una celda.
// 6 ColocarBarco: añade un barco leído del jugador al array de barcos y
//   actualiza las celdas correspondientes.
// 7 Colisión: comprueba si hay colisión en la colocación de un barco, a 
//   medida que se piden al jugador.
// 8 Mostrar: muestra el tablero de juego en pantalla.
// 9 ComprobarBarco: verifica si la coordenada indicada pertenece a un
//   barco, y actualiza el objeto de la clase Barco correspondiente. 
// Esta clase se usa durante el juego, y no es accesible a los jugadores.
class Tablero {
  public:
   Tablero() throw(std::bad_alloc);
  ~Tablero();
   void Iniciar() throw(std::bad_alloc);
   contenido LeerCelda(Coordenada) const;
   contenido ModificarCelda(Coordenada, contenido);
   bool ColocarBarco(int, Coordenada, int, direccion) throw(std::bad_alloc);
   bool Colision();
   void Mostrar();
   bool ComprobarBarco(Coordenada);
   
  private:
   contenido celda[cte::ancho][cte::alto];
   Barco **barco; // Array dinámico de punteros de barcos
};

Tablero::Tablero() throw(std::bad_alloc) : barco(NULL) {
   try {
      Iniciar();
   }
   catch(std::bad_alloc) {
      throw;
   }
}

Tablero::~Tablero() {
   for(int i = 0; i < cte::nBarcos; i++)
      if(barco[i]) delete barco[i];
   delete[] barco;
}

void Tablero::Iniciar() throw(std::bad_alloc) {
   // Dejar el tablero libre por completo:
   for(int i = 0; i < cte::ancho; i++)
      for(int j = 0; j < cte::alto; j++)
         celda[i][j] = libre;
   // Borrar array de barcos, si existe:
   if(barco) {
      for(int i = 0; i < cte::nBarcos; i++)
         if(barco[i]) delete barco[i];
      delete[] barco;
   }
   // Crear nuevo array de barcos, vacío:
   try {
      barco = new Barco*[cte::nBarcos];
   }
   catch(std::bad_alloc) {
      throw;
   }
   // Ningún barco existe todavía:
   for(int i = 0; i < cte::nBarcos; i++) barco[i] = NULL;
}

contenido Tablero::LeerCelda(Coordenada coor) const {
   return celda[coor.X()][coor.Y()];
}

contenido Tablero::ModificarCelda(Coordenada coor, contenido cont) {
   if(coor.X() < 0 || coor.X() >= cte::ancho ||
      coor.Y() < 0 || coor.Y() >= cte::alto) return novalido;
   contenido previo = LeerCelda(coor);
   celda[coor.X()][coor.Y()] = cont;
   return previo;
}

bool Tablero::ColocarBarco(int n, Coordenada coor, int lon, direccion dir) 
   throw(std::bad_alloc) {
   // Verificar si el barco cabe.
   try {
      barco[n] = new Barco(coor, lon, dir);
   }
   catch(bad_alloc) {
      throw;
   }
   catch(ErrorBarco) {
      cout << "Error de barco: fuera de tablero" << endl;
      return false;
   }
   return true;   
}   

bool Tablero::Colision() {
   // Verificar colisión.
   for(int n = 0; barco[n] && n < cte::nBarcos; n++) {
      for(int i = 0; i < cte::lBarco[n]; i++) {
         Coordenada c = barco[n]->Posicion(i);
         if(LeerCelda(c) != libre) return true;
      }
      // Agua alrededor
      for(int i = 0; i < cte::lBarco[n]; i++) {
         Coordenada c = barco[n]->Posicion(i);
         ModificarCelda(c, agua);
         c.Incrementar(izquierda);
         c.Incrementar(arriba);
         ModificarCelda(c, agua);
         c.Incrementar(derecha);
         ModificarCelda(c, agua);
         c.Incrementar(derecha);
         ModificarCelda(c, agua);
         c.Incrementar(abajo);
         ModificarCelda(c, agua);
         c.Incrementar(abajo);
         ModificarCelda(c, agua);
         c.Incrementar(izquierda);
         ModificarCelda(c, agua);
         c.Incrementar(izquierda);
         ModificarCelda(c, agua);
         c.Incrementar(arriba);
         ModificarCelda(c, agua);
      }      
   }
   // Iniciar celdas:
   for(int i = 0; i < cte::ancho; i++)
      for(int j = 0; j < cte::alto; j++)
         ModificarCelda(Coordenada(i, j), libre);
   // Colocar barcos:
   for(int n = 0; barco[n] && n < cte::nBarcos; n++) {
      for(int i = 0; i < cte::lBarco[n]; i++) {
         ModificarCelda(barco[n]->Posicion(i), buque);
      }
   }
   return false;
}

bool Tablero::ComprobarBarco(Coordenada coor) {
   // Actualiza la información del barco tocado, si es necesario.
   // Devuelve true si ha sido hundido, false si no es un barco o
   // si sólo ha sido tocado.
   int pos=-1;
   int n=-1;
   
   // Buscamos si la coordenda pertenece a un barco, y en 
   // ese caso, a cual.
   do {
      pos = barco[++n]->Pertenece(coor);
   } while(barco[n] && pos == -1 && n < cte::nBarcos);
   
   if(pos == -1) return false; // No pertenece a ninguno: es agua.
   else {
      barco[n]->Marcar(coor); // marcar como tocado
      return barco[n]->Hundido(); // Devolvemos true si el barco está hundido.
   }
}

void Tablero::Mostrar() {
   for(int j = 0; j < cte::alto; j++) {
      for(int i = 0; i < cte::ancho; i++)
         switch(celda[i][j]) {
            case libre:
               cout << " ";
               break;
            case agua:
               cout << ".";
               break;
            case buque:
               cout << "O";
               break;
            case tocado:
               cout << "X";
               break;
         }
      cout << endl;
   }
   cout << endl;
}

// Clase Torneo:
// Contiene la información de un torneo, compuesto por un número de partidas
// en las que se enfrentarán dos jugadores, alternandose en el comienzo.
// Contiene un array de dos punteros a objetos derivados de la clase base
// abstracta "Jugador", que se reciben como parámetros en el constructor.
// También contiene un array de dos objetos Tablero, para almacenar datos
// durante la partida.
// Un tercer array de enteros almacena el número de partidas ganadas por cada
// jugador.
// El interfaz se compone de:
// 1 Torneo: constructor, inicialización de datos.
// 2 Iniciar: inicia una partida, inicia los tableros y los jugadores y pide
//   los barcos a cada uno.
// 3 Partida: juega una partida completa.
// 4 Resultado: muestra el resultado de partidas ganadas.
//
class Torneo {
  public:
   Torneo(Jugador *j1, Jugador *j2);
   int Iniciar() throw(std::bad_alloc); 
   int Partida(int);
   void Resultado();
   int Ganadas() const;
  private:
   Jugador *jugador[2];
   Tablero tablero[2];
   int ganadas[2];
};

Torneo::Torneo(Jugador *j1, Jugador *j2) {
   jugador[0] = j1;
   jugador[1] = j2;
   ganadas[0] = ganadas[1] = 0;
}
   
// Coloca los barcos, el valor de retorno indica
// 0 no hay errores
// 1 para error de colisión del jugador 0
// 2 para error de colisión del jugador 1
// 3 para error de colisión de ambos
int Torneo::Iniciar() throw(std::bad_alloc) {
   int retorno = 0;
   DatosBarco datosBarco;
   
   // Pedir barcos a jugadores:
   for(int j = 0; j < 2; j++) {
      cout << "jugador " << j+1 << " ";
      try {
         tablero[j].Iniciar();
         jugador[j]->NuevaPartida();
         for(int i = 0; i < cte::nBarcos; i++) {
            datosBarco = jugador[j]->PedirBarco(i);
            if(!tablero[j].ColocarBarco(i, datosBarco.inicio, 
                                        cte::lBarco[i], datosBarco.dir))
               retorno |= (1 << j);
            cout << ".";
         }
         if(tablero[j].Colision()) retorno |= (1 << j);
         cout << endl;
      }
      catch(bad_alloc) {
         throw;
      }
   }
   return retorno;
}

// Enfrenta a los dos jugadores en una partida
// El parámetro indica qué jugador empieza 0/1
// El valor de retorno indica
// 0 no hay errores
// 1 error de jugador 0 (fuera de tablero o repetición)
// 2 error de jugador 1
int Torneo::Partida(int j) {
   // Jugar:
   int activo = j;
   int pasivo = (j+1) % 2;  
   contenido cont;
   Coordenada coor;
   bool salir = false;
   bool error = false;
   int hundidos[2] = {0, 0};
   int aux; // para cambio de turno
   
   do {
      // Turno de jugador
      cout << "Turno de jugador: " << activo+1;
      coor = jugador[activo]->PedirCoordenada();
      cout << ": " << coor.X() << "," << coor.Y() << "...";
      cont = tablero[pasivo].LeerCelda(coor);
      jugador[pasivo]->Informar(coor);
      switch(cont) {
        case tocado:
          cout << "Error: Ya ha disparado en esa celda" << endl;
          jugador[activo]->Responder(coor, novalido);
          error = true;
          break;
        case novalido:
          cout << "Error: Coordenada ilegal" << endl;
          jugador[activo]->Responder(coor, novalido);
          error = true;
          break;
        case buque:
          // Buscar barco y verificar Hundido.
          if(tablero[pasivo].ComprobarBarco(coor)) {
             tablero[pasivo].ModificarCelda(coor, tocado);
             cout << "Hundido";
             hundidos[activo]++;
             cout << " van " << hundidos[activo] << endl;
             jugador[activo]->Responder(coor, hundido);
          } else {
             tablero[pasivo].ModificarCelda(coor, tocado);
             cout << "Tocado" << endl;
             jugador[activo]->Responder(coor, tocado);
          }
          if(hundidos[activo] == cte::nBarcos) salir = true;
          break;
        case agua:
        case libre:
          tablero[pasivo].ModificarCelda(coor, agua);
          cout << "Agua" << endl;
          jugador[activo]->Responder(coor, agua);
          break;
      }
      if(!error) { // Cambio de turno
         aux = activo;
         activo = pasivo;
         pasivo = aux;
      }
      if(salir) cout << "salir" << endl;
      if(error) cout << "error" << endl;
   } while(!salir && !error);
   ganadas[pasivo]++;
   if(!error) return 0; else return activo+1;
}

void Torneo::Resultado() {
   cout << "Resultado del torneo" << endl;
   cout << "Jugador 1: " << ganadas[0] << " partidas ganadas" << endl;
   cout << "Jugador 2: " << ganadas[1] << " partidas ganadas" << endl;
}

int Torneo::Ganadas() const {
   if(ganadas[0] > ganadas[1]) return ganadas[0]; else return ganadas[1];
}

// Programa principal.
int main() {
   int retorno;

   // Iniciar el generador de números aleatorios
   srand(time(NULL));

   // Intentamos crear un torneo de dos jugadores:
   try {
//      Torneo torneo(new Jugador1, new Humano);
      Torneo torneo(new Jugador1, new Jugador1);
  
      for(int i = 0; torneo.Ganadas() < cte::nPartidas; i++) { 
         retorno = torneo.Iniciar();
         // Si retorno es 0, jugamos. Si es 1, 2 ó 3, indica un
         // error de colisión:
         if(retorno == 0) {
            if(torneo.Partida(i % 2)) {
               cout << "error: jugador " << retorno << " ha disparado"
                  " dos veces al mismo barco" << endl;
            }
            else
               torneo.Resultado();
         }
         else {
            if(retorno | 1) cout << "error: jugador 1 ha producido una"
               " colisión de barcos" << endl;
            if(retorno | 2) cout << "error: jugador 2 ha producido una"
               " colisión de barcos" << endl;
         }
      }
   }
   catch(bad_alloc) {
      cout << "Error en asignación de memoria" << endl;
      return 1;
   }
   cin.ignore();
   cin.get();
   return 0;
}
