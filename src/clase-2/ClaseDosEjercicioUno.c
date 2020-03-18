#include <stdio.h>

/*
    Alumno: Jorge Caceres Flores
    C.I.: 4787628
*/

int getQuocient(int divisor, int dividendo);
int getReminder(int divisor, int dividendo);

int main()
{
    int divisor=0;
    int dividendo=0;
    printf("Cargue un numero que sera el divisor: ");
	scanf("%d",&divisor);
	getchar();

    printf("Cargue un numero que sera el dividendo: ");
	scanf("%d",&dividendo);
	getchar();
	
    int cociente=0;
    int resto = 0;

    cociente = getQuocient(divisor, dividendo);
    resto = getReminder(divisor, dividendo);

    printf(" %d divido %d \n Cociente -> %d  \n Resto -> %d \n", dividendo, divisor, cociente, resto);

	return 0;
}

/* Returns a quocient based on the provided divisor and dividend */
int getQuocient(int divisor, int dividendo)
{
	int resta=dividendo;
    int contador=0;
	while(resta>=divisor)
	{
        printf("Valor de la resta %d contador %d \n", resta, contador);
		contador++;
        resta -= divisor;
	}
    return contador;
}

/* Returns the reminder of a division */
int getReminder(int divisor, int dividendo){
    return dividendo%divisor;
}
