#include <stdio.h>
#define QNT_NUMEROS 5

int main()
{
    int numeros[QNT_NUMEROS];
    
    for (int i = 0; i < QNT_NUMEROS; i++) {
        printf("informe um numero > ");
        scanf("%d", &numeros[i]);
    }

    printf("%d ", numeros[0] + numeros[1] + numeros[2] + numeros[3] + numeros[4]);
    printf("\n----------\n");
    printf("%d ", numeros[0] * numeros[1] * numeros[2] * numeros[3] * numeros[4]);
    printf("\n----------\n");
    for (int i = 0; i < QNT_NUMEROS; i++) {
        printf("%d ", numeros[i]);
    }

    
    
    return 0;
}