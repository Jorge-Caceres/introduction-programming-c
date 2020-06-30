#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Materia
{
    char nombre[30];
    int cantidad_parciales;
    int notas_parciales[4];
};

struct Alumno
{
    char nombre[20];
    char apellido[20];
    int edad, ci, estatura, peso_kg;
    struct Materia asignaturas[5];
};

/**
 
 EJERCICIO 0 - Dada una promocion con alumnos (cantidad entre 20 a 30) cada uno de ellos tiene 4 asignaturas con 4 parciales.
 Genere de manera al azar las notas de cada asignatura y halle sus promedios.
 El nombre del alumno sera "Alumno# Apellido# donde # sera su posicion en la lista.
 
 * */

void generar_alumnos(int cantidad, struct Alumno alumnos[cantidad]);
float cargar_notas(int x, int y, float matriz_notas[x][y]);

float generar_notas();

int main()
{
    srand(time(NULL));

    int cantidad;

    cantidad = rand() % 31 + 40;

    struct Alumno alumnos[cantidad];

    int k;
    for(k=0; k < cantidad; k++){

        struct Alumno a;
        strcpy(a.apellido, "");
        strcpy(a.nombre, "");
        a.ci = 0;
        a.edad = 0;
        a.estatura = 0;
        a.peso_kg = 0;
        alumnos[k] = a;
    }
    printf("Alumnos cargados");

    int materias = 4;

    generar_alumnos(cantidad, alumnos);

    int j;
    int i;
    for (j = 0; j < cantidad; j++)
    {
        printf("%s", alumnos[j].nombre);
        for (i = 0; i < materias; i++)
        {
            printf("%d", alumnos[j].asignaturas[i].cantidad_parciales);
        }
    }

    return 0;
}

void generar_alumnos(int cantidad, struct Alumno alumnos[cantidad])
{
    int i;
    int j;
    int asignatura = 4;
    int parciales = 4;
    int k;
    for (i = 0; i < cantidad; i++)
    {
        struct Alumno alumno;
        char nombre[20];
        strcat(nombre, "Alumno");
        strcat(nombre, i);

        char apellido[20];
        strcat(apellido, "Apellido");
        strcat(apellido, i);

        strcpy(alumno.apellido, apellido);
        strcpy(alumno.nombre, nombre);

        alumno.edad = 20 + rand() % 30;
        alumno.ci = 2000000 + rand() % 5100000;

        for (j = 0; j < asignatura; j++)
        {
            struct Materia materia_1;
            strcpy(materia_1.nombre, "Materia");
            materia_1.cantidad_parciales = parciales;
            for (k = 0; k < parciales; k++)
            {
                materia_1.notas_parciales[k] = rand() % 41 + 60;
            }
            alumno.asignaturas[j] = materia_1;
        }

        alumnos[i] = alumno;
    }
}
