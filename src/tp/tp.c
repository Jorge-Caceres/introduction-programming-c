#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/*
    Alumno: Jorge Caceres Flores
    C.I.: 4787628
*/

int execute_integer_operation(int n1, int n2, char *operator_symbol);
double execute_real_number_operation(double r, int operation);
const char *get_real_number_operation(int operation);
bool check_length(int number, int max_length);
int calculate_numerator(int num1, int den1, int num2, int den2, char *operation);
int calculate_denominator(int num1, int den1, int num2, int den2, char *operation);

int numberType(int type);

int main()
{
    int number_type;
    printf("Ingrese el codigo de acuerdo al tipo de numero con el que desea trabajar.\n (Enteros -> 1 / Reales -> 2 / Fraccionarios -> 3) : ");
    scanf("%d", &number_type);
    getchar();

    //integers
    if (number_type == 1)
    {

        int integer_1 = 0;
        int integer_2 = 0;

        printf("Ingrese un número entero de hasta 4 dígitos: ");
        scanf("%d", &integer_1);
        getchar();
        if (check_length(integer_1, 4))
        {
            char operator[] = "";
            printf("Ingrese la operacion que desea realizar -> + (suma) - (resta) * (multiplicacion) / (division) : ");
            scanf("%s", operator);
            getchar();

            printf("Ingrese otro número entero de hasta 4 dígitos: ");
            scanf("%d", &integer_2);
            getchar();
            if (check_length(integer_2, 4))
            {
                int integer_operation_result = execute_integer_operation(integer_1, integer_2, operator);
                printf("%d %s %d = %d\n", integer_1, operator, integer_2, integer_operation_result);
            }
            else
            {
                printf("El numero ingresado supera los cuatro digitos enteros permitidos\n");
            }
        }
        else
        {
            printf("El numero ingresado supera los cuatro digitos enteros permitidos\n");
        }
    }
    //reals numbers
    else if (number_type == 2)
    {

        int operation_type = 0;
        double real_number;

        printf("Tiene 8 operaciones posibles, digite el número de la operación a efectuar. \n 1 -> Raíz cuadrada | 2 -> Raíz cúbica | 3 -> Seno | 4 -> Coseno | 5 -> Logaritmo natural | 6 -> Logaritmo en base 10 | 7 -> Valor absoluto | 8 -> Tangente | :");
        scanf("%d", &operation_type);

        if (!(operation_type < 1 || operation_type > 8))
        {
            printf("Ingrese un número real sobre el que se aplicará la operación (Para los ángulos, ingrese el valor de 0 a 360 grados): ");
            scanf("%lf", &real_number);
            double real_number_result = execute_real_number_operation(real_number, operation_type);
            printf("%s de %lf = %lf \n", get_real_number_operation(operation_type), real_number, real_number_result);
        }
        else
        {
            printf("El numero de operacion ingresado no es valido. \n");
        }
    }
    //fractions
    else if (number_type == 3)
    {

        char fraction_1[] = "";
        char fraction_2[] = "";

        int num1, den1 = 0;
        int num2, den2 = 0;

        printf("Ingrese el numerador/denominador: ");
        scanf("%s", fraction_1);
        getchar();

        char *fraction_spl_1 = strtok(fraction_1, "/");
        while (fraction_spl_1 != NULL)
        {
            if (num1 == 0)
            {
                num1 = atoi(fraction_spl_1);
            }
            else if (den1 == 0)
            {
                den1 = atoi(fraction_spl_1);
            }
            fraction_spl_1 = strtok(NULL, "/");
        }

        char fractional_operator[] = "";
        printf("Ingrese la operacion que desea realizar -> + (suma) - (resta) * (multiplicacion) / (division) : ");
        scanf("%s", fractional_operator);
        getchar();

        printf("Ingrese el numerador/denominador: ");
        scanf("%s", fraction_2);
        getchar();
        char *fraction_spl_2 = strtok(fraction_2, "/");
        while (fraction_spl_2 != NULL)
        {
            if (num2 == 0)
            {
                num2 = atoi(fraction_spl_2);
            }
            else if (den2 == 0)
            {
                den2 = atoi(fraction_spl_2);
            }
            fraction_spl_2 = strtok(NULL, "/");
        }

        int numerator_result = calculate_numerator(num1, den1, num2, den2, fractional_operator);

        int denominator_result = calculate_denominator(num1, den1, num2, den2, fractional_operator);

        int reduce;
        if (numerator_result < denominator_result)
        {
            reduce = numerator_result;
        }
        else
        {
            reduce = denominator_result;
        }

        while (reduce > 1)
        {
            if (numerator_result % reduce == 0 && denominator_result % reduce == 0)
                break;
            reduce--;
        }

        float non_fraction_result = (float)numerator_result / (float)denominator_result;

        printf("%d/%d %s %d/%d = %d/%d = %.2f \n", num1, den1, fractional_operator, num2, den2, numerator_result / reduce, denominator_result / reduce, non_fraction_result);
    }

    printf("Presione ENTER para finalizar la ejecucion. \n");
    getchar();
    return 0;
}

bool check_length(int number, int max_length)
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

int execute_integer_operation(int n1, int n2, char *operator_symbol)
{
    if ('+' == *(operator_symbol))
    {

        return n1 + n2;
    }
    else if ('-' == *(operator_symbol))
    {

        return n1 - n2;
    }
    else if ('*' == *(operator_symbol))
    {

        return n1 * n2;
    }
    else if ('/' == *(operator_symbol))
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

const char *get_real_number_operation(int operation)
{

    switch (operation)
    {
    case 1:
        return "Raiz cuadrada";
        break;
    case 2:
        return "Raiz cubica";
        break;
    case 3:
        return "Seno";
        break;
    case 4:
        return "Coseno";
        break;
    case 5:
        return "Logaritmo natural";
        break;
    case 6:
        return "Logaritmo en base 10";
        break;
    case 7:
        return "Valor absoluto";
        break;
    case 8:
        return "Tangente";
        break;
    default:
        break;
    }
}

int calculate_numerator(int num1, int den1, int num2, int den2, char *operation)
{
    if ('+' == *(operation))
    {
        return (num1 * den2 + num2 * den1);
    }
    else if ('-' == *(operation))
    {
        return (num1 * den2 - num2 * den1);
    }
    else if ('*' == *(operation))
    {
        return num1 * num2;
    }
    else if ('/' == *(operation))
    {
        return num1 * den2;
    }
    else
    {
        return 0;
    }
}

int calculate_denominator(int num1, int den1, int num2, int den2, char *operation)
{
    if ('+' == *(operation) || '-' == *(operation) || '*' == *(operation))
    {
        return (den1 * den2);
    }
    else if ('/' == *(operation))
    {
        return den1 * num2;
    }
    else
    {
        return 0;
    }
}