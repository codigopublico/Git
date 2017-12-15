#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#define nomardatos "diezprimeros.txt"
#define ANCHOMEMI 300 /* ancho de la memoria intermedia */
#define ANCHOPANT 80 /* ancho de la pantalla por defecto */

int anchura = ANCHOPANT;

struct fecha {
  int dia;
  int mes;
  int anio;
};
  
struct dato {
  char nombre[20];
  char dni[20];
  struct fecha fechanac;
};

struct lista { /* lista simple enlazada */
  struct dato datos;
  struct lista *sig;
};

struct longydir {
  int lgmax; /* longitud máxima del nodo */
  struct dato *p; /* puntero al dato */
};

struct lista *creanodo(void) {
  return (struct lista *) malloc(sizeof(struct lista));
}

/* Inserta dato al final de la lista (para colas) */
struct lista *insertafinal(struct lista *l, struct dato x) {
  struct lista *p,*q;
  q = creanodo(); /* crea un nuevo nodo */
  q->datos = x; /* copiar los datos */
  q->sig = NULL;
  if (l == NULL)
    return q;
  /* la lista argumento no es vacía. Situarse en el último */
  p = l;
  while (p->sig != NULL)
    p = p->sig;
  p->sig = q;
  return l;
}

/* Inserta dato al comienzo de la lista (para pilas) */
struct lista *insertacomienzo(struct lista *l, struct dato x) {
  struct lista *p,*q;
  q = creanodo(); /* crea un nuevo nodo */
  q->datos = x; /* copiar los datos */
  q->sig = l;
  l = q;
  return l;
}

/* Extrae dato al comienzo de la lista (para pilas y colas) */
struct lista *pop(struct lista *l, struct dato *x) {
  if (l != NULL) { /* no hacer nada si l es nula */
    struct lista *p,*q;
    p = l;
    q = p->sig; /* para no perder el enlace */
    *x = p->datos; /* copiar el dato */
    free(p); /* libera memoria */
    l = q;
    return l;
  }
}

