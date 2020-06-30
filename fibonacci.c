#include <stdio.h>

/*
    Alumno: Jorge Ariel Caceres Flores.
    C.I.: 4787628

*/

int fibonacci(int num);

int main()
{

    int number;

    printf("Ingrese la posicion del numero de fibonacci que quiere obtener: ");
    scanf("%d", &number);

    int result = fibonacci(number);
    printf("El %dº numero de la serie de fibonacci es : %d\n", number, result);
}

int fibonacci(int num)
{
    int result;
    if (num == 0)
    {
        result = 0;
    }
    else if (num == 1)
    {
        result = 1;
    }
    else
    {
        result = (fibonacci(num - 1) + fibonacci(num - 2));
    }
    return result;
}
