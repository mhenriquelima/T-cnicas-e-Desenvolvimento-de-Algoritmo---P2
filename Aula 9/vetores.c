#include <stdio.h>

int main () {
    int v[3] = {10, 20, 30};
    int *p;

    p = &v[0]; // ou p = v;

    for(int i = 0; i < 3; i++) {
        printf("Endereco de v[%d]: %p, Valor de v[%d]: %d\n", i, (p + i), i, *(p + i));
    }

    return 0;
}