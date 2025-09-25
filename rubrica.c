#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct contatto{
    char nome[50];
    char cognome[50];
    int cellulare;
    struct contatto* next;
} contatto;


int main(){
    contatto* rubrica = NULL;
    char no[50];
    char cogno[50];
    int cellula;

    FILE* fp = fopen("file.txt", "r");
    if (fp == NULL){
        return 1;
    }
    int i = 0;
    while (fscanf(fp, "%s %s %d", &no[0], &cogno[0], &cellula) == 3){
        contatto* c = (contatto*)malloc(sizeof(contatto));
        printf("%s\t%s\t%d\n", no, cogno, cellula);
        strcpy(c->nome, no);
        strcpy(c->cognome, cogno);
        c->cellulare = cellula;
        c->next = NULL;
    }
    return 0;
}
