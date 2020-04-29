#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generar_numeros(int v[]);
void cargar_matriz_letras(int x, int v, char matriz_letras[x][v]);
void impresion(int x, int v, char matriz_letras[x][v]);

/*
    Alumno: Jorge Cáceres Flores
    C.I.: 4787628
    EJERCICIO UNO
    Dada una matriz de letras MxN donde M y N mayores o iguales a 5 y menores o iguales a 10, M y N distintos y generados al azar, cargue la matriz
    con letras generadas al azar.

*/
int main()
{

    int v[] = {0, 0};

    srand(time(NULL));
    generar_numeros(v);

    char matriz_letras[v[0]][v[1]];

    int i, j;

    for (i = 0; i < v[0]; i++)
    {
        for (j = 0; j < v[1]; j++)
        {
            matriz_letras[i][j] = 0;
        }
    }

    cargar_matriz_letras(v[0], v[1], matriz_letras);

    impresion(v[0], v[1], matriz_letras);

    return 0;
}

void impresion(int x, int v, char matriz_letras[x][v])
{
    int i, j;
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < v; j++)
        {
            if(j == 0)
                printf("|");
                
            printf(" %c |", matriz_letras[i][j]);
        }
        printf("\n");
    }
}

void generar_numeros(int v[])
{
    v[0] = 5 + rand() % 6;
    int b = 1;
    while (b)
    {
        v[1] = 5 + rand() % 6;
        if (v[0] != v[1])
            b = 0;
    }
}

void cargar_matriz_letras(int x, int v, char matriz_letras[x][v])
{
    int i, j;

    for (i = 0; i < x; i++)
    {
        for (j = 0; j < v; j++)
        {
            matriz_letras[i][j] = 65 + rand() % 26;
        }
    }
}