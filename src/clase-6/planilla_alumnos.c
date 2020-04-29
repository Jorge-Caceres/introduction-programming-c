#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float cargar_notas(int x, int y, float matriz_notas[x][y]);
void impresion(int x, int y, float matriz_notas[x][y]);
void imprimir_alumno(int y, float alumno[]);

/*
    Alumno: Jorge Cáceres Flores
    C.I.: 4787628
*/
int main()
{
    srand(time(NULL));
    int x, i, j;

    x = rand() % 31 + 40;
    float matriz_notas[x][5], promedio_general;

    for (i = 0; i < x; i++)
    {
        for (j = 0; j < 5; j++)
        {
            matriz_notas[i][j] = 0;
        }
    }

    printf("Cantidad de alumnos: %d\n", x);
    promedio_general = cargar_notas(x, 5, matriz_notas);
    impresion(x, 5, matriz_notas);

    return 0;
}

float cargar_notas(int x, int y, float matriz_notas[x][y])
{
    ////// x sera el numero de alumnos y sera el numero de parciales y el premedio
    int aux, i, j;
    float promedio_general = 0;

    for (i = 0; i < x; i++)
    { /*  hara de 0 a 3 */
        for (j = 0; j < y - 1; j++)
        {
            aux = rand() % 2;
            if (aux)
            {
                matriz_notas[i][j] = rand() % 41 + 60; // se asigan una nota 68
            }
            else
            {
                matriz_notas[i][j] = rand() % 60;
            }
            matriz_notas[i][y - 1] += matriz_notas[i][j] / (y - 1);
        }
        promedio_general += matriz_notas[i][y - 1] / x;
    }

    return promedio_general;
}

void impresion(int x, int y, float matriz_notas[x][y])
{
    int input, i;
    do
    {
        printf("Alumno que desea ver la nota (0 si quiere imprimir todos, -1 si quiere cerrar el programa):");
        scanf("%d", &input);
        getchar();
        if (input < 0)
        {
            printf("Finalizando la ejecucion.\n");
        }
        else if (input)
        {
            printf("Alumno %d:\n", input);
            imprimir_alumno(y, matriz_notas[input - 1]);
        }
        else if (input == 0)
        {
            for (i = 0; i < x; i++)
            {
                printf("Alumno %d:\n", i + 1);
                imprimir_alumno(y, matriz_notas[i]);
            }
        }
    } while (input >= 0);
}
void imprimir_alumno(int y, float alumno[])
{
    int i;
    for (i = 0; i < y - 1; i++)
    {
        printf("Parcial %d: %2.0f\n", i + 1, alumno[i]);
    }
    printf("Promedio: %2.2f\n", alumno[y - 1]);
}
