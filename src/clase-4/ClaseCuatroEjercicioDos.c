#include <stdio.h>
#include <stdbool.h>

/*
    Alumno: Jorge Caceres Flores.
    C.I.: 4787628

    Clase 4 - Ejercicio 2
    Dado un numero hasta 8 dígitos diga cuantos dígitos tiene el número. 3puntos extras

*/
int main()
{
    int n = 0;

    printf("Por favor, ingrese un numero de HASTA ocho digitos\n");
    scanf("%d", &n);
    int repNumber = n;
    int count = 0;
    while (n)
    {
        count++;
        n /= 10;
        if (count > 8)
        {
            printf("ERROR -> el numero %d tiene mas de ocho digitos \n", repNumber);
            return 0;
        }
    }

    printf("El numero [%d] tiene [%d] digitos \n", repNumber, count);

    return 0;
}
