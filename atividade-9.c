#include <stdio.h>

int main() {

  int numeros[10], posicao, resultado;
  FILE *fp;
  char path[] = "numeros.bin";

  puts("Informe 10 números");
  for (int i = 0; i < 10; i++) {
    scanf("%i", &numeros[i]);
  }

  fp = fopen(path, "w+b");

  if (fp != NULL) {
    fwrite(numeros, sizeof(int), 10, fp);
  }

  puts("Informe uma posicao de 0 a 9");
  scanf("%i", &posicao);

  fseek(fp, posicao * sizeof(int), SEEK_SET);

  fread(&resultado, sizeof(int), 1, fp);

  fclose(fp);

  printf("A posicao %i possui o valor %i ", posicao, resultado);
}