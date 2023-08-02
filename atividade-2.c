#include <stdio.h>

char * instring(char *string, char c);

int main() {
    char s[] = "teste";

    if (instring(s, 't') == NULL) {
        printf("O caractere 't' nao existe na string");
    } else {
        printf("%s", instring(s, 't'));
    }
}

char * instring(char *string, char c) {
    
}