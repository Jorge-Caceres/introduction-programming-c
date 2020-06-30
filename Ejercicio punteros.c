#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 
 * ALUMNO: JORGE CACERES FLORES
 * C.I.: 4787628
 * 
 * */


typedef struct NODO
{
       char *nombre;
       struct NODO *siguiente;
       int pos;
       
} Nodo;


void agregar (Nodo **nodo)
{
	char nombre[50];
	printf("Cargue nombre: ");
	scanf("%s",nombre);
	getchar();

	Nodo *_nodo = (Nodo *) malloc(sizeof(Nodo));
	_nodo->nombre = (char *) malloc(sizeof((nombre)));
	strcpy(_nodo->nombre,nombre);
	_nodo->siguiente = *nodo;
	*nodo = _nodo;	
}


int main()
{

	Nodo *nodo = NULL;
    agregar(&nodo);
	agregar(&nodo);
	agregar(&nodo);
	agregar(&nodo);
	agregar(&nodo);
	
	while (nodo!=NULL)
	{
		printf("Nombre -> [%s]\n",nodo->nombre);
		nodo=nodo->siguiente;
   }
	return 0;
}

