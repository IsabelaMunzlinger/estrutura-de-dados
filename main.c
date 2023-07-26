#include <stdio.h>

void printvint(int a[], int n) {
    for (int i = 0; i < n; i++)
    {
        printf("%i ", a[i]);
    }
}

int main () {
    int x[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printvint(x, 5);
    // resultado deve ser: 12345
    return 0;
}