#include <stdio.h>
#include <stdlib.h>

struct student
{
    char name[80];
    int age;
    float percentage;
};

int main()
{

    struct student st1 = {"Jorge", 22, 80.2};
    
    //declate a pointer which is also of the type that it will be allocate.
    struct student *ptr;

    ptr = &st1;

    //accessing to members of structure by a pointer.
    printf("Name [%s] Age [%d] Percentage [%.1f] \n", ptr->name, ptr->age, ptr->percentage);

    printf("%p", ptr);

    getchar();

}