#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Alumno: Jorge Cáceres Flores.
 * C.I.: 4787628
 * 1. Dada la matriz cuadrada NxN( donde N  es impar, mayor o igual a 13 menor o igual que 19 generado al azar). 
 * Realice la carga de como sigue el ejemplo, donde N=15
 * 
 * */

int generar_dimension();
void cargar_matriz(int dimension, float matriz[dimension][dimension]);
void imprimir_matriz(int dimension, float matriz[dimension][dimension]);
void inicializar_matriz(int dimension, float matriz[dimension][dimension]);

int main()
{
    srand(time(NULL));
    int dimension = generar_dimension();

    int i, j;

    printf("Dimension [%d][%d]", dimension, dimension);
    float matriz[dimension][dimension];

    cargar_matriz(dimension, matriz);

    imprimir_matriz(dimension, matriz);
}

int generar_dimension()
{

    int dimension = 6 + rand() % 13;
    int b = 1;
    while (b)
    {
        dimension = 6 + rand() % 13;
        if (dimension >= 13 && dimension <= 19)
            b = 0;
    }

    return dimension;
}

void cargar_matriz(int dimension, float matriz[dimension][dimension])
{
    int i, j;
    int aux = 0;
    for (i = 0; i < dimension; i++)
    {
        aux = i + 1;
        for (j = 0; j < dimension; j++)
        {
            if (aux > dimension)
                aux = 1;

            matriz[i][j] = aux++;
        }
    }
}

void inicializar_matriz(int dimension, float matriz[dimension][dimension])
{
    int i,j;
    for (i = 0; i < dimension; i++)
    {
        for (j = 0; j < dimension; j++)
        {
            matriz[i][j] = 0;
        }
    }
}
void imprimir_matriz(int dimension, float matriz[dimension][dimension])
{
    int k, l;
    for (k = 0; k < dimension; k++)
    {
        printf("\n");
        for (l = 0; l < dimension; l++)
        {
            printf(" %2.0f| ", matriz[k][l]);
        }
    }
}