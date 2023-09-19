/*
author:
date:
es. 1 ripasso
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM_RIGA 1000
#define NUM_RIGHE 20000

typedef struct {
    int num;
    char* nome;
    char* genere;
    int anno;
    char* disponibilita;
} Film;

int main() {
    char nomeFile[] = "listafilm.csv";
    char riga[DIM_RIGA];
    FILE *fp;
    char* campo;
    Film array_film[NUM_RIGHE];
    int dim = 0;
    fp = fopen(nomeFile, "r");
    if (fp == NULL) {
        printf("Errore nell'apertura del file.");
        return 0;
    }
    while (fgets(riga, DIM_RIGA, fp)) {
        campo = strtok(riga, ",");
        array_film[dim].num = atoi(campo);
        campo = strtok(NULL, ",");
        array_film[dim].nome = strdup(campo);
        campo = strtok(NULL, ",");
        array_film[dim].genere = strdup(campo);
        campo = strtok(NULL, ",");
        array_film[dim].anno = atoi(campo);
        campo = strtok(NULL, ",");
        array_film[dim].disponibilita = strdup(campo);
        printf("%d ", array_film[dim].num);
        printf("%s ", array_film[dim].nome);
        printf("%s ", array_film[dim].genere);
        printf("%d ", array_film[dim].anno);
        printf("%s \n", array_film[dim].disponibilita);
        dim++;
    }
}

