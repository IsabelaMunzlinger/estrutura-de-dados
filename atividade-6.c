#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sRegistro {
    int chave;
    char valor[100];
    struct sRegistro *prox;
    struct sRegistro *ant;
} REGISTRO;

typedef REGISTRO* LISTA;

void inserir(LISTA *l, int chave, char *valor, int posicao);
void excluir(LISTA *l, int posicao);
void mostrar(LISTA l);

int main () {

    LISTA l = NULL;
    int opcao, chave, posicao;
    char valor[100];

    do {
        puts("1. Inserir REGISTRO");
        puts("2. Excluir REGISTRO");
        puts("3. Mostrar LISTA");
        puts("4. Sair");
        scanf("%i", &opcao);

        switch (opcao) {
        case 1:
            printf("Digite a chave: ");
            scanf("%d", &chave);
            printf("Digite o valor: ");
            scanf("%s", valor);
            printf("Digite a posição: ");
            scanf("%d", &posicao);
            inserir(&l, chave, valor, posicao);
            break;

        case 2:
            printf("Digite a posição: ");
            scanf("%d", &posicao);
            excluir(&l, posicao);
            break;

        case 3:
            mostrar(l);
            break;

        default:
            break;
        }

    } while (opcao != 4);

    return 0;
}

void inserir(LISTA *l, int chave, char *valor, int posicao) {

    REGISTRO *novoRegistro = (REGISTRO *)malloc(sizeof(REGISTRO));
    novoRegistro->chave = chave;
    strcpy(novoRegistro->valor, valor);
    
    if (*l == NULL) {
        novoRegistro->prox = NULL;
        novoRegistro->ant = NULL;
        *l = novoRegistro;
    } else if (posicao == 0) {
        novoRegistro->prox = *l;
        novoRegistro->ant = NULL;
        (*l)->ant = novoRegistro;
        *l = novoRegistro;
    } else {
        REGISTRO *anterior = *l;
        int i;
        for (i = 0; i < posicao - 1; i++) {
            if (anterior->prox == NULL)
                break;
            anterior = anterior->prox;
        }

        novoRegistro->prox = anterior->prox;
        novoRegistro->ant = anterior;
        if (anterior->prox != NULL)
            anterior->prox->ant = novoRegistro;
        anterior->prox = novoRegistro;
    }
}

void excluir(LISTA *l, int posicao) {
    if (*l == NULL) {
        printf("A LISTA está vazia.\n");
        return;
    }

    REGISTRO *aExcluir;
    if (posicao == 0) {
        aExcluir = *l;
        *l = (*l)->prox;
        if (*l != NULL)
            (*l)->ant = NULL;
    } else {
        REGISTRO *anterior = *l;
        int i;
        for (i = 0; i < posicao - 1; i++) {
            if (anterior == NULL)
                break;
            anterior = anterior->prox;
        }

        if (anterior == NULL || anterior->prox == NULL) {
            printf("Posição inválida.\n");
            return;
        }

        aExcluir = anterior->prox;
        anterior->prox = aExcluir->prox;
        if (aExcluir->prox != NULL)
            aExcluir->prox->ant = anterior;
    }

    free(aExcluir);
}

void mostrar(LISTA l) {
    if (l == NULL) {
        printf("A LISTA está vazia.\n");
        return;
    }

    REGISTRO *atual = l;
    while (atual != NULL) {
        printf("Chave: %d, Valor: %s\n", atual->chave, atual->valor);
        atual = atual->prox;
    }
}