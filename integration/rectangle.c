#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double f(double x)
{
    return sin(x);
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
    double x_nouv = start + h;

    for(int i = 0 ; i<= stepNumber-1; i++)
    { 
        sum += ((f(x_ancien)+f(x_nouv))/2);

        x_ancien = x_nouv;
        x_nouv   += h;
    }
    return h*sum;
}

double simpsonIntegration(double start, double end, int stepNumber)
{
    if (stepNumber % 2 != 0) {
        // Simpson nécessite un nombre pair de sous-intervalles
        printf("Erreur: stepNumber doit être pair.\n");
        return NAN; 
    }

    double h = (end - start) / (double) stepNumber;
    double sumPaire = 0.0;
    double sumImpaire = 0.0;

    for (int i = 1; i < stepNumber; i++) {
        double xi = start + i * h;
        if (i % 2 == 0) sumPaire   += f(xi);       // indices pairs (sauf extrêmes)
        else            sumImpaire += f(xi);       // indices impairs
    }

    return (h/3.0) * (f(start) + f(end) + 4.0*sumImpaire + 2.0*sumPaire);
}

int main()
{

    double start = 0;
    double end = 1;
    int stepNumber = 1000;

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
        printf("erreur ouverture");
    }

    for(int i = 0 ; i<= (int)pow(10,4); i+=10)
    {
        printf("i = %d",i);
        resRec     =    rectIntegration(start,end,i);
        resTrap    = trapezeIntegration(start,end,i);
        resSimpson = simpsonIntegration(start,end,i);

        fprintf(fichier,"%d %.20lf %.20lf %.20lf \n",i,resRec,resTrap,resSimpson);
    }

    fclose(fichier);

    /*printf("entrez la valeur de départ : ");
    scanf("%lf",&start);
    printf("entrez la valeur de d'arrivé : ");
    scanf("%lf",&end);

    printf("entrez le nombre de pas : ");
    scanf("%d",&stepNumber);  */

    return 0;
}