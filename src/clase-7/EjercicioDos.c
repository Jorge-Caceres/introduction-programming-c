#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generar_numeros(int v[]);
void cargar_matriz_letras(int x, int v, char matriz_letras[x][v]);
void imprimir_matriz(int x, int v, char matriz_letras[x][v]);
void volcar_matriz(int x, int y, char vector_letras[], char matriz_letras[x][y]);
void imprimir_vector(int l, char vector_letras[l]);

/*
    Alumno: Jorge Cáceres Flores
    C.I.: 4787628
    EJERCICIO DOS
   Utilizando la matriz de letras del ejercicio 1 vuelque los valores dentro de un vector, siguiendo el recorrido de la matriz de arriba para abajo
    y abajo para arriba, recorriendo constante de izquierda a derecha.

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

    imprimir_matriz(v[0], v[1], matriz_letras);

    int x, y;
    x = v[0];
    y = v[1];

    int l = x * y;

    char vector_letras[l];
    int k;
    for (k = 0; k < l; k++)
    {
        vector_letras[k] = 0;
    }

    volcar_matriz(x, y, vector_letras, matriz_letras);

    imprimir_vector(l, vector_letras);

    return 0;
}

void imprimir_matriz(int x, int v, char matriz_letras[x][v])
{
    int i, j;
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < v; j++)
        {
            if (j == 0)
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

void volcar_matriz(int x, int y, char vector_letras[], char matriz_letras[x][y])
{
    int i, j, c = 0;
    for (j = 0; j < y; j++)
    {
        //si la columna es par, entonces recorremos para abajo
        if (j % 2 == 0)
        {
            for (i = 0; i < x; i++)
            {
                vector_letras[c] = matriz_letras[i][j];
                c++;
            }
        }
        else
        {
            for (i = x - 1; i >= 0; i--)
            {
                vector_letras[c] = matriz_letras[i][j];
                c++;
            }
        }
    }
}

void imprimir_vector(int l, char vector_letras[l])
{
    printf("\n VECTOR \n");
    int i;
    for (i = 0; i < l; i++)
    {
        if (i == (l - 1))
            printf("| %c |\n", vector_letras[i]);
        else
            printf("| %c ", vector_letras[i]);
    }
}