/*
  Inserta un dato en una lista ordenada.
  La nueva lista debe quedar ordenada
  f es la función de ordenación
*/
struct lista *insertaordenado(struct lista *l, struct dato x, int (*f)(struct dato a, struct dato b)) {
  struct lista *p,*q,*ant;
  int ind;
  q = creanodo(); /* crea un nuevo nodo */
  q->datos = x; /* copiar los datos */
  q->sig = NULL; /* por defecto, puede cambiar */
  if (l == NULL) {
    l = q;
    return l;
  }
  /* la lista no es nula */
  ant = NULL;
  p = l;
  ind = 0;
  while (p != NULL && ind == 0) {
    if ((*f)(x,p->datos) <= 0) /* aquí hay que insertar */
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
}

struct lista *elimina(struct lista *p, struct dato x, int (*f)(struct dato a, struct dato b)) {
  int cond;
  if (p == NULL) /* no hay nada que borrar */
    return p;
  /* compara el dato */
  cond = (*f)(x,p->datos);
  if (cond == 0) { /* encontrado! */
    struct lista *q;
    q = p->sig;
    free(p); /* libera la memoria y hemos perdido el enlace, por eso se guarda en q */
    p = q; /* restaurar p al nuevo valor */
  } else /* no encontrado */
    p->sig = elimina(p->sig,x,f); /* recurre */
  return p;
}

/* Devuelve la longitud de una lista */
int longitudl(struct lista *l) {
  struct lista *p;
  int n;
  n = 0;
  p = l;
  while (p != NULL) {
    ++n;
    p = p->sig;
  }
  return n;
}

/* anula una lista liberando la memoria */
struct lista *anulalista(struct lista *l) {
  struct lista *p,*q;
  p = l;
  while (p != NULL) {
    q = p->sig; /* para no perder el nodo */
    free(p);
    p = q;
  }
  return NULL;
}

/* lee los datos de un archivo y construye la pila */
struct lista *leedatos(char *nomfich, int *vret) {
  int ind,i;
  struct lista *l;
  struct dato x;
  FILE *fp;
  fp = fopen(nomfich,"r");
  if (fp == NULL) {
    *vret = 0;
    return NULL;
  }
  l = NULL;
  ind = 1;
  while (ind) {
    i = fscanf(fp,"%s",x.nombre);
    if (i == EOF)
      ind = 0;
    else {
      fscanf(fp,"%s",x.dni);
      fscanf(fp,"%d/%d/%d",&(x.fechanac.dia),&(x.fechanac.mes),&(x.fechanac.anio));
      l = insertacomienzo(l,x);
    }
  }
  fclose(fp);
  *vret = 1;
  return l;
}

/* funciones de ordenación */
int comparafecha(struct dato x, struct dato y) {
  int u[3],v[3],i;
  u[0] = x.fechanac.anio;
  u[1] = x.fechanac.mes;
  u[2] = x.fechanac.dia;

  v[0] = y.fechanac.anio;
  v[1] = y.fechanac.mes;
  v[2] = y.fechanac.dia;

  for (i = 0; i < 3; ++i) {
    if (u[i] < v[i])
      return -1;
    if (u[i] > v[i])
      return 1;
  }
  return 0;
}

int comparafechainversa(struct dato x, struct dato y) {
  return (-1)*comparafecha(x,y);
}

int alfabetica(struct dato x, struct dato y) {
  int i;
  i = strcasecmp(x.nombre,y.nombre);
  return i;
}

int alfabeticainversa(struct dato x, struct dato y) {
  return (-1)*alfabetica(x,y);
}

/* Imprimir la lista */
void imprimelista(struct lista *l) {
  struct lista *p;
  p = l;
  while (p != NULL) {
    printf("%s\n",p->datos.nombre);
    printf("%s\n",p->datos.dni);
    printf("%d-%d-%d\n\n",p->datos.fechanac.dia,p->datos.fechanac.mes,p->datos.fechanac.anio);
    p = p->sig;
  }
}

void centracad(char *cadena, int ancho, char *d) {
  int r,l,i,j;
  l = strlen(cadena);
  r = (ancho - l)/2;
  for (i = 0; i < r; ++i)
    d[i] = ' ';
  for (j = 0; j < l; ++j) {
    d[i] = cadena[j];
    ++i;
  }
  for (j = 0; j < ancho - r - l; ++j) {
    d[i] = ' ';
    ++i;
  }
  d[i] = '\0';
}

void procesanodos(struct longydir *lg, int nodoini, int nodofin, int indfinal) {
  char auxiliar[ANCHOMEMI],auxi[50];
  int i,j,m,k,ind;
  /* primera fila */
  for (i = nodoini; i <= nodofin; ++i) {
    m = lg[i].lgmax;
    printf("+");
    for (k = 0; k < m + 2; ++k)
      printf("-");
    printf("+");
    ind = 1; /* poner los espacios */
    if (i == nodofin) {
      if (indfinal == 0)
	ind = 0;
    }
    if (ind) { /* poner los espacios */
      for (k = 0; k < 4; ++k)
	printf(" ");
    }
  }
  printf("\n");
  /* fila del nombre */
  for (i = nodoini; i <= nodofin; ++i) {
    m = lg[i].lgmax;
    centracad(lg[i].p->nombre,m + 2,auxiliar);
    printf("|%s|",auxiliar);
    ind = 1; /* poner los espacios */
    if (i == nodofin) {
      if (indfinal == 0)
	ind = 0;
    }
    if (ind) { /* poner los espacios */
      for (k = 0; k < 4; ++k)
	printf(" ");
    }
  }
  printf("\n");
  /* fila del dni */
  for (i = nodoini; i <= nodofin; ++i) {
    m = lg[i].lgmax;
    centracad(lg[i].p->dni,m + 2,auxiliar);
    printf("|%s|",auxiliar);
    ind = 1; /* poner los espacios */
    if (i == nodofin) {
      if (indfinal == 0)
	ind = 0;
    }
    if (ind) { /* poner los espacios */
      printf(" -> ");
    }
  }
  printf("\n");

  /* fila de la fecha */
  for (i = nodoini; i <= nodofin; ++i) {
    sprintf(auxi,"%d/%d/%d",lg[i].p->fechanac.dia,lg[i].p->fechanac.mes,lg[i].p->fechanac.anio);
    m = lg[i].lgmax;
    centracad(auxi,m + 2,auxiliar);
    printf("|%s|",auxiliar);
    ind = 1; /* poner los espacios */
    if (i == nodofin) {
      if (indfinal == 0)
	ind = 0;
    }
    if (ind) { /* poner los espacios */
      for (k = 0; k < 4; ++k)
	printf(" ");
    }
  }
  printf("\n");

  /* última fila (igual que la primera) */
  for (i = nodoini; i <= nodofin; ++i) {
    m = lg[i].lgmax;
    printf("+");
    for (k = 0; k < m + 2; ++k)
      printf("-");
    printf("+");
    ind = 1; /* poner los espacios */
    if (i == nodofin) {
      if (indfinal == 0)
	ind = 0;
    }
    if (ind) { /* poner los espacios */
      for (k = 0; k < 4; ++k)
	printf(" ");
    }
  }
  printf("\n");
}

void imprimenombres(struct lista *l) {
  int i,j,k,m,nn,ind,s,indfinal,np,p;
  struct longydir *lg;
  struct lista *q;
  char auxiliar[ANCHOMEMI];
  if (l != NULL) {
    /* Calcular longitudes máximas y direcciones de los datos y almacenarlas en un vector */
    nn = longitudl(l); /* longitud de la lista */
    lg = (struct longydir *)malloc(nn * sizeof(struct longydir)); /* vector para almacenar longitudes y direcciones */
    q = l;
    i = 0;
    while (q != NULL) {
      /* calcular la longitud máxima del nodo actual */
      k = strlen(q->datos.nombre);
      m = strlen(q->datos.dni);
      if (m > k)
	k = m;
      sprintf(auxiliar,"%d/%d/%d",q->datos.fechanac.dia,q->datos.fechanac.mes,q->datos.fechanac.anio);
      m = strlen(auxiliar);
      if (m > k)
	k = m;
      lg[i].lgmax = k; /* asignar el máximo */
      lg[i].p = &(q->datos);
      ++i;
      q = q->sig;
    }
    /* Procesar los nodos */
    i = 0;
    k = 0;
    while (i < nn) {
      s = 0;
      indfinal = 1; /* por defecto hay que poner el enlace al final */
      ind = 1;
      np = 0; /* número de nodos a procesar */
      while (ind && k < nn) {
	if (k == nn - 1)
	  p = 4 + lg[k].lgmax; /* necesito este espacio */
	else
	  p = 8 + lg[k].lgmax; /* necesito este espacio */
	if (s + p <= anchura) { /* este nodo cabe */
	  s += p;
	  ++np;
	  indfinal = (k == nn - 1) ? 0 : 1;
	  ++k;
	} else /* no cabe */
	  ind = 0;
      }
      if (np == 0) { /* nodo demasiado grande, overflow, procesarlo aunque se salga de la pantalla */
	np = 1;
	++k;
      }
      procesanodos(lg,i,i + np -1,indfinal);
      i += np;
    }
    free(lg); /* libera memoria */
  }
} /* fin de la función */

struct dato tomadatos(void) {
  struct dato x; /* dato a retornar */
  char nombre[20];
  char dni[20];
  int dia;
  int mes;
  int anio;
  printf("Introduce nombre: ");
  scanf("%s",nombre);
  printf("Introduce dni: ");
  scanf("%s",dni);
  printf("Introduce fecha de nacimiento en la forma \"dia/mes/año\": ");
  scanf("%d/%d/%d",&dia,&mes,&anio);
  strcpy(x.nombre,nombre);
  strcpy(x.dni,dni);
  x.fechanac.dia = dia;
  x.fechanac.mes = mes;
  x.fechanac.anio = anio;
  return x;
}

int menuprograma(void) {
  int opcion;
  printf("\n");
  printf("1) Insertar en la pila.\n");
  printf("2) Extraer de la pila.\n");
  printf("3) Imprimir la pila.\n");
  printf("4) Mostrar la pila gráficamente.\n");
  printf("5) Anular la pila.\n");
  do {
    printf("Introduzca opción (1,2,3,4 o 5), 0 (cero) para salir: ");
    scanf("%d",&opcion);
  } while (opcion < 0 || opcion > 5);
  printf("\n");
  return opcion;
}

void muestrauso(char *programa) {
  printf("Uso: %s opciones [ argumentos ...]\n",programa);
  printf("    -h  --help                        Mostrar esta ayuda\n"
	 "    -d  --datos archivo-de-datos      Leer el archivo de datos\n"
	 "    -a  --ancho ancho-de-pantalla     Tamaño del ancho de la pantalla\n");
}

int main (int argc, char *argv[]) {
  int ind,dia,mes,anio,i,opciona;
  struct lista *l; /* esta es la lista */
  struct dato x;
  char nombre[30];
  
  /* Una cadena que lista las opciones cortas válidas */
  char* op_cortas = "hd:a:" ;

  /* Una estructura de varios arrays describiendo los valores largos */
  struct option op_largas[] = {
    { "help",0,NULL,'h'},
    { "datos",1,NULL,'d'},
    { "ancho",1,NULL,'a'},
    { NULL,0,NULL,0}
  };

  /* El nombre del fichero de datos y el del programa */
  char *nomfich,*nprograma;

  /* Guardar el nombre del programa para incluirlo a la salida */
  nprograma = strdup(argv[0]);

  /* valores por defecto */
  nomfich = strdup(nomardatos);
  anchura = ANCHOPANT; /* ancho de pantalla por defecto */
  
  ind = 1;
  while (ind) {
    opciona = getopt_long(argc, argv, op_cortas, op_largas, NULL);
    switch (opciona) {
    case 'h' : /* -h o --help */
      muestrauso(nprograma);
      exit(EXIT_SUCCESS);
      break;
    case 'd' : /* archivo de datos */
      nomfich = strdup(optarg);
      break;
    case 'a' : /* ancho de pantalla */
      anchura = atoi(optarg);
      if (anchura <= 0) { /* anchura inválida */
	printf("Ancho de pantalla inválido = %d\n",anchura);
	exit(EXIT_FAILURE);
      }
      break;
    case '?' : /* opción inválida */
      muestrauso(nprograma);
      exit(EXIT_FAILURE);
      break;
    case -1 : /* No hay más opciones */
      ind = 0;
      break;
    }
  }
  /* valores nomfich y anchopant asignados */
  /* Imprimir las entradas */
  printf("Archivo de datos = \"%s\"\n",nomfich);
  printf("Ancho de pantalla = %d\n\n",anchura);
  /* lee los datos y construye la lista */
  l = leedatos(nomfich,&i);
  while (1) {
    i = menuprograma();
    switch(i) {
    case 0:
      exit(0); /* salir */
      break;
    case 1: /* Insertar */
      x = tomadatos(); /* dato leido */
      l = insertacomienzo(l,x);
      break;
    case 2: /* Borrar */
      if (l != NULL) {
	l = pop(l,&x);
	printf("\nDato extraído:\n");
	printf("Nombre = %s\n",x.nombre);
	printf("Dni = %s\n",x.dni);
	printf("Fecha de nacimiento = %d/%d/%d\n",x.fechanac.dia,x.fechanac.mes,x.fechanac.anio);
      } else 
	printf("\nPila vacía.\n");
      break;
    case 3: /* Imprimir la lista */
      imprimelista(l);
      break;
    case 4: /* Mostrar la lista gráficamente */
      imprimenombres(l);
      break;
    case 5: /* anular la lista */
      l = anulalista(l);
      break;
    default: /* por si las moscas */
      printf("Opción incorrecta: opcion = %d\n",i);
      break;
    }
  }
} /* fin de main */
