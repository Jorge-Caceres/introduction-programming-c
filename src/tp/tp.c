#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/*
    Alumno: Jorge Caceres Flores
    C.I.: 4787628
*/

int executeOperation(int n1, int n2, char *operatorSymbol);
int addition(int n1, int n2);
int substraction(int n1, int n2);
int multiplication(int multiplicand, int multiplier);
int division(int dividend, int divisor);
bool checkLength(int number, int max_length);

int numberType(int type);

int main()
{
    int n1 = 0;
    int n2 = 0;
    char user_response[] = "Y";

    int number_type;

    printf("Ingrese el codigo de acuerdo al tipo de numero con el que desea trabajar. (Enteros = 1 / Reales = 2 / Fraccionarios = 3) : ");
    scanf("%d", &number_type);
    getchar();

    if (number_type == 1)
    {

        int integer_1 = 0;
        int integer_2 = 0;

        printf("Ingrese un número entero de hasta 4 dígitos: ");
        scanf("%d", &integer_1);
        getchar();
        if (!checkLength(integer_1, 4))
        {
            printf("El numero ingresado supera los cuatro digitos permitidos\n");
            return 0;
        }

        char operator[] = "";
        printf("Ingrese la operacion que desea realizar -> + (suma) - (resta) * (multiplicacion) / (division) : ");
        scanf("%s", operator);
        getchar();

        printf("Ingrese otro numero: ");
        scanf("%d", &integer_2);
        getchar();
        if (!checkLength(integer_2, 4))
        {
            printf("El numero ingresado supera los cuatro digitos permitidos\n");
            return 0;
        }

        int integer_operation_result = executeOperation(integer_1, integer_2, operator);
        printf("%d %s %d = %d\n", integer_1, operator, integer_2, integer_operation_result);
    }

    getchar();
    return 0;
}

bool checkLength(int number, int max_length)
{
    int digits = floor(log10(abs(number))) + 1;
    if (digits > max_length)
    {
        return false;
    }
    else
    {
        return true;
    }
}

//Executes the operation by the provided operator.
int executeOperation(int n1, int n2, char *operatorSymbol)
{
    if ('+' == *(operatorSymbol))
    {

        return addition(n1, n2);
    }
    else if ('-' == *(operatorSymbol))
    {

        return substraction(n1, n2);
    }
    else if ('*' == *(operatorSymbol))
    {

        return multiplication(n1, n2);
    }
    else if ('/' == *(operatorSymbol))
    {

        return division(n1, n2);
    }
    else
    {
        return 0;
    }
}

int addition(int n1, int n2)
{
    return n1 + n2;
}

int substraction(int n1, int n2)
{
    return n1 - n2;
}

int multiplication(int multiplicand, int multiplier)
{

    int accumulated = 0;
    int product = 0;
    while (accumulated < multiplier)
    {
        accumulated++;
        product += multiplicand;
    }
    return product;
}

int division(int dividend, int divisor)
{
    int substraction = dividend;
    int accumulated = 0;
    while (substraction >= divisor)
    {
        accumulated++;
        substraction -= divisor;
    }
    return accumulated;
}
