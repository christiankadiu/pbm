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


void printContacts(contatto* lista){
    contatto *tmp = lista;

    printf("iniziamo a stampare\n");
    while(tmp){
        printf("%s\t", tmp->nome);
        printf("%s\t", tmp->cognome);
        printf("%d\n", tmp->cellulare);

        tmp = tmp->next;
    }
}

void save(contatto* lista, FILE* f){
    while(lista){
        fprintf(f, "%s\t%s\t%d\n", lista->nome, lista->cognome, lista->cellulare);
        lista = lista->next;
    }
}

int main(int argc, char *argv[]){
    contatto *rubrica = NULL;
    contatto *tmp;
    char no[50];
    char cogno[50];
    int cellula;

    FILE* fp = fopen("file.txt", "r+");
    if (fp == NULL){
        return 1;
    }
    int i = 0;
    while (fscanf(fp, "%s %s %d", &no[0], &cogno[0], &cellula) == 3){
        contatto* c = (contatto*)malloc(sizeof(contatto));
        //printf("%s\t%s\t%d\n", no, cogno, cellula);
        strcpy(c->nome, no);
        strcpy(c->cognome, cogno);
        c->cellulare = cellula;
        c->next = NULL;
        if (i == 0) {
            tmp = c;
            rubrica = tmp;
            i++;
        }
        tmp->next = c;
        tmp = tmp->next;
    }
    
    //visualizzare l'intera rubrica
    if (strcmp(argv[1], "v") == 0){
        printContacts(rubrica);
    }
    // se l'argomento è "c" allora crea un nuovo contatto e lo aggiunge in rubrica
    if (strcmp(argv[1], "c") == 0){
        contatto *tmp = rubrica;
        while(tmp->next){
            tmp = tmp->next;
        }
        contatto *tmp2 = (contatto*)malloc(sizeof(contatto));
        scanf("%s", tmp2->nome);
        scanf("%s", tmp2->cognome);
        scanf("%d", &tmp2->cellulare);
        tmp->next = tmp2;
        tmp = tmp->next;
        printContacts(rubrica);
    }

    if (strcmp(argv[1], "s") == 0){
        save(rubrica, fp);
    }
    return 0;
}
