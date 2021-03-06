#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/**
 * Alumno: Jorge Cáceres Flores.
 * C.I: 4787628
 * 4. Dado el vector de strings de 10 palabras, cuyo valor deben ser letras generadas al azar, 
 * compuestas por 6 letras generadas al azar, imprima el vector, ordénelo y vuelva a imprimir el vector. 
 * Sabiendo que el valor de la A en la tabla ASCII es 65 y la Z es 90
 * 
 * */

void generar_vector_strings(int palabras, int longitud, char strings[palabras][longitud]);
//void generar_vector_strings(int palabras, char strings[palabras]);
void imprimir_matriz(int palabras, int longitud, char strings[palabras][longitud]);
char obtener_caracter();

// void inicializar_matriz(int dimension, float matriz[dimension][dimension]);

int main()
{

    int palabras = 10;
    int dimension = 7;

    char vector_palabras[palabras][dimension];

    // int i, j;
    // for (i = 0; i < palabras; i++)
    // {
    //     for (j = 0; j < dimension; j++)
    //     {
    //         vector_palabras[i][j] = '';
    //     }
    // }

    srand(time(NULL));

    generar_vector_strings(palabras, dimension, vector_palabras);

    imprimir_matriz(palabras, dimension, vector_palabras);
}

char obtener_caracter()
{

    int numero = 65 + rand() % 90;
    int b = 1;
    while (b)
    {
        numero = 65 + rand() % 90;
        if (numero > 64 && numero < 91)
            b = 0;
    }
    return (char)numero;
}

void imprimir_matriz(int palabras, int longitud, char strings[palabras][longitud])
{
    int k;
    for (k = 0; k < palabras; k++)
    {
        printf("|%s", strings[k]);
    }
}

void generar_vector_strings(int palabras, int longitud, char strings[palabras][longitud])
{

    int i, j;
    for (i = 0; i < palabras; i++)
    {
        for (j = 0; j < longitud; j++)
        {
            strcat(strings[i], obtener_caracter());
        }

        printf("[%s]\n", strings[i]);
    }
}
