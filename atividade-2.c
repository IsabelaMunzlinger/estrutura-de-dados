#include <stdio.h>

char * instring(char *string, char c);

int main() {
    char s[] = "teste";

    if (instring(s, 'e') == NULL) {
        printf("O caractere 'e' nao existe na string");
    } else {
        printf("%s", instring(s, 'e'));
    }
}

char * instring(char *string, char c) {
    for (int i = 0; *(string + i) != '\0' ; i++) {
        if (*(string + i) == c) {
            return (string + i);
        }
    }
    return NULL;
}