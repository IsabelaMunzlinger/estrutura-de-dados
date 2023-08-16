#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float altura;
    float largura;
    float profundidade;
} REGISTRO;

int main () {

    REGISTRO *registros;
    int opcao, posicao, quantidade = 0;

    do {
        puts("1 - Inserir registro");
        puts("2 - Alterar registro");
        puts("3 - Excluir registro");
        puts("4 - Mostrar registros");
        puts("5 - Sair");
        scanf("%i", &opcao);

        switch (opcao) {
        case 1:
            if (quantidade == 0) {
                registros = malloc(sizeof(REGISTRO));
            }
            else {
                registros = realloc(registros, (quantidade+1) * sizeof(REGISTRO));
            }
            puts("Informe a altura");
            scanf("%f", &registros[quantidade].altura);
            puts("Informe a largura");
            scanf("%f", &registros[quantidade].largura);
            puts("Informe a profundidade");
            scanf("%f", &registros[quantidade].profundidade);
            quantidade++;
            break;

        case 2:
            printf("Informe uma posicao (0-%i)", quantidade-1);
            scanf("%i", &posicao);
            puts("Informe a altura");
            scanf("%f", &registros[posicao].altura);
            puts("Informe a largura");
            scanf("%f", &registros[posicao].largura);
            puts("Informe a profundidade");
            scanf("%f", &registros[posicao].profundidade);
            break;

        case 3:
            registros = realloc(registros, (quantidade-1) * sizeof(REGISTRO));
            quantidade--;
            break;

        case 4:
            for (int i = 0; i < quantidade; i++) {
                printf("Altura: %.2f ", registros[i].altura);
                printf("Largura: %.2f ", registros[i].largura);
                printf("Profundidade: %.2f \n", registros[i].profundidade);
            }
            break;

        default:
            break;
        }

    } while (opcao != 5);
}