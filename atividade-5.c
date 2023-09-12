#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sRegistro {
    int chave;
    char valor[100];
    struct sRegistro *prox;
} REGISTRO;

typedef REGISTRO* FILA;

void inserir(FILA *f, int chave, char *valor);
void mostrar(FILA *f);
void excluir(FILA *f);

main () {

    FILA f = NULL;
    int opcao, chave;
    char valor[100];

    do {
        puts("1. Inserir REGISTRO");
        puts("2. Excluir REGISTRO");
        puts("3. Mostar FILA");
        puts("4. Sair");
        scanf("%i", &opcao);

        switch (opcao) {
        case 1:
            puts("Entre com a chave");
            scanf("%i", &chave);
            puts("Entre com o valor");
            scanf("%s", valor);
            inserir(&f, chave, valor);
            break;

        case 2:
            excluir(&f);
            break;

        case 3:
            mostrar(&f);
            break;

        default:
            break;
        }

    } while (opcao != 4);
}

void inserir(FILA *f, int chave, char *valor) {
    if(*f==NULL){
        *f = (FILA) malloc(sizeof(REGISTRO));
        (*f)->chave = chave;
        strcpy((*f)->valor, valor);
        (*f)->prox = NULL;
    }
    else
        inserir(&(*f)->prox, chave, valor);
}

void mostrar(FILA *f) {
    if(*f==NULL)
        return;
    else {
        printf("%i \n", (*f)->chave);
        printf("%s \n", (*f)->valor);
        printf("\n");
        mostrar(&(*f)->prox);
    }
}

void excluir(FILA *f) {
    REGISTRO *aux;
    if(*f==NULL)
        return;
    aux = *f;
    *f = (*f)->prox;
    free(aux);
}