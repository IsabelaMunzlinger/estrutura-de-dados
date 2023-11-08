#include <stdio.h>

int fibonacci(int n) {

  if (n <= 1)
    return n;
  else
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {

  int n;

  printf("Digite um número inteiro positivo: ");
  scanf("%i", &n);
    
  for (int i = 1; i <= n; i++) {
    printf("%i \n", fibonacci(i));
  }

  return 0;
}