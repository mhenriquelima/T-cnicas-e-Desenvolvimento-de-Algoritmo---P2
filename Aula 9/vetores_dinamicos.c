#include <stdio.h>
#include <stdlib.h>

int main() {
    int *vetor = (int *) calloc(10, sizeof(int));

    int *pTemp = realloc(vetor, 20 * sizeof(int));
    vetor = pTemp;
    
    vetor[0] = 42;
    vetor[1] = 13;
    vetor[2] = 7;
    vetor[3] = 99;

    printf("Elementos do vetor:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\n", vetor[i]);
    }

    free(vetor);
    return 0;
}

//  int main() {
//      int tam, i;

//      printf("digite o tamanho do seu vetor:\n");
//      scanf("%d", &tam);

//      int *vet;
//      vet = (int *) malloc( sizeof(int)*tam );

//      for (i=0 ; i<tam ; i++) {
//          printf("digite o numero %d\n", i+1);
//          scanf("%d", &vet[i]);
//      }

//      printf("Os %d numeros digitados foram:\n", tam);
//      for (i=0 ; i<tam ; i++) {
//          printf("numero %d\n", vet[i]);
//      }
//      free(vet);

//      return 0;
//  }