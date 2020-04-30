#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int capturar_numero();
void cargar_matriz(int x, float matriz_letras[x][x]);
void imprimir_matriz(int x, float matriz_letras[x][x]);

/*
    Alumno: Jorge Cáceres Flores
    C.I.: 4787628
    Ejercicio 0
    Dada una matriz Cuadrada NxN donde N carga el usuario de tama�o mayor o igual a 5 menor o igual a 10, cargue los valores en la matriz de manera al azar
    del 0 al 30 para la diagonal principal, del 31 al 60 diagonal secundaria, del 61 al 100 los demas valores, si las diagonales se interceptan cargar 101

*/
int main()
{

    int input = capturar_numero();

    int i, j;
    int x = input;

    float matriz[x][x];
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < x; j++)
        {
            matriz[i][j] = 0;
        }
    }
    srand(time(NULL));
    cargar_matriz(x, matriz);
    imprimir_matriz(x, matriz);
    return 0;
}

void cargar_matriz(int x, float matriz[x][x])
{
    int i, j;
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < x; j++)
        {
            if ((i == j) && (i + j == x - 1))
            {
                matriz[i][j] = 101;
            }
            else if (i == j)
            {
                matriz[i][j] = rand() % 31;
            }
            else if (i + j == x - 1)
            {
                matriz[i][j] = 31 + rand() % 30;
            }
            else
            {
                matriz[i][j] = 61 + rand() % 40;
            }
        }
    }
}

void imprimir_matriz(int x, float matriz[x][x])
{
    int i, j;
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < x; j++)
        {
            if (j == 0)
                printf(" |");

            printf(" %2.0f| ", matriz[i][j]);
        }
        printf("\n");
    }
}

int capturar_numero()
{
    int input = 0;

    while (input < 5 || input > 10)
    {
        printf("Ingrese un numero entre 5 y 10 que sera la dimension de la matriz: ");
        scanf("%d", &input);
        getchar();
    }

    return input;
}
