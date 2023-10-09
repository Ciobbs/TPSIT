#include <stdio.h>
#include <stdlib.h>

#define DIM 10

int calcolaSomma(int v[], int n){
int somma  = 0;
    for(int k = 0; k < n; k++){
    somma += *(v + k);
}
return somma;
}

int main(){
int vett[DIM] = {1 , 3, 4, 4, 2, 6, 7, 9, 7, 10};
printf("La somma e' %d", calcolaSomma(vett, DIM));
}