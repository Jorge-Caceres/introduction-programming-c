#include <stdio.h>   
#include <stdlib.h>  
#include <time.h>

typedef struct NODO {
	int numero;
	struct NODO *siguiente;
} Nodo;

/*Agrega un nodo a lista enlazada*/
void agregar_nodo(Nodo **puntero) {

    Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));// se crea un nodo y este espacio en la memoria se enlaza
        
    nodo->siguiente = *puntero;                                                                            
    *puntero = nodo;
    nodo->numero = 1+rand()%4000;
    
}

/*remueve un elemento de la lista enlazada*/
void remover(Nodo **puntero) { 
    if (*puntero != NULL) {
        Nodo *nodo = *puntero;
	*puntero = (*puntero)->siguiente;
	free(nodo);
    }
}
/*Tipo de dato de la funcion ** porque se devolvera una posicion de memoria, donde se espera un puntero en este caso la funcion remover.*/
Nodo **buscar(Nodo **nodo, int i) {
    /*Busca la posicion del nodo que contiene el valor sugerido, dicha posicion se utilizar para eliminar en la otra funcion*/
    while (*nodo != NULL) {
        if ((*nodo)->numero == i) {
            return nodo;
        }
        nodo = &(*nodo)->siguiente;
    }
    return NULL;
}

void imprimir(Nodo *nodo) {
    if (nodo == NULL) {
        printf("lista esta vacia\n");
    }
    /*Recorre la lista para ir imprimiendo los numeros generados al azar*/
    while (nodo != NULL) {
        printf("Pos. Mem: %p Pos. sig: %p Valor cont:%d\n", nodo, nodo->siguiente, nodo->numero);
        nodo = nodo->siguiente;
    }
}

int main() {
    Nodo *nodo = NULL;
     srand(time(NULL));
    int i,num,pos;
  /*se cargan los elementos al azar de la lista en este caso 5 elementos*/
   // imprimir(nodo);
      for(i=0;i<5;i++)
      {
       agregar_nodo(&nodo);
       printf("\n\n");
       imprimir(nodo);
      }
      printf("\n\nLista cargada\n");    
      imprimir(nodo);
    /*Elimina el elemento que se desea de la lista*/
      printf("\nQue valor desea remover: ") ;
      scanf("%d",&num);
      getchar();
   /*elimina el primer numero de la lista */
      remover(buscar(&nodo, num));
      printf("\n\n");
      imprimir(nodo);

   /*elimina el primer numero de la lista */
      remover(&nodo);
      printf("\n\n");
      imprimir(nodo);
   /*elimina el primer numero de la lista */
      remover(&nodo);
      printf("\n\n");
      imprimir(nodo);
      getchar();
   return 0;
}
