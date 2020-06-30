/*
Ejercicio
Dada una cantidad de alumnos generados al azar(48 a 75) cargue las fichas de los siguiente manera:
Generados al azar desde una lista:

Reglas Basicas: nombres 1 y 2 no puede ser iguales, apellidos si pueeden ser iguales

Primer Nombre (lista)
Segundo Nombre (lista)
Primer Apellido (lista)
Segundo Apellido (lista)
Ciudad (lista)
Edad (entre 20  a 30)
CI (generados al azar unico)
Sexo (M o F)

Deben manejarse los datos del alumno como una sola variable.

Imprima luego en el siguiente formato la lista:
Sexo primer nombre segundo nombre primer apellido segundo apellido ciudad ci edad

Diga las siguientes estadisticas:
----------------------------------
Cuantos tienen la misma edad y cual es la edad
Cuantos alumnos hay de la misma ciudad
Cuantos alumnos del mismo sexo
Imprimir luego de las estadisticas la lista ordenada alfabeticamente por apellidos y luego ordenada alfabeticamente por nombres
 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct ficha
{
    char sexo;
    char pnombre[50];
    char snombre[50];
    char papellido[50];
    char sapellido[50];
    char nombreyapellido[102];
    char apellidoynombre[102];
    int edad;
    int ci;
    char ciudad[25];
    //struct ficha *sgte
} Ficha;

typedef struct edad
{
    int valoredad;
    int cantidad;
} Edad;

typedef struct CiudadEst
{
    char nombre[15];
    int cantidad;
} Ciudad;

int generarNroCedula(Ficha alumnos[], int a);
void imprimir_lista(Ficha alumnos[], int x);
void cargar_alumnos(Ficha alumnos[], int a);
void estadistica_edad(Ficha alumnos[], int a);
void estadistica_ciudad(Ficha alumnos[], int a);
void estadistica_sexo(Ficha alumnos[], int a);
void ordenar(Ficha alumnos[], int a, int tipo);

int main()
{
    srand(time(NULL));
    int n;
    n = 48 + rand() % 28;
    Ficha alumnos[n];
    cargar_alumnos(alumnos, n);
    imprimir_lista(alumnos, n);
    //// estadisticas
    //estadistica_edad(alumnos, n);

    int ordenamiento_apellido = 1;
    int ordenamiento_nombre = 2;

    ordenar(alumnos, n, ordenamiento_apellido);
    imprimir_lista(alumnos, n); // ordenados alfabeticamente apellidos

    ordenar(alumnos, n, ordenamiento_nombre);
    imprimir_lista(alumnos, n); // ordenados alfabeticamente nombres
    return 0;
}

void cargar_alumnos(Ficha alumnos[], int a)
{

    int i; //auxa,aux2;
    for (i = 0; i < a; i++)
    {
        Ficha F;

        char nombre_hombre[][50] = {"ADRIAN", "ALBERTO", "ALEJANDRO", "ALVARO", "ANDRES", "ANGEL", "ANTONIO", "CARLOS", "DANIEL", "DAVID", "DIEGO", "EDUARDO", "ENRIQUE", "FERNANDO", "FRANCISCO", "IVAN", "JAVIER", "JESUS", "JOAQUIN", "JORGE", "JOSE", "JUAN", "LUIS", "MANUEL", "MIGUEL", "OSCAR", "PABLO", "PEDRO", "RAFAEL", "RAMON", "RAUL", "RUBEN", "SANTIAGO", "SERGIO", "VICENTE", "VICTOR"};
        char nombre_mujer[][50] = {"ANA", "ANDREA", "ANGELA", "ANTONIA", "BEATRIZ", "CARMEN", "CONCEPCION", "CRISTINA", "DOLORES", "ELENA", "ENCARNACION", "FRANCISCA", "IRENE", "ISABEL", "JOSEFA", "JUANA", "JULIA", "LAURA", "LUCIA", "MANUELA", "MARIA", "MARTA", "MERCEDES", "MONICA", "MONTSERRAT", "NURIA", "PATRICIA", "PAULA", "PILAR", "RAQUEL", "ROCIO", "ROSA", "ROSARIO", "SARA", "SILVIA", "TERESA"};
        char pos_apellidos[][50] = {"ALONSO", "ALVAREZ", "BLANCO", "CANO", "CASTILLO", "CASTRO", "CORTES", "DELGADO", "DIAZ", "DOMINGUEZ", "FERNANDEZ", "GARCIA", "GARRIDO", "GIL", "GOMEZ", "GONZALEZ", "GUERRERO", "GUTIERREZ", "HERNANDEZ", "IGLESIAS", "JIMENEZ", "LOPEZ", "LOZANO", "MARIN", "MARTIN", "MARTINEZ", "MEDINA", "MOLINA", "MORALES", "MORENO", "MUNOZ", "NAVARRO", "NUNEZ", "ORTEGA", "ORTIZ", "PEREZ", "RAMIREZ", "RAMOS", "RODRIGUEZ", "ROMERO", "RUBIO", "RUIZ", "SANCHEZ", "SANTOS", "SANZ", "SERRANO", "SUAREZ", "TORRES", "VAZQUEZ"};
        char ciudad[][15] = {"Asuncion", "Barcelona", "Madrid", "Londres", "Lambare", "Capiata", "Luque", "California"};
        char nombres[50];
        char apellidos[50];
        // Asignar nombre y apellido definiendo al azar si es hombre o mujer
        if ((rand() % 2) == 0)
        {
            F.sexo = 'M';
            // aux=rand()%36;
            strcpy(F.pnombre, nombre_hombre[(rand() % 36)]); //aux --aux2=aux///aux2=rand()%36;
            strcpy(F.snombre, F.pnombre);
            while (strcmp(F.snombre, F.pnombre) == 0)
            { //aux2=rand()%36-- while(aux==aux2)
                strcpy(F.snombre, nombre_hombre[(rand() % 36)]);
            }
        }
        else
        {
            F.sexo = 'F';
            strcpy(F.pnombre, nombre_mujer[(rand() % 36)]);
            strcpy(F.snombre, F.pnombre);
            while (strcmp(F.snombre, F.pnombre) == 0)
            {
                strcpy(F.snombre, nombre_mujer[(rand() % 36)]);
            }
        }
        strcpy(F.papellido, pos_apellidos[(rand() % 49)]);
        strcpy(F.sapellido, pos_apellidos[(rand() % 49)]);
        strcat(nombres, F.pnombre);
        strcat(nombres, F.snombre);
        strcat(apellidos, F.papellido);
        strcat(apellidos, F.sapellido);
        strcat(F.nombreyapellido, nombres);
        strcat(F.nombreyapellido, " ");
        strcat(F.nombreyapellido, apellidos);
        strcat(F.apellidoynombre, apellidos);
        strcat(F.apellidoynombre, ", ");
        strcat(F.apellidoynombre, nombres);
        strcpy(F.ciudad, ciudad[(1 + rand() % 8)]);
        // Asignar CI, edad y nro de inscripcion
        F.edad = ((rand() % 6) + 20);
        F.ci = generarNroCedula(alumnos, a);
        alumnos[i] = F;
        //printf("\n%s %s %s %s %s %s %d %d %d\n",F.genero,F.pnombre,F.snombre,F.papellido,F.sapellido,F.ciudad,F.ci,F.edad);
    }
}

int generarNroCedula(Ficha alumnos[], int a)
{
    int ci = 0, i = 0; //b=1 si se usa while;
    ci = 2500000 + rand() % 3500001;
    for (i = 0; i < a; i++)
    {
        if (alumnos[i].ci == ci)
        {
            ci = 2500001 + rand() % 3500000;
            i = 0;
        }
    }
    return ci;
}

void imprimir_lista(Ficha alumnos[], int x)
{
    int i = 0;
    for (i = 0; i < x; i++)
    {
        printf("\n%c %s %s %s %s %s %d %d", alumnos[i].sexo, alumnos[i].pnombre, alumnos[i].snombre, alumnos[i].papellido, alumnos[i].sapellido, alumnos[i].ciudad, alumnos[i].ci, alumnos[i].edad);
    }
}

void estadistica_edad(Ficha alumnos[], int a)
{

    Edad edades[10];

    int i;
    int j;
    int k;

    for (i = 20; i < 30; i++)
    {
        Edad edad;
        edad.cantidad = 0;
        edad.valoredad = i;
    }

    for (j = 0; j < a; j++)
    {
        for (k = 0; k < 10; k++)
        {
            if (edades[k].valoredad == alumnos[j].edad)
            {
                edades[k].cantidad = edades[k].cantidad + 1;
            }
        }
    }

    int l;
    for (l = 0; l < 10; l++)
    {
        printf("Alumnos con %d anhos -> %d \n", edades[l].valoredad, edades[l].cantidad);
    }
}

void estadistica_ciudad(Ficha alumnos[], int a)
{

    Ciudad ciudades[8];
    int i, k, l;

    char ciudades_v[][15] = {"Asuncion", "Barcelona", "Madrid", "Londres", "Lambare", "Capiata", "Luque", "California"};

    for (i = 0; i < 8; i++)
    {
        Ciudad ciudad;
        ciudad.cantidad = 0;
        ciudad.nombre = ciudades_v[i];
    }

    for (k = 0; k < a; k++)
    {
        for (i = 0; i < 8; i++)
        {
            if (strcmp(ciudades[i].nombre, alumnos[k].ciudad) == 0)
            {
                ciudades[i].cantidad = ciudades[i].cantidad + 1;
                break;
            }
        }
    }

    for (l = 0; l < 8; l++)
    {
        printf("%d alumnos viven en %s", ciudades[l].cantidad, ciudades[l].nombre);
    }
}

void estadistica_sexo(Ficha alumnos[], int a)
{
    int m, f = 0;

    int i;
    for (i = 0; i < a; i++)
    {
        if (alumnos[i].sexo == 'M')
            m++;
        else
            f++;
    }
    printf("Existen %d alumnos del sexo masculino\n", m);
    printf("Existen %d alumnas del sexo femenino\n", f);
}

void ordenar(Ficha alumnos[], int a, int tipo)
{

    Ficha aux;

    if (tipo == 1)
        printf("Vamos a ordernar por apellidos!");
    else
        printf("Vamos a ordernar por nombres!");

    int i, j;
    for (i = 0; i <= a - 1; i++)
    {
        for (j = i + 1; j < a; j++)
        {
            if (tipo == 1)
            {

                if (strcmp(alumnos[i].apellidoynombre, alumnos[j].apellidoynombre) > 0)
                {
                    aux = alumnos[i];
                    alumnos[i] = alumnos[j];
                    alumnos[j] = aux;
                }
            }
            else
            {
                if (strcmp(alumnos[i].nombreyapellido, alumnos[j].nombreyapellido) > 0)
                {
                    aux = alumnos[i];
                    alumnos[i] = alumnos[j];
                    alumnos[j] = aux;
                }
            }
        }
    }
}