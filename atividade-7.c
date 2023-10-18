#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sRegistro {
    int valor;
    struct sRegistro *prox;
} REGISTRO;

typedef REGISTRO* LISTA;

void inserir(LISTA *l, int valor, int posicao);
void excluir(LISTA *l, int posicao);
void mostrar(LISTA *l);
void bubbleSort(LISTA *l);

int main () {

    LISTA l = NULL;
    int opcao, valor, posicao;

    do {
        puts("1. Inserir REGISTRO");
        puts("2. Excluir REGISTRO");
        puts("3. Mostar LISTA");
        puts("4. Ordenar LISTA");
        puts("5. Sair");
        scanf("%i", &opcao);

        switch (opcao) {
        case 1:
            puts("Informe com o valor");
            scanf("%i", &valor);
            puts("Informe a posicao");
            scanf("%i", &posicao);
            inserir(&l, valor, posicao);
            break;

        case 2:
            puts("Informe a posicao");
            scanf("%i", &posicao);
            excluir(&l, posicao);
            break;

        case 3:
            mostrar(&l);
            break;

        case 4:
            bubbleSort(&l);
            break;

        default:
            break;
        }

    } while (opcao != 5);

    return 0;
}

void inserir(LISTA *l, int valor, int posicao) {

    REGISTRO *novoRegistro;

    novoRegistro = (REGISTRO*) malloc(sizeof(REGISTRO));
    novoRegistro->valor = valor;

    if (posicao == 0 || *l == NULL) {
        novoRegistro->prox = *l;
        *l = novoRegistro;
    } else {
        REGISTRO *anterior = NULL;
        REGISTRO *atual = *l;
        int contador = 0;

        while (atual != NULL && contador < posicao) {
            anterior = atual;
            atual = atual->prox;
            contador++;
        }
        novoRegistro->prox = atual;
        anterior->prox = novoRegistro;
    }
}

void excluir(LISTA *l, int posicao) {

    if(*l==NULL)
        return;

    if (posicao == 0) {
        REGISTRO *aux = *l;
        *l = (*l)->prox;
        free(aux);
        return;
    }

    REGISTRO *anterior = NULL;
    REGISTRO *atual = *l;
    int contador = 0;

    while (atual != NULL && contador < posicao) {
        anterior = atual;
        atual = atual->prox;
        contador++;
    }

    if (atual == NULL) {
        printf("Posição inválida\n");
        return;
    }

    anterior->prox = atual->prox;
    free(atual);
}

void mostrar(LISTA *l) {
    if(*l==NULL)
        return;
    else {
        printf("Valor: %i \n", (*l)->valor);
        mostrar(&(*l)->prox);
    }
}

void bubbleSort(LISTA *l) {
    int troca;
    REGISTRO *atual;
    REGISTRO *proximo = NULL;
    do {
        troca = 0;
        atual = *l;

        while (atual->prox != proximo) {
            if (atual->valor > atual->prox->valor) {
                // Trocar os valores
                int tempValor = atual->valor;
                atual->valor = atual->prox->valor;
                atual->prox->valor = tempValor;
                troca = 1;
            }
            atual = atual->prox;
        }
        proximo = atual;
    } while (troca);
}