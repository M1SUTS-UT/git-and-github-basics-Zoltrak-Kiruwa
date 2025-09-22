#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int factorial(int n)
{
    int res = 1;

    for (int i = 1 ; i<=n ; i++)
    {
        res *=i;
    }

    return res;
}

double expfunc(double x,int order)
{
    double sum = 0;
    for(int i = 0 ; i<=order; i++)
    {
        sum +=  pow(x,i)/factorial(i);
    }
    return sum;
}

int main()
{
    
    int order;
    double x;

    printf("Entrez l'ordre voulue : ");
    scanf("%d",&order);

    printf("Entrez le réel en argurment : ");
    scanf("%lf",&x);

    printf("exp func = %lf \n",expfunc(x,order));
    printf("exp  = %lf \n",exp(x));
    
    return 0;
}