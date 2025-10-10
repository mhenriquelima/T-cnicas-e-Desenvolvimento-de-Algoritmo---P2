#include <stdio.h>

int main(){
    for (int n = 1; n <= 10; n++){
        printf("Mostrando tabuada de %d\n", n);
        for (int m = 1; m <= 10; m++){
            printf("%d x %d = %d\n", n, m, n * m);
        }
        printf("\n");
    }
}