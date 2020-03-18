#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
    Alumno: Jorge Caceres Flores
    C.I.: 4787628
*/
int formula(int year, int day, int accumulatedDays);
int getDayOfWeek(int d, int m, int y);
int getAccumulatedDays(int month, int year);
bool isYearLeap(int year);
const char *getMonth(int month);

int main()
{

    char date[] = "";
    printf("Cargue una fecha en formato dd/mm/aaaa: ");
    scanf("%s", &date);
    getchar();

    int year = 0;
    int day = 0;
    int month = 0;

    char *dateSpl = strtok(date, "/");
    while (dateSpl != NULL)
    {
        if (day == 0)
        {
            day = atoi(dateSpl);
        }
        else if (month == 0)
        {
            month = atoi(dateSpl);
        }
        else if (year == 0)
        {
            year = atoi(dateSpl);
        }
        dateSpl = strtok(NULL, "/");
    }

    int accumulatedDays = getAccumulatedDays(month, year);
    int days = formula(year, day, accumulatedDays);
    int dayW = getDayOfWeek(day, month, year);

    printf("Mes del anho en letras [%s] y en numero [%d]", getMonth(month), month);
    printf("\n Dias acumulados hasta el inicio del mes %s: %d", getMonth(month), accumulatedDays);
    printf("\n Dia de la semana: %d \n", getDayOfWeek(day, month, year));

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

int getAccumulatedDays(int month, int year)
{
    int accumulatedDays = 0;

    if (isYearLeap(year))
    {
        accumulatedDays += 29;
    }
    else
    {
        accumulatedDays += 28;
    }

    for (int i = 1; i < month; i++)
    {

        if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
        {
            accumulatedDays += 30;
        }
        else if (month != 2)
        {
            accumulatedDays += 31;
        }
    }
    return accumulatedDays;
}

bool isYearLeap(int year)
{
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        return 1;
    else
        return 0;
}

const char *getMonth(int month)
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
