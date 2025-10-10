#include <stdio.h>
#define QNT_NUMEROS 5

int main()
{
    int numeros[QNT_NUMEROS];
    
    for (int i = 0; i < QNT_NUMEROS; i++) {
        printf("informe um numero > ");
        scanf("%d", &numeros[i]);
    }
    
    for (int i = 0; i < QNT_NUMEROS; i++) {
        printf("%d ", numeros[i]);
    }
    
    printf("\n----------\n");
    
    for (int i = QNT_NUMEROS - 1; i >= 0; i--) {
        printf("%d ", numeros[i]);
    }
    
    return 0;
}