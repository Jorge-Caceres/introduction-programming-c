#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
/*
    Alumno: Jorge Caceres Flores
    C.I.: 4787628
    4-Dado el año cargado por el usuario, imprima todos los días del año y el total de días que corresponden al año:
*/
int formula(int year, int day, int accumulatedDays);
int getDayOfWeek(int d, int m, int y);
bool isYearLeap(int year);
const char *getMonthInLetters(int month);
int getDaysOfMonth(int month, bool isYearLeap);
const char *getDayInLetters(int day);

int main()
{

    int year = 0;
    printf("Introduzca un año, por favor: ");
    scanf("%d", &year);
    getchar();

    int count = 0;
    int month_number = 1;
    printf("Año: %d \n", year);
    while (month_number < 13)
    {
        char *month_in_word;
        //get the month in a word
        month_in_word = getMonthInLetters(month_number);
        //get the numbers of days that the month has
        int days_in_month = getDaysOfMonth(month_number, isYearLeap(year));
        int days_count = 1;
        while (days_count <= days_in_month)
        {
            int day_in_week = getDayOfWeek(days_count, month_number, year);
            char *day_in_word;
            day_in_word = getDayInLetters(day_in_week);
            printf("%s, %d de %s de %d \n", day_in_word, days_count, month_in_word, year);
            days_count++;
            count++;
        }
        month_number++;
    }
    printf("Cantidad de dias: %d \n", count);
    return 0;
}


int formula(int year, int day, int accumulatedDays)
{
    return ((year - 1) * 365 + (year - 1) / 4 - (3 * ((year - 1) / 100 + 1) / 4) + accumulatedDays + day) % 7;
}

int getDayOfWeek(int d, int m, int y)
{
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= m < 3;
    return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
}


bool isYearLeap(int year)
{
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        return 1;
    else
        return 0;
}

int getDaysOfMonth(int month, bool isYearLeap)
{

    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        return 31;
    }
    else if (month == 2)
    {
        if (isYearLeap)
        {
            return 29;
        }
        else
        {
            return 28;
        }
    }
    else
    {
        return 30;
    }
}

const char *getMonthInLetters(int month)
{

    switch (month)
    {
    case 1:
        return "Enero";
        break;
    case 2:
        return "Febrero";
        break;
    case 3:
        return "Marzo";
        break;
    case 4:
        return "Abril";
        break;
    case 5:
        return "Mayo";
        break;
    case 6:
        return "Junio";
        break;
    case 7:
        return "Julio";
        break;
    case 8:
        return "Agosto";
        break;
    case 9:
        return "Setiembre";
        break;
    case 10:
        return "Octubre";
        break;
    case 11:
        return "Noviembre";
        break;
    case 12:
        return "Diciembre";
        break;

    default:
        break;
    }
}

const char *getDayInLetters(int day)
{
    switch (day)
    {
    case 0:
        return "Domingo";
        break;
    case 1:
        return "Lunes";
        break;
    case 2:
        return "Martes";
        break;
    case 3:
        return "Miércoles";
        break;
    case 4:
        return "Jueves";
        break;
    case 5:
        return "Viernes";
        break;
    case 6:
        return "Sábado";
        break;
    default:
        break;
    }
}