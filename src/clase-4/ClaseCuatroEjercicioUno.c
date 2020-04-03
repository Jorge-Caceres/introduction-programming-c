#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool checkPalindrome(int number);
char *getLetter(int number);

/*
    Alumno: Jorge Caceres Flores.
    C.I.: 4787628

    Clase 4 - Ejercicio 1
    Dado un numero hasta 8 dígitos diga cuantos dígitos tiene el número. 3puntos extras

*/
int main()
{
    int n = 0;
    int number = 0;
    printf("Por favor, ingrese un numero de ocho digitos\n");
    scanf("%d", &n);
    number = n;

    if (checkPalindrome(n))
    {
        char* numbersAsLetters[7];
        int digit;
        while (n)
        {
            digit = n % 10;
            n /= 10;
            char* letter = getLetter(digit);
            printf("Letter %s \n", letter);
            strcat(numbersAsLetters, letter);
        }
        printf("El palindromo [%d] se representa por las letras [%s] \n", number, numbersAsLetters);
    }
    else
    {
        printf("El numero %d no es palindromo\n", number);
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

char *getLetter(int number)
{
    switch (number)
    {
    case 0:
        return "A";
        break;
    case 1:
        return "B";
        break;
    case 2:
        return "C";
        break;
    case 3:
        return "D";
        break;
    case 4:
        return "E";
        break;
    case 5:
        return "F";
        break;
    case 6:
        return "G";
        break;
    case 7:
        return "H";
        break;
    case 8:
        return "I";
        break;
    case 9:
        return "J";
        break;
    default:
        break;
    }
}