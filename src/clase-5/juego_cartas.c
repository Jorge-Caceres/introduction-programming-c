
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void repartir(int x, int y, int mazo[x][y], int f, int c, int jugador1[f][c], int jugador2[f][c]);
void cargar_mazo(int x, int y, int mazo[x][y]);
void jugar(int f, int c, int jugador1[f][c], int jugador2[f][c]);

/*
    Alumno: Jorge Ariel Cáceres Flores.
    C.I.: 4787628

    Clase 5 - Juego de cartas

*/
int main()
{

    printf("----JUEGO DE CARTAS-----\n");

    int x = 52;
    int y = 4;
    int mazo[52][4];

    cargar_mazo(x, y, mazo);
    int f = 26;
    int c = 4;
    int jugador1[f][c];
    int jugador2[f][c];

    srand(time(NULL));
    repartir(x, y, mazo, f, c, jugador1, jugador2);

    jugar(f, c, jugador1, jugador2);

    return 0;
}

void cargar_mazo(int x, int y, int mazo[x][y])
{
    int i, j, c = 0;
    for (i = 0; i < 4; i++)
    {
        for (j = 1; j < 14; j++)
        {
            //valor
            mazo[c][0] = j; //1-13
            //palo
            mazo[c][1] = i; //0-3
            //color
            mazo[c][2] = i % 2;
            //estado
            mazo[c][3] = 0;
            c++;
        }
    }
}

void repartir(int x, int y, int mazo[x][y], int f, int c, int jugador1[f][c], int jugador2[f][c])
{
    int fila = 0, aux, j;
    for (fila = 0; fila < f; fila++)
    {
        aux = rand() % 52; ///0 a 51
        while (mazo[aux][3])
            aux = rand() % 52; ///0 a 51

        for (j = 0; j < 4; j++)
        {
            //printf("Asignando [%d] al jugador 1\n", mazo[aux][j]);
            jugador1[fila][j] = mazo[aux][j]; ///ejemplo 10 de corazones 10,1,1,0
        }

        mazo[aux][3] = 1; ///la carta ya esta utilizada

        aux = rand() % 52; ///0 a 51
        while (mazo[aux][3])
            aux = rand() % 52; ///0 a 51

        for (j = 0; j < 4; j++)
        {
            //printf("Asignando [%d] al jugador 2 \n", mazo[aux][j]);
            jugador2[fila][j] = mazo[aux][j];
        }
        mazo[aux][3] = 1; ///la carta ya esta utilizada
    }
}

void jugar(int f, int c, int jugador1[f][c], int jugador2[f][c])
{

    int puntuacion1 = 0;
    int puntuacion2 = 0;

    int turno;
    for (turno = 0; turno < 26; turno++)
    {
        //posicion 0 -> valor de la carta
        if (jugador1[turno][0] > jugador2[turno][0])
        {
            puntuacion1++;
        }
        else if (jugador2[turno][0] > jugador1[turno][0])
        {
            puntuacion2++;
        }
        //si el turno es par, punto para el ROJO en caso de que sean diferentes
        else if (turno % 2 == 0)
        {
            if (jugador1[turno][2] != jugador2[turno][2])
            {
                if (jugador1[turno][2] == 1)
                    puntuacion1++;
                else if (jugador2[turno][2] == 1)
                    puntuacion2++;
            }
        }
        //turno impar, punto para el NEGRO en caso de que sean diferentes
        else
        {
            if (jugador1[turno][2] != jugador2[turno][2])
            {
                if (jugador1[turno][2] == 0)
                    puntuacion1++;
                else if (jugador2[turno][2] == 0)
                    puntuacion2++;
            }
        }
    }

    if (puntuacion1 > puntuacion2)
        printf("GANADOR -> JUGADOR 1\n");
    else if (puntuacion2 > puntuacion1)
        printf("GANADOR -> JUGADOR 2\n");
    else
        printf("¡EMPATE!\n");
}