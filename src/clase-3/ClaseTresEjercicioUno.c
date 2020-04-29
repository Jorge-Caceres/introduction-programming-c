#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
    Alumno: Jorge Caceres Flores
    C.I.: 4787628

    Crear una funcion que utilizando la funcion de sumas sucesivas realice la potencia de un numero elevado a otro numero

    P (p mayuscula)
    Ej:
    4 P 2 resultado 16
*/

int powerTo(int base, int exponent);
int multiplication(int multiplicand, int multiplier);


int main()
{
    int n1 = 0;
    int n2 = 0;
    printf("Calculador. Por favor, especifique los numeros y el operador matematico. \n");
    printf("Ingrese un numero: ");
    scanf("%d",&n1);
	getchar();

    printf("Ingrese otro numero: ");
    scanf("%d",&n2);
	getchar();

    int result = powerTo(n1, n2);
    printf("El resultado de %d P %d es %d \n", n1, n2, result);

    return 0;
}


int powerTo(int base, int exponent){
    
    int result = base;
    if(exponent == 0){
        return 1;
    }else{
        int i = 0;
        while(i < (exponent-1)){
            result = multiplication(result, base);
            i++;
        }
        return result;
    }
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
