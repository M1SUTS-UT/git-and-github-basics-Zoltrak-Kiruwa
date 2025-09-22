#include<stdio.h>


int main()
{
    int ** Mat;
    int x = 10;
    
    int* a = &x;
    *a = 45;

    printf("adresse de a %p \n",&a);
    printf("adresse pointé par a %p \n",a);
    printf("valeur pointé par a %d \n",*a);
    printf("valeur via x = %d\n", x);

}