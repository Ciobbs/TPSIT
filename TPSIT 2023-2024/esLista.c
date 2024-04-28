#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int valore;
    struct node* next;   
} Node;

// Funzione per calcolare la lunghezza della lista iterativamente
int calcolaLunghezza(Node* lista){
    Node* l = lista;
    int lung = 0;
    while (l != NULL)
    {
        lung++;
        l = l ->next;
    }
    return lung; 
}

// Funzione per calcolare la lunghezza della lista ricorsivamente
int ricorsivaLunghezza(Node* lista, int lung){
    Node* l = lista;
    if(l != NULL){
        lung++;
        lung = ricorsivaLunghezza(l->next, lung);
    }
    return lung;
}

// Funzione per stampare gli elementi della lista
void stampaLista(Node* lista){
    Node* l = lista;
    printf("\nValori lista: ");
    while (l != NULL)
    {
        printf("%d ", l->valore);
        l = l ->next;
    }
}

// Funzione per stampare gli elementi della lista ricorsivamente
void stampaListaRicorsiva(Node* lista){
    Node* l = lista;
    if(l != NULL){
        printf("%d ", l->valore);
        stampaListaRicorsiva(l->next);
    }
}

// Funzione per contare gli elementi della lista ricorsivamente
int contaElementiRicorsivo(Node* head){
    if (head != NULL){
        return 1 + contaElementiRicorsivo(head->next);
    }
    return 0;  // Restituisce 0 per una lista vuota
}

// Funzione per aggiungere un elemento alla fine della lista
void aggiungiElemento(Node** head, int valore){
    Node* nuovoNodo = (Node*)malloc(sizeof(Node));
    nuovoNodo->valore = valore;
    nuovoNodo->next = NULL;

    if (*head == NULL){
        *head = nuovoNodo;
    } else {
        Node* temp = *head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = nuovoNodo;
    }
}

//Funzione per aggiungere l'elemento alla fine
void aggiungiElementoFine(Node** head, int valore){
    Node* nuovoNodo = (Node*)malloc(sizeof(Node));
    nuovoNodo->valore = valore;
    nuovoNodo->next = NULL;

    if (*head == NULL){
        *head = nuovoNodo;
    } else {
        Node* temp = *head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = nuovoNodo;
    }
}
    // Funzione per aggiungere un elemento all'inizio della lista
void aggiungiElementoInizio(Node<<<<** head, int valore) {
    Node* nuovoNodo = (Node*)malloc(sizeof(Node));
    nuovoNodo->valore = valore;
    nuovoNodo->next = *head; 

    *head = nuovoNodo; 
}
int main(){
    int numero, numero2;
    int n;
    int lung = 0;
    Node* lista = NULL;
    Node* l;

    do {
        printf("Inserire un numero naturale o -1 per terminare: ");
        scanf("%d", &n);

        if (n >= 0){
            if (lista == NULL){
                lista = (Node*)malloc(sizeof(Node));
                l = lista;
            } else {
                l->next = (Node*)malloc(sizeof(Node));
                l = l->next;
            }

            l->valore = n;
            l->next = NULL;
        }

    } while (n >= 0);

    l = lista;
    printf("Numeri inseriti: ");
    printf("\n");
    while (l != NULL)
    {
        printf("%d - %p \n", l->valore, l->next);
        l = l->next;
    }

    printf("\n");
    printf("Numero di elementi: %d", calcolaLunghezza(lista));
    printf("\nNumero di elementi con ricorsiva: %d", ricorsivaLunghezza(lista, lung));
    stampaLista(lista);
    printf("\nValori lista ricorsiva: ");
    stampaListaRicorsiva(lista);
    printf("\nNumero di elementi con ricorsiva: %d", contaElementiRicorsivo(lista));
    printf("Inserisci il numero che vuoi aggiungere alla fine: \n");
    scanf("%d", &numero);
    aggiungiElementoFine(&lista, numero);
    stampaLista(lista);
    printf("Inserisci il numero che vuoi aggiungere al inizio: \n");
    scanf("%d", &numero2);
    aggiungiElementoInizio(&lista, numero2);
    stampaLista(lista);
    return 0;
}
