#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sRegistro {
    int chave;
    char valor[100];
    struct sRegistro *prox;
} REGISTRO;

typedef REGISTRO* FILA;

void inserir(FILA *f, int chave, char *valor, int posicao);
void mostrar(FILA *f);
void excluir(FILA *f, int posicao);
int quantidade(FILA *f);
char * buscar(FILA *f, int chave);

int main () {

    FILA f = NULL;
    int opcao, chave, posicao;
    char valor[100];

    do {
        puts("1. Inserir REGISTRO");
        puts("2. Excluir REGISTRO");
        puts("3. Mostar FILA");
        puts("4. Quantidade de REGISTROS");
        puts("5. Buscar REGISTRO por chave");
        puts("6. Sair");
        scanf("%i", &opcao);

        switch (opcao) {
        case 1:
            printf("Informe a posicao (0-%i)", quantidade(&f));
            scanf("%i", &posicao);
            puts("Entre com a chave");
            scanf("%i", &chave);
            puts("Entre com o valor");
            scanf("%s", valor);
            inserir(&f, chave, valor, posicao);
            break;

        case 2:
            printf("Informe a posicao");
            scanf("%i", &posicao);
            excluir(&f, posicao);
            break;

        case 3:
            mostrar(&f);
            break;

        case 4:
            printf("Quantidade: %i\n", quantidade(&f));
            break;

        case 5:
            puts("Informe a chave");
            scanf("%i", &chave);
            printf("%s\n", buscar(&f, chave));
            break;

        default:
            break;
        }

    } while (opcao != 6);

    return 0;
}

void inserir(FILA *f, int chave, char *valor, int posicao) {

    REGISTRO *novoRegistro;

    novoRegistro = (REGISTRO*) malloc(sizeof(REGISTRO));
    novoRegistro->chave = chave;
    strcpy(novoRegistro->valor, valor);

    if (posicao == 0 || *f == NULL) {
        novoRegistro->prox = *f;
        *f = novoRegistro;
    } else {
        REGISTRO *anterior = NULL;
        REGISTRO *atual = *f;
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

void excluir(FILA *f, int posicao) {

    if(*f==NULL)
        return;

    if (posicao == 0) {
        REGISTRO *aux = *f;
        *f = (*f)->prox;
        free(aux);
        return;
    }

    REGISTRO *anterior = NULL;
    REGISTRO *atual = *f;
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

int quantidade(FILA *f) {
    if(*f==NULL)
        return 0;
    else
        return 1 + quantidade(&(*f)->prox);
}

char * buscar(FILA *f, int chave) {
    if(*f==NULL)
        return "Chave nao encontrada\n";
    else
        if ((*f)->chave == chave)
            return (*f)->valor;
        else
            return buscar(&(*f)->prox, chave);
}