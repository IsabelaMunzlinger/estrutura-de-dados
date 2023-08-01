#include <stdio.h>

void printvint(int a[], int n);
int cmpvint(int a1[], int a2[], int n);
int instring(char string[], char c);

int main () {
    int array1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int array2[5] = {1, 2, 3, 4, 5};
    char s[] = "teste";

    // Teste 1.1
    printvint(array1, 5);

    //  Teste 1.2
    if (cmpvint(array1, array2, 3) == 1) {
        printf("Os 3 primeiros elementos sao iguais \n");
    } else {
        printf("Os 3 primeiros elementos sao diferentes \n");
    }

    // Teste 1.3
    if (instring(s, 'e') == 1)
    {
        printf("O caractere 'c' existe na string \n");
    } else {
        printf("O caractere 'c' nao existe na string \n");
    }
    
    return 0;
}

void printvint(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%i ", a[i]);
    }
    printf("\n");
}

int cmpvint(int a1[], int a2[], int n) {
    for (int i = 0; i < n; i++) {
        if (a1[i] != a2[i])  {
            return 0;
        }
    }
    return 1;
}

int instring(char string[], char c) {
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == c) {
            return 1;
        }
    }
    return 0;
}