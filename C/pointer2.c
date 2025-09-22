#include<stdio.h>

// Fonction qui prend un pointeur sur int
void setValue(int* p) {
    *p = 42;  // on modifie la valeur à l'adresse pointée
}

int main() {
    
    int x = 10;

    printf("Avant : x = %d\n", x);

    setValue(&x);  // on passe l'adresse de x

    printf("Après : x = %d\n", x);

    return 0;