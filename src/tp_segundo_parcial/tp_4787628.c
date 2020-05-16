#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/**
 *Existen diez alumnos:
Agustín
Beatriz
Carlos
Daniela
Eugenio        
Fabiola
Gustavo
Hilda
Ignacio
Juan
Quienes recibirán 20 cables de longitudes distintas que van desde 1cm a 35 cm de manera al azar, no recibirán cables de longitudes iguales. 
Representar cada cable con * por cada centímetro y al final de cada cable su longitud representada en unidades. Ej:
************ 12
Imprimir de manera automática todos los pasos de ordenamiento. Debe poder verse cada paso del ordenamiento en pantalla y diga en cuantos pasos 
se ha realizado una vez terminado el proceso de impresión de ordenamiento.

Se debe poder elegir que se haga el ordenamiento de manera automática de los 10 alumnos o poder ver los cables del alumno y luego decidir si queremos ordenarlos o no.

Agregue una opción mas al menú en donde permita mostrar quien de los alumnos tuvo el menor cantidad de pasos para ordenar, así como aquel que tuvo mas pasos. 1P

 * */

void generar_vector_cables(int alumnos, int cables, int vector_cables[alumnos][cables]);

void imprimir_cables_por_alumno(int alumnos, int cables, int vector_cables[alumnos][cables], char vector_alumnos[alumnos][alumnos]);

void obtener_longitud(int longitudes, int vector_longitudes[longitudes]);

void imprimir_cable(int longitud);

void ordenar_cables_por_alumno(int alumnos, int cables, int vector_cables[alumnos][cables], char vector_alumnos[alumnos][alumnos]);

void imprimir_ordenamiento(int alumnos, int cables, int vector_cables[alumnos][cables]);

int obtener_decision_usuario(int menu);

void obtener_estadistica_ordenamiento(int alumnos, int matriz_pasos[alumnos][1], char vector_alumnos[alumnos][10]);

int main()
{
    int cantidad_alumnos = 3;

    char alumnos[10][10] = {
        "Agustín",
        "Beatriz",
        "Carlos"};
    // char alumnos[10][10] = {
    //     "Agustín",
    //     "Beatriz",
    //     "Carlos",
    //     "Daniela",
    //     "Eugenio",
    //     "Fabiola",
    //     "Gustavo",
    //     "Hilda",
    //     "Ignacio",
    //     "Juan"};

    int cables = 20;

    int menu_inicial = 1;
    int menu_dos = 2;
    int mostrar_cables = obtener_decision_usuario(menu_inicial);

    int ordernar_cables = 0;

    int vector_cables[cantidad_alumnos][cables];

    srand(time(NULL));

    generar_vector_cables(cantidad_alumnos, cables, vector_cables);

    if (mostrar_cables)
    {
        imprimir_cables_por_alumno(cantidad_alumnos, cables, vector_cables, alumnos);
        ordernar_cables = obtener_decision_usuario(menu_dos);
        if (ordernar_cables)
        {
            ordenar_cables_por_alumno(cantidad_alumnos, cables, vector_cables, alumnos);
        }
    }
    else
    {
        ordenar_cables_por_alumno(cantidad_alumnos, cables, vector_cables, alumnos);
    }

    imprimir_cables_por_alumno(cantidad_alumnos, cables, vector_cables, alumnos);

    return 0;
}

void imprimir_cables_por_alumno(int alumnos, int cables, int vector_cables[alumnos][cables], char vector_alumnos[alumnos][alumnos])
{
    int i, j = 0;
    for (i = 0; i < alumnos; i++)
    {
        printf("Alumno [%s] \n", vector_alumnos[i]);
        for (j = 0; j < cables; j++)
        {
            imprimir_cable(vector_cables[i][j]);
        }
        printf("\n");
    }
}

void ordenar_cables_por_alumno(int alumnos, int cables, int vector_cables[alumnos][cables], char vector_alumnos[alumnos][alumnos])
{
    int i, j, k, l = 0;

    int aux;

    int menor_pasos, mayor_pasos, posicion_mayor, posicion_menor, aux_mayor, aux_menor;

    int matriz_pasos[10][1];

    //cantidad de pasos que toma el ordenamiento.
    int pasos;
    for (i = 0; i < alumnos; i++)
    {
        pasos = 0;
        printf("Alumno [%s] \n", vector_alumnos[i]);
        for (j = 0; j <= cables - 1; j++)
        {
            for (k = j + 1; k < cables; k++)
            {
                if (vector_cables[i][j] > vector_cables[i][k])
                {
                    aux = vector_cables[i][j];
                    vector_cables[i][j] = vector_cables[i][k];
                    vector_cables[i][k] = aux;
                    imprimir_ordenamiento(alumnos, cables, vector_cables);
                    pasos++;
                }
            }
        }
        matriz_pasos[i][0] = pasos;
        printf("Pasos de ordenamiento: [%d] \n", pasos);
    }
    obtener_estadistica_ordenamiento(alumnos, matriz_pasos, vector_alumnos);
}

void imprimir_cable(int longitud)
{
    char caracter = '*';
    int i;
    for (i = 0; i < longitud; i++)
    {
        printf("%c", caracter);
    }
    printf("%d \n", longitud);
}

void obtener_longitud(int longitudes, int vector_longitudes[longitudes])
{
    int i = 0;
    int numero = (rand() % 34) + 1;
    vector_longitudes[i] = numero;
    int b = 1;
    int agregar = 1;
    i++;
    while (i < 20)
    {

        numero = (rand() % 34) + 1;
        int j;
        for (j = 0; j < longitudes; j++)
        {
            if (vector_longitudes[j] == numero)
            {
                agregar = 0;
                break;
            }
            else if (j == (longitudes < 1))
            {
                agregar = 1;
            }
        }

        //en caso de que el numero generado no exista en el vector aun, agregamos.
        if (agregar)
        {
            vector_longitudes[i] = numero;
            i++;
        }
    }
}

void generar_vector_cables(int alumnos, int cables, int vector_cables[alumnos][cables])
{
    int vector_longitudes[cables];
    int i, j;
    for (i = 0; i < alumnos; i++)
    {
        //cargo el vector con longitudes aleatorias por cada alumno
        obtener_longitud(cables, vector_longitudes);
        for (j = 0; j < cables; j++)
        {
            vector_cables[i][j] = vector_longitudes[j];
        }
    }
}

void imprimir_ordenamiento(int alumnos, int cables, vector_cables[alumnos][cables])
{
    int i, j = 0;
    for (i = 0; i < alumnos; i++)
    {
        for (j = 0; j < cables; j++)
        {
            imprimir_cable(vector_cables[i][j]);
        }
        printf("\n");
    }
}

int obtener_decision_usuario(int menu)
{

    int decision;
    if (menu == 1)
    {
        while (decision < 0 || decision > 1)
        {
            printf("Para ver los cables repartidos, ingrese 1. Si quiere ordenarlos automaticamente, ingrese 0. ");
            scanf("%d", &decision);
            getchar();
        }
    }
    else if (menu == 2)
    {
        while (decision < 0 || decision > 1)
        {
            printf("Si desea ordenar los cables, ingrese 1, sino ingrese 0.");
            scanf("%d", &decision);
            getchar();
        }
    }
    return decision;
}

void obtener_estadistica_ordenamiento(int alumnos, int matriz_pasos[alumnos][1], char vector_alumnos[alumnos][10])
{

    int menor, mayor, posicion_mayor, posicion_menor;

    int i;
    for (i = 0; i < alumnos; i++)
    {
        if (i == 0)
        {
            menor = matriz_pasos[i][0];
            mayor = matriz_pasos[i][0];
            posicion_mayor = i;
            posicion_menor = i;
        }
        else
        {

            if (matriz_pasos[i][0] < menor)
            {
                menor = matriz_pasos[i][0];
                posicion_menor = i;
            }
            else if (matriz_pasos[i][0] > mayor)
            {
                mayor = matriz_pasos[i][0];
                posicion_mayor = i;
            }
        }
    }
    printf("%s tuvo la menor cantidad de pasos de ordenamiento [%d] \n", vector_alumnos[posicion_menor], menor);
    printf("%s tuvo la mayor cantidad de pasos de ordenamiento [%d] \n", vector_alumnos[posicion_mayor], mayor);
}
