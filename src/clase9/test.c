#include <stdio.h>
#include <string.h>

struct Movie
{

    char title[50];
    int year;
    float rate;
};

int main()
{

    struct Movie movie1;

    strcpy(movie1.title, "Star wars");
    movie1.year = 1984;
    movie1.rate = 9.4;

    printf(" Movie title %s\n", movie1.title);
    printf("Year %d\n", movie1.year);

    return 0;
}