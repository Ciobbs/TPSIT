/*-Creare un file .csv con COGNOME, NOME, NASCITA (annomesegiorno in formato INT)
-scorrere il file con la funzione FGETS e STRTOK
-stampare in ordine DECRESCENTE (dal più grande al più piccolo)
 utilizzando i puntatori e allocazione dinamica (MALLOC)*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 10
#define LUNG 100

typedef struct {
    int giorno;
    int mese;
    int anno;
} Data;

typedef struct {
    char cognome[LUNG];
    char nome[LUNG];
    Data data;
} Struttura;

int leggiFile(Struttura **st, char nomeFile[]) {
    FILE *fp = fopen(nomeFile, "r");
    if (fp == NULL) {
        printf("Impossibile aprire il file %s\n", nomeFile);
        exit(1);
    }

    char riga[LUNG];
    int counter = 0;

    *st = malloc(sizeof(Struttura));  // Alloca il primo elemento dell'array

    if (*st == NULL) {
        printf("Errore di allocazione di memoria.\n");
        exit(1);
    }

    while (fgets(riga, LUNG, fp)) {
                

        char *campo = strtok(riga, ",");
        strcpy((*st)[counter].cognome, campo);

        campo = strtok(NULL, ",");
        strcpy((*st)[counter].nome, campo);

        campo = strtok(NULL, ",");
        (*st)[counter].data.giorno = atoi(campo);

        campo = strtok(NULL, ",");
        (*st)[counter].data.mese = atoi(campo);

        campo = strtok(NULL, ",");
        (*st)[counter].data.anno = atoi(campo);

        counter++;
    }

    fclose(fp);
    return counter;
}


int main() {
    Struttura st[DIM];
    char nomeFile[LUNG] = "es1.csv";
    int dim = leggiFile(st, nomeFile, DIM);

    if (dim > 0) {
        for (int i = 0; i < dim; i++) {
            printf("Cognome: %s\n", st[i].cognome);
            printf("Nome: %s\n", st[i].nome);
            printf("Giorno: %d\n", st[i].data.giorno);
            printf("Mese: %d\n", st[i].data.mese);
            printf("Anno: %d\n\n", st[i].data.anno);
        }
    } else {
        printf("Nessun dato valido nel file.\n");
    }

    return 0;
}
