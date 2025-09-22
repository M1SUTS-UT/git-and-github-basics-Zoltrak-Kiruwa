#include<stdio.h>
#include <stdlib.h>


int main()
{


int n = 10;
int** tab = malloc(10*sizeof(int*));     //(int*) sécurité  
if(tab == NULL)
{
    printf("ERREUR ALLOCATION");
}

for (int i = 0 ; i <= 9 ; i++)
{                                                      
    tab[i] = malloc(10*sizeof(int));
    if(tab[i] == NULL)
    {
    printf("ERREUR ALLOCATION");
    }
}


for(int i = 0; i<=9 ;i++)
{
    
    for(int j = 0 ; j<=9 ; j++)
    {
        tab[i][j]= 1;
    }
} 

for(int i = 0; i<=9 ;i++)
{
    for(int j = 0 ; j<=9 ; j++)
    {
        printf("%d | ",tab[i][j]);
    }
    printf("\n");
} 





return 0;   

}