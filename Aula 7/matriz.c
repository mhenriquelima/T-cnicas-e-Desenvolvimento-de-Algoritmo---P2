#include <stdio.h>

#define LINHAS 3
#define COLUNAS 3

int main()
{
    int tabela[LINHAS][COLUNAS] = {
        {300, 5, 3}, 
        {4, 10, 337}, 
        {12, 2, 5}
        
    };
    
     for (int linha = 0; linha < LINHAS; linha++) {
        for (int coluna = 0; coluna < COLUNAS; coluna++) {
            printf(" %d ", tabela[linha][coluna]);
        if (coluna < 2) 
            printf(" - "); 
        }
        printf("\n");
    }

    return 0;
}