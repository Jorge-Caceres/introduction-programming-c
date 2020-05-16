/*
    Clase 8 de PROGRAMACION EN C

    BIBLIOTECA string.h

    un string es un arreglo de caracteres en C

    char string[] s = "hola";

    string[] = {"h","o","l","a", "\0"}




#include <string.h>

//longitud de un string

//strlen recibe un string y retorna la longitud sin incluir el terminador.

    -- REGLAS
    1 - se puede hacer la siguiente asignacion solo al declarar
    char string[] = "Jorge";

    NO SE PUEDE char string[6];
    string = "Jorge";

    2 - Si existen varios terminadores de string, solo se toma el primero en aparecer
    3 - No se puede cargar un string mayor a la longitud predefinida del vector.

    se debe copiar el string ya que no se puede modificar con un valor mayor a su longitud

    stcrpy(string_destino, string_origen)
                            <----

    se van a tomar los caracteres del string de origen y se copian por cada posicion en la posicion destino.

    Es decir, el destino debe poder contener al string origen


    --CONCATENACION DE UN STRING
    strcat(string_destino, string_origen)
    recorre el string hasta encontrar el terminador y reemplaza a partir de este todos los caracteres que se pasan como string origen hasta encontrar el primer terminador de este ultimo

    char string[50];
    stcrpy(string, "Juanjo");
    string[] ->  {'J', 'u','a','n','j','o','\0'}

    char string_2[]= "Acosta";
    strcat(string, string_2);
    printf("%s", string);
    resultado:JuanjoAcosta


    --PREGUNTAS LOGICAS
    
    COMPARACION DE STRINGS
    strcmp(string1, string2)
    compare the content inside strings and for each one of the characters asigned in ASCII
    compara el contenido de los strings por cada caracter asignado en la tabla ascii
    ADVICE: always work in zero based

    char s1[30];
    char s2[2];

    strcpy(s1, "h");
    strcpy(s2, "H")

    s1 y s2 son iguales

    strcmp(s1, s2);
    si son iguales la funcion devuelve 0
    si s1 es menos que s2 devuelve <0
    si s1 es mayor a s2 devuelve >0

    para este caso devuelve mayor a 0 porque la h tiene mayor precedencia sobre H en la tabla de caracteres ASCII

    sprintf(destingo, "%s %s %s", nombre, apellido1, apellido2)

    -------
    HOW TO CAPTURE AN STRING?
         we're going to use scanf("%s"...... for academic purpose
         we must skip the & character 

    strlen(string) returns an integer that represents string size

    strcpy(dst, src) is a void

    strcat is a void

    strcmp returns an integer

    sprintf is a void


    EJERCICIO
    Utilizando el algoritmo de ordenamiento de burbuja, realice una funcion que capture del usuario 5 textos y ordenelos de manera alfabetica de menor a mayor




*/

#include <stdio.h>
#include <string.h>

void sort(char words[], int size);

int main(){

    char words[5][30];

    int k = 0;
    while(k < 5){
        printf("Ingrese una palabra: ");
        scanf("%s", words[k]);
        getchar();
        k++;
    } 

    sort(words, 5);
    
    int n;
    for(n=0; n < k;n++){
        printf("%s \n", words[n]);
    }
    

    return 0;
}

void sort(char words[], int size){
    int i,j;
    char aux[30];
    for(i = 0; i <= size ;i++){
        for(j = i +1; j <= size-i; j++){
            if(strcmp(words[j], words[j+1]) > 0){
                strcpy(aux, words[j]);
                printf("AUX -> %s", aux);
                strcpy(words[j], words[j+1]);
                strcpy(words[j+1], aux);
            }
        }
    }
}