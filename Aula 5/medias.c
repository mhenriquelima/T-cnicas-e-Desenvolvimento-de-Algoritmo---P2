#include <stdio.h>
#define QNT_MEDIAS 7

int main()
{
    float medias[QNT_MEDIAS];
    
    for (int i = 0; i < QNT_MEDIAS; i++) {
        printf("informe uma media > ");
        scanf("%f", &medias[i]);
    }
    
    for (int i = 0; i < QNT_MEDIAS; i++) {
        printf("%.2f ", medias[i]);
    }
    
    return 0;
}