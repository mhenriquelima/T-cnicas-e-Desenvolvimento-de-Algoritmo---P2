#include <stdio.h>

int main(){
    
    int a = 10;
    int *p;
    double d = 20.5;
    double *q;
    char c = 'A';
    char *r;

    p = &a;
    q = &d;
    r = &c;

    printf("Endereco de a: %p, Valor de a: %d\n", p, *p);
    printf("Endereco de d: %p, Valor de d: %.2f\n", q, *q);
    printf("Endereco de b: %p, Valor de b: %c\n\n", r, *r);

    *p = 15;
    *q = 25.5;
    *r = 'B';

    printf("Endereco de a: %p, Valor de a: %d\n", p, *p);
    printf("Endereco de d: %p, Valor de d: %.2f\n", q, *q);
    printf("Endereco de b: %p, Valor de b: %c\n\n", r, *r);

    return 0;

}