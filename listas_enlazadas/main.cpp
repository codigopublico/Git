//la cosa es haber si puedo mezclar las listas_enlazadas i ademas encapularlo en una classe. 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <iostream>
#include <string>
/*
En ningun momento esta usando el operador new para hacer la lista.....
*/
struct datos{
std::string titulo;
std::string autor;
    /*datos operator=(const datos &a){
        datos d;
        d.duracion = a.duracion;
        d.nivel = a.nivel;
        return d;
    }*/
int nivel;
int duracion;
//bool single;
};
struct lista{
struct datos dato;
struct lista *sig;
};
struct lista *creanodo(void) {
  return (struct lista *) malloc(sizeof(struct lista));
}
//hasta aqui es donde se define la lista....
struct lista *insertarfinal(struct  lista *l, struct datos x){
struct lista *q;
struct lista *p;
q = creanodo();
q->dato = x;
q->sig = NULL; 
if(l == NULL){
	return q;
}
while (p->sig == NULL){//esta funcion hace que se recorra la lista hasta que se acabe cuando retorn NULL
	p = p->sig;
}
p->sig = q;
return l;
};

struct lista *insertarcomienzo(struct lista *l, struct datos x){
	struct lista *q; 
        struct lista *p;
	q = creanodo();
	q->dato = x;
	q->sig = l;
	l = q;
	return l;
};
struct lista *pop(struct lista *l, struct datos x){
	if( l != NULL){//esto es para combrovar que la lista no esta vacia.
	struct lista *q;
        struct lista *p;
	p = l;
	q = p->sig;
	x = p->dato;
	free(p);
	l = q;
	return l;
	}
};
int compura(datos x, datos y){
int i = 1;
if(x.duracion == y.duracion){
	i = 0;
}
return i;
}//esta funcion en el programa madre de se llama alfavetica
int Icompura(datos x, datos y){
    int i = 0;
    if(x.duracion > y.duracion){
        return -1;
    }
    if(x.duracion < y.duracion){
        return 1;
    }
    
}


struct lista *elimina(struct lista *p, struct datos x, int (*f)(struct datos a, struct datos b)){//Se elimenara en base a la duracion.
int cond;
if(p == NULL){
	return p;
}
cond = (*f)(x, p->dato);
if(cond == 0){
	struct lista *q;
	q = p->sig;
	free(p);
	p = q;
}else{
	p->sig = elimina(p->sig, x,f);
}
return p;
};
void imprimelista(struct lista *l) {
  struct lista *p;
  p = l;
  while (p != NULL) {
    printf("Duracion:   ");
    printf("%d\n",p->dato.duracion);
    printf("Nivel:       ");
    printf("%d\n",p->dato.nivel);
    p = p->sig;
    for(int i = 0; i < 1; i++){
        std::cout << "\n|\n";
    }
  }
}
int menu(){
int opcion;
  printf("\n");
  printf("1) Insertar en la lista.\n");
  printf("2) Borrar de la lista.\n");
  printf("3) Imprimir la lista.\n");
  printf("0) Para salir de la lista\n");
  do {
    printf("Introduzca opción (1,2,3), 0 (cero) para salir: ");
    std::cin >> opcion;
  } while (opcion < 0 || opcion > 3);
  printf("\n");
  return opcion;
}
struct datos tomadatos(void){
    struct datos a;
    int dura;
    int nivel;
    printf("Dime la duracion de la cancion:    ");
    std::cin >> dura;
    printf("Dime el nivel de sonido de la cancion:     ");
    std::cin >> nivel;
    a.duracion = dura;
    a.nivel = nivel;
    return a;
}//Esta funcion es para hacer que se lean los datos
struct lista *insertardato(struct lista *l, struct datos x, int (*f)(struct datos a, struct datos b)){
    struct lista *p;
    struct lista  *q;
    struct lista *ant;
    int ind;
    q = creanodo();
    q->dato = x;
    q->sig = NULL;
    if(l == NULL){
        l = q;
        return l;
    }
    ant = NULL;
    p = l;
    ind = 0;
   while (p != NULL && ind == 0) {
    if ((*f)(x,p->dato) <= 0) /* aquí hay que insertar aqui es donde se implementa la funcionde comparacion */
      ind = 1;
    else {
      ant = p;
      p = p->sig;
    }
  }
  if (ant == NULL) { /* inserción al comienzo */
    q->sig = l;
    l = q;
  } else { /* inserción en medio o al final */
    ant->sig = q;
    q->sig = p;
  }
  return l;
};
int main (int argc, char *argv[]) {//comienzo del main
int i;
struct lista *l;
struct datos x;
do{ 
    
    i = menu();
    for(int e = 0; e < 5; e++){
    for(; e < 100; e++ ){
            std::cout << "\n";
        }
    }
    if(i == 1){
        x = tomadatos();
        l = insertardato(l,x, Icompura);
    }
    if(i == 2){
        int n;
        printf("Dime la duracion a eliminar:   ");
        std::cin >> n;
        x.duracion = n;
        x.nivel = 0;
        l = elimina(l, x, compura);
    }
    if(i == 3){
        imprimelista(l);
    }

}while(i != 0);

}