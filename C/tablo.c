#include<stdio.h>


int main(){

   int tab[10][10];

   for(int i = 0; i<=9 ;i++)
    {
        for(int j = 0 ; j<=9 ; j++)
        {
            tab[i][j] = 1;
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

   printf("\n");
}