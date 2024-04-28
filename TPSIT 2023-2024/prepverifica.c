#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int valore;
    struct node* next;
}Node;

int main(){
    int lung = 0;
    int n; 
    Node* lista = NULL;
    Node* l;
    do{
        printf("Inserisci un numero naturale o -1 per terminare");
        scanf("%d", &n);
        if(n > 0){
            if(lista == NULL){
                lista = (Node*)malloc(sizeof(Node));
                l = lista
            }else{
                l->next = (Node*)malloc(sizeof(Node));
                l->next;
            }
        }
        l->valore = n;
        l->next = NULL;

    }while(n != 0);
}