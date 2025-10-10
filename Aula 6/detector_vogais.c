#include <stdio.h>

int main()
{
    char nome[11];
    int count = 10;
    
    printf("Escreva um nome com até 10 caracteres > ");
    fgets(nome, sizeof(nome), stdin);
    
    for (int i = 0; nome[i] != '\0'; i++) {
        if (nome[i] == '\n') {
            nome[i] = '\0';
            break;
        }
    }
    
    for (int i = 0; nome[i] != '\0'; i++) {
        switch (nome[i]) {
            case 'a':
                printf("a,");
                count++;
                break;
            case 'e':
                printf("e,");
                count++;
                break;
            case 'i':
                printf("i,");
                count++;
                break;
            case 'o':
                printf("o,");
                count++;
                break;
            case 'u':
                printf("u,");
                count++;
                break;
        }
    }
    
    printf("\nTotal de vogais: %d\n", count);
    
    return 0;
}
