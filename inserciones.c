
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct NODO
{
    int numero;
    struct NODO *siguiente;
} Nodo;

void push(Nodo **cabecera_ref, Nodo **nuevo_nodo)
{

    (*nuevo_nodo)->siguiente = (*cabecera_ref);

    (*cabecera_ref) = nuevo_nodo;
}

void inserta_despues(Nodo *nodo_previo, Nodo *nuevo_nodo)
{

    if (nodo_previo == NULL)
    {
        printf("El anterior no puede estar vacio");
        return;
    }

    nuevo_nodo->siguiente = nodo_previo->siguiente;

    nodo_previo->siguiente = nuevo_nodo;
}

void append(Nodo** cabecera_ref, int nuevo_nro) 
{ 
  
    Nodo* nuevo_nodo = (Nodo*) malloc(sizeof(Nodo)); 
  
    Nodo *ultimo = *cabecera_ref; 
  
    
    nuevo_nodo->numero  = nuevo_nro; 
  
   
    nuevo_nodo->siguiente = NULL; 
  
    if (*cabecera_ref == NULL) 
    { 
       *cabecera_ref = nuevo_nodo; 
       return; 
    } 
      
    while (ultimo->siguiente != NULL) 
        ultimo = ultimo->siguiente; 
  
   
    ultimo->siguiente = nuevo_nodo; 
    return; 
} 

void imprimir(Nodo *nodo)
{
    while (nodo != NULL)
    {
        printf(" %d ", nodo->numero);
        nodo = nodo->siguiente;
    }
    printf("\n");
}

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

int main()
{

    srand(time(NULL));

    Nodo *cabecera = NULL;

    int i;
    for (i = 0; i < 5; i++)
    {
        int n = rand() % 40 + 20;
        append(&cabecera, n);
    }

    //   // Inserta 6.  lista: 6->NULL
    //   append(&cabecera, 6);

    //   // Inserta 7 al comienzo. Lista: 7->6->NULL
    //   push(&cabecera, 7);

    //   // Inserta 1 al comienzo. lista:1->7->6->NULL
    //   push(&cabecera, 1);

    //   // Inserta 4 al final. lista: 1->7->6->4->NULL
    //   append(&cabecera, 4);

    //   // Inserta 8, despues de 7. lista: 1->7->8->6->4->NULL
    //   inserta_despues(cabecera->siguiente, 8);

    //   printf("\n lista enlazada: ");
    imprimir(cabecera);

    int j;
    int k;
    for (j = 0; j < 5; j++)
    {
        for (k = 0; k < 5 - j; k++)
        {
            if ((*cabecera).numero > (*cabecera->siguiente).numero)
            {
                printf("[%d] es mayor que [%d]\n",(*cabecera).numero, (*cabecera->siguiente).numero);
                //append(&cabecera, &cabecera->siguiente);
                inserta_despues(&cabecera, &cabecera->siguiente);
                //push(&cabecera->siguiente, &cabecera);
            }
        }
    }


    imprimir(cabecera);

    return 0;
}
