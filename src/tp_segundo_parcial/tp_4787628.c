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

 * */

void generar_vector_cables(int alumnos, int cables, int vector_cables[alumnos][cables]);
void imprimir_cables_por_alumno(int alumnos, int cables, int vector_cables[alumnos][cables], char vector_alumnos[alumnos][alumnos]);
// void imprimir_matriz(int palabras, int longitud, char strings[palabras][longitud]);
void obtener_longitud(int longitudes, int vector_longitudes[longitudes]);
void imprimir_cable(int longitud);
void ordenar_cables_por_alumno(int alumnos, int cables, int vector_cables[alumnos][cables], char vector_alumnos[alumnos][alumnos]);
void imprimir_ordenamiento(int alumnos,int cables,int vector_cables[alumnos][cables]);

int main()
{

    char alumnos[1][10] = {
        "Agustín"};
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
    int cantidad_alumnos = 1;

    // int mostrar_cables = 0;
    // int ordernar_cables = 0;
    // printf("Si desea ver los cables repartidos a los alumnos, antes de ordenarlos, ingrese 1: ");
    // scanf("%d", &mostrar_cables);
    // getchar();

    int vector_cables[cantidad_alumnos][cables];

    srand(time(NULL));

    generar_vector_cables(cantidad_alumnos, cables, vector_cables);

    imprimir_cables_por_alumno(cantidad_alumnos, cables, vector_cables, alumnos);
    ordenar_cables_por_alumno(cantidad_alumnos, cables, vector_cables, alumnos);

    //imprimir_cables_por_alumno(cantidad_alumnos, cables, vector_cables, alumnos);
    // if (mostrar_cables)
    // {
    //     imprimir_cables_por_alumno(cantidad_alumnos, cables, vector_cables, alumnos);
    //     printf("Para ordenar los cables, ingrese 1, sino 0. Serán imprimidos.");
    //     scanf("%d", &ordernar_cables);
    //     getchar();
    //     if (ordernar_cables)
    //     {
    //         ordenar_cables_por_alumno(cantidad_alumnos, cables, vector_cables, alumnos);
    //     }
    // }

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
    for (i = 0; i < alumnos; i++)
    {
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
                }
            }
        }
        printf("\n");
    }
}

/*
void ordenar_palabras(int palabras, int longitud, char strings[palabras][longitud]){
	int i,j;
	char aux[7];
	for(i=0; i <= palabras -1; i++){
		for(j=i+1; j < palabras ; j++){
			if(strcmp(strings[i], strings[j])>0){
				strcpy(aux, strings[i]);
				strcpy(strings[i], strings[j]);
				strcpy(strings[j], aux);
			}
		}
	}
}
*/

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
    obtener_longitud(cables, vector_longitudes);
    int i, j;
    for (i = 0; i < alumnos; i++)
    {
        for (j = 0; j < cables; j++)
        {
            vector_cables[i][j] = vector_longitudes[j];
        }
    }
}

void imprimir_ordenamiento(int alumnos,int cables, vector_cables[alumnos][cables])
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
