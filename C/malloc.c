#include<stdio.h>
#include <stdlib.h>

typedef int* Tab;

int main()
{


int n = 10;
int* tab = (int*)malloc(10*sizeof(int));     //(int*) sécurité


for(int i = 0; i<=9 ;i++)
{
    scanf("%d",&tab[i]);
} 

for(int i = 0; i<=9 ;i++)
{
    printf("%d | ",tab[i]);
} 

printf("\n");

}