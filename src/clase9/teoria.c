#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    Alumno: Jorge Cáceres Flores
    C.I.: 4787628
*/

void funcion(int *ptr, int a);

int main()
{

    int numero = 5;

    printf("Numero: %d Direccion: %d\n", numero, &numero);

    int *ptr;

    ptr = &numero;

    printf("Contenido puntero:%d Valor a que apunta: %d\n", ptr, *ptr);

    numero = 6;
    printf("Contenido puntero:%d Valor a que apunta: %d\n", ptr, *ptr);
    *ptr = 8;
    int numero_1 = 15;
    ptr = &numero_1;
    //*ptr = 8;

    printf("Contenido puntero:%d Valor a que apunta: %d\n", numero, &numero);

    printf("Contenido puntero:%d Valor a que apunta: %d\n", ptr, *ptr);

    int vector[] = {1, 2, 3, 4};

    int i;
    for (i = 0; i < 4; i++)
    {
        //direccion
        printf("%d\n", vector + i);

        //contenido
        printf("%d\n", *(vector + i));
    }

    int variable = 45;
    funcion(&variable, variable);
    printf("Direccion: %d Valor: %d \n", &variable, variable);

    return 0;
}

void funcion(int *ptr, int a)
{
    printf("Puntero: %d      Variable:%d\n", *ptr, a);

    *ptr = 50;

}