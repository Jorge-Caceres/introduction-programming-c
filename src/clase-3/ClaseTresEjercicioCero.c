#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
    Alumno: Jorge Caceres Flores
    C.I.: 4787628

    Crear una calculadora que acepte la siguiente entrada numero operador numero ej 4 + 5 dar el resultado 9
    las operaciones son
    suma +
    resta -
    multiplicacion * (a través de sumas sucesivas)
    division / (a través de restas sucesivas)
*/

int executeOperation(int n1, int n2, char *operatorSymbol);
int addition(int n1, int n2);
int substraction(int n1, int n2);
int multiplication(int multiplicand, int multiplier);
int division(int dividend, int divisor);

int main()
{
    int n1 = 0;
    int n2 = 0;
    printf("Ingrese un numero: ");
    scanf("%d",&n1);
	getchar();
    
    char operator[]="";
    printf("Ingrese la operacion que desea realizar -> + (suma) - (resta) * (multiplicacion) / (division) : ");
    scanf("%s", operator);
    getchar();

    printf("Ingrese otro numero: ");
    scanf("%d",&n2);
	getchar();
    int result = executeOperation(n1, n2, operator);
    printf("El resultado de %d %s %d es %d \n", n1, operator, n2, result);

    return 0;
}

//Executes the operation by the provided operator.
int executeOperation(int n1, int n2, char *operatorSymbol)
{
    if('+'==*(operatorSymbol))
    {
        
        return addition(n1, n2);
    }else if('-'==*(operatorSymbol)){
        
        return substraction(n1, n2);
    }else if('*'==*(operatorSymbol)){
        
        return multiplication(n1, n2);
    }else if('/'==*(operatorSymbol)){
        
        return division(n1, n2);
    }else{
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

int multiplication(int multiplicand, int multiplier){
    
    int accumulated=0;
    int product = 0;
	while(accumulated<multiplier)
	{
		accumulated++;
        product += multiplicand;
	}
    return product;
}

int division(int dividend, int divisor){
    int substraction=dividend;
    int accumulated=0;
	while(substraction>=divisor)
	{
		accumulated++;
        substraction -= divisor;
	}
    return accumulated;
}

