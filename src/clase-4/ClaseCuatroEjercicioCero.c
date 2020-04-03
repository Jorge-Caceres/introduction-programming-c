#include <stdio.h>
#include <stdbool.h>

bool checkPalindrome(int number);

/*
    Alumno: Jorge Caceres Flores.
    C.I.: 4787628

    Clase 4 - Ejercicio 0
    Dado un numero de 8 cifras diga si el mismo es palíndromo o capicua o no lo es, es decir que el formato numérico sea ABCDDCBA.
*/
int main()
{
    int n = 0;
    printf("Por favor, ingrese un numero de ocho digitos\n");
    scanf("%d", &n);

    if (checkPalindrome(n))
    {
        printf("El numero %d es un palindromo o capicua.\n", n);
    }
    else
    {
        printf("El numero %d no es palindromo\n", n);
    }
    return 0;
}

bool checkPalindrome(int number)
{
    int t, r = 0;

    t = number;
    while (t != 0)
    {
        r = r * 10;
        r = r + t % 10;
        t = t / 10;
    }

    if (number == r)
    {
        return true;
    }
    else
    {
        return false;
    }
}