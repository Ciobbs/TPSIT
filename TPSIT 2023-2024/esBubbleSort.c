#include <stdio.h>
#include <stdlib.h>
#define DIM 100
void scambio(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleSort1(int vett[], int n){
int k, sup;
    for (sup = n-1; sup > 0; sup--){
        for (k = 0; k < sup ; k++){
            if (*(vett + k) > *(vett + k + 1)){
                scambio(vett + k ,vett + k + 1);
            }
        }
    }
}
void stampaVett(int v[], int n){
    for(int k = 0; k < n; k++){
        printf("%d ", *(v + k));
    }

}
int main(){
    int vett[DIM] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 2, 5, 22};
    bubbleSort1(vett, 12);
    stampaVett(vett, 12);
    return 0;
}