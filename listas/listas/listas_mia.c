//la cosa es haber si puedo mezclar las listas_enlazadas i ademas encapularlo en una classe. 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
//#include <string>
/*
En ningun momento esta usando el operador new para hacer la lista.....
*/
struct datos{
//string titulo;
//string autor;
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
struct lista *q *p;
q = creandonodo();
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
	struct lista *q *p;
	q = creandonodo();
	q->dato = x;
	q->sig = l;
	l = q;
	return l;
};
struct lista *pop(struct lista *l, struct datos *x){
	if( l != NULL){//esto es para combrovar que la lista no esta vacia.
	struct lista *q *p;
	p = l;
	q = p->sig;
	*x = p->sig;
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


struct lista *elimina(struct lista *p, struct datos x, int (*f)(struct datos a, struct datos b)){//Se elimenara en base a la duracion.
int cond;
if(p == NULL){
	return p;
}
cond = (*f)(x, p->datos);
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
int menu(){
int opcion;
  printf("\n");
  printf("1) Insertar en la lista.\n");
  printf("2) Borrar de la lista.\n");
  printf("3) Imprimir la lista.\n");
  do {
    printf("Introduzca opción (1,2,3,4 o 5), 0 (cero) para salir: ");
    scanf("%d",&opcion);
  } while (opcion < 0 || opcion > 5);
  printf("\n");
  return opcion
}
int main (int argc, char *argv[]) {//comienzo del main
int i = menu();

}


void 
