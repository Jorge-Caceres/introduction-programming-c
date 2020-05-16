#include <stdio.h>
#include <string.h>

void sort(char words[][30], int size);

int main(){

    char words[5][30];

    int k = 0;
    while(k < 5){
        printf("Ingrese una palabra: ");
        scanf("%s", words[k]);
        getchar();
        k++;
    } 

    sort(words, k);
    
    int n;
    for(n=0; n < k;n++){
        printf("%s \n", words[n]);
    }
    

    return 0;
}

void sort(char words[][30], int size)
{
    int i,j;
    char aux[30];
    for(i = 1; i <= size ;i++)
    {
        for(j = 0; j <= size-i; j++)
        {
            if(strcmp(words[j], words[j+1]) > 0)
            {
                strcpy(aux, words[j]);
                strcpy(words[j], words[j+1]);
                strcpy(words[j+1], aux);
            }
        }
    }
}