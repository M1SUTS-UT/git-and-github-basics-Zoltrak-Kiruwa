#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double f(double x)
{
    return exp(x);
}

double rectIntegration(double start,double end,int stepNumber)
{
    double sum = 0;
    double h = (double)(end-start)/stepNumber;
    double x = start;

    for(int i = 0 ; i<= stepNumber-1; i++)
    {
        sum += h*f(x);  
        x += h;
    }
    return sum;
}

double trapezeIntegration(double start,double end,int stepNumber)
{
    double sum = 0;
    double h = (double)(end-start)/stepNumber;      
    double x_ancien = start;
    double x_nouv = h;

    for(int i = 0 ; i<= stepNumber-1; i++)
    { 
        sum += ((f(x_ancien)+f(x_nouv))/2);

        x_ancien = x_nouv;
        x_nouv   += h;
    }
    return h*sum;
}

double simpsonIntegration(double start,double end,int stepNumber)
{

    double h = (double)(end-start)/stepNumber;
    double sumPaire = 0;
    double sumImpaire = 0;
    double x = 0;

    for(int i = 0; i<= stepNumber; i++)
    {
        x += h;
        if(i%2 == 0)sumPaire += f(x);
        else {sumImpaire += f(x);};
    }

    return (h/3)*((f(start) + 4*sumImpaire + 2*sumPaire + f(end)));
}

int main()
{

    double start = 0;
    double end = 1;
    int stepNumber;

    /*printf("entrez la valeur de départ : ");
    scanf("%lf",&start);
    printf("entrez la valeur de d'arrivé : ");
    scanf("%lf",&end);*/

    printf("entrez le nombre de pas : ");
    scanf("%d",&stepNumber);

    double resRec = rectIntegration(start,end,stepNumber);
    printf("integrale rect entre [%lf,%lf] = %lf\n",start,end,resRec);    

    double resTrap = trapezeIntegration(start,end,stepNumber);
    printf("integrale trapeze entre [%lf,%lf] = %lf\n",start,end,resTrap);    

    double resSimpson = simpsonIntegration(start,end,stepNumber);
    printf("integrale simpson entre [%lf,%lf] = %lf\n",start,end,resSimpson);   

    FILE *fichier;
    fichier = fopen("mon_fichier.txt","w");

    if(fichier == NULL)
    {
        printf("erreur ouverture")
    }

    for(int i = 1 ; i<= (int)pow(10,8); i*=10)
    {
        resRec     =    rectIntegration(start,end,stepNumber);
        resTrap    = trapezeIntegration(start,end,stepNumber);
        resSimpson = simpsonIntegration(start,end,stepNumber);
        fprintf(fichier,"%d %lf %lf %lf",i,resRec,resTrap,resSimpson);
    }

    fclose(fichier);
    return 0;
}