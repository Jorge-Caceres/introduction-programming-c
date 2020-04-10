#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/*
    Alumno: Jorge Caceres Flores
    C.I.: 4787628
*/

int execute_integer_operation(int n1, int n2, char *operatorSymbol);
double execute_real_number_operation(double r, int operation);
bool checkLength(int number, int max_length);

int numberType(int type);

int main()
{
    int n1 = 0;
    int n2 = 0;
    char user_response[] = "Y";

    int number_type;

    printf("Ingrese el codigo de acuerdo al tipo de numero con el que desea trabajar. (Enteros -> 1 / Reales -> 2 / Fraccionarios -> 3) : ");
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

        int integer_operation_result = execute_integer_operation(integer_1, integer_2, operator);
        printf("%d %s %d = %d\n", integer_1, operator, integer_2, integer_operation_result);
    }
    else if (number_type == 2)
    {

        int operation_type = 0;
        double real_number;

        printf("Tiene 8 operaciones posibles, digite el número de la operación a efectuar. Raíz cuadrada -> 1 Raíz cúbica -> 2 \n Seno -> 3 Coseno -> 4 \n Logaritmo natural -> 5 Logaritmo en base 10 -> 6 \n Valor absoluto -> 7 Tangente -> 8 ")
            scanf("%d", &operation_type);

        printf("Ingrese un número real sobre el que se aplicará la operación: ");
        scanf("%lf", &real_number);

        double real_number_result = execute_real_number_operation(r, operation_type);
        printf("%s %lf", real_number_result);

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
int execute_integer_operation(int n1, int n2, char *operatorSymbol)
{
    if ('+' == *(operatorSymbol))
    {

        return n1 + n2;
    }
    else if ('-' == *(operatorSymbol))
    {

        return n1 - n2;
    }
    else if ('*' == *(operatorSymbol))
    {

        return n1 * n2;
    }
    else if ('/' == *(operatorSymbol))
    {

        return n1 / n2;
    }
    else
    {
        return 0;
    }
}

//Raíz cuadrada -> 1 Raíz cúbica -> 2 \n Seno -> 3 Coseno -> 4 \n Logaritmo natural -> 5 Logaritmo en base 10 -> 6 \n Valor absoluto -> 7 Tangente -> 8 ")
double execute_real_number_operation(double r, int operation)
{

    switch (operation)
    {
    case 1:
        return sqrt(r);
        break;
    case 2:
        return cbrt(r);
        break;
    case 3:
        return sin(r);
        break;
    case 4:
        return cos(r);
        break;
    case 5:
        return log(r);
        break;
    case 6:
        return log10(r);
        break;
    case 7:
        return fabs(r);
        break;
    case 8:
        return tan(r);
        break;
    default:
        break;
    }
}
