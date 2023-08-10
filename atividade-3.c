#include <stdio.h>

typedef struct {
    float altura;
    float largura;
    float profundidade;
} REGISTRO;

int main () {

    REGISTRO registros[10];
    int opcao, posicao;

    for (int i = 0; i < 10; i++) {
        registros[i].altura = 0;
        registros[i].largura = 0;
        registros[i].profundidade = 0;
    }

    do {
        puts("1 - Inserir registro");
        puts("2 - Alterar registro");
        puts("3 - Excluir registro");
        puts("4 - Mostrar registros");
        puts("5 - Sair");
        scanf("%i", &opcao);

        switch (opcao) {
        case 1:
            puts("Informe uma posicao (0-9)");
            scanf("%i", &posicao);
            puts("Informe a altura");
            scanf("%f", &registros[posicao].altura);
            puts("Informe a largura");
            scanf("%f", &registros[posicao].largura);
            puts("Informe a profundidade");
            scanf("%f", &registros[posicao].profundidade);
            break;

        case 2:
            puts("Informe uma posicao (0-9)");
            scanf("%i", &posicao);
            puts("Informe a altura");
            scanf("%f", &registros[posicao].altura);
            puts("Informe a largura");
            scanf("%f", &registros[posicao].largura);
            puts("Informe a profundidade");
            scanf("%f", &registros[posicao].profundidade);
            break;

        case 3:
            puts("Informe uma posicao (0-9)");
            scanf("%i", &posicao);
            registros[posicao].altura = 0;
            (*(registros+posicao)).largura = 0;
            (registros+posicao)->profundidade = 0;
            break;

        case 4:
            for (int i = 0; i < 10; i++) {
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