#include <stdio.h>

#define LINHAS 3
#define COLUNAS 3

void mostrar_tabuleiro(char tabuleiro[LINHAS][COLUNAS]) {
    printf("\n");
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < COLUNAS - 1)
                printf("|");
        }
        printf("\n");
        if (i < LINHAS - 1)
            printf("---+---+---\n");
    }
}

// Função que verifica se há vitória
int verificar_vitoria(char tabuleiro[LINHAS][COLUNAS], char jogador) {
    // verifica linhas
    for (int i = 0; i < LINHAS; i++) {
        if (tabuleiro[i][0] == jogador &&
            tabuleiro[i][1] == jogador &&
            tabuleiro[i][2] == jogador)
            return 1;
    }

    // verifica colunas
    for (int j = 0; j < COLUNAS; j++) {
        if (tabuleiro[0][j] == jogador &&
            tabuleiro[1][j] == jogador &&
            tabuleiro[2][j] == jogador)
            return 1;
    }

    // verifica diagonais
    if (tabuleiro[0][0] == jogador &&
        tabuleiro[1][1] == jogador &&
        tabuleiro[2][2] == jogador)
        return 1;

    if (tabuleiro[0][2] == jogador &&
        tabuleiro[1][1] == jogador &&
        tabuleiro[2][0] == jogador)
        return 1;

    // se nada encontrado, sem vitória
    return 0;
}

int main()
{
    char tabuleiro[LINHAS][COLUNAS] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    int user_linha, user_coluna;
    char jogador_atual = 'X';
    int jogadas = 0;

    while (1) {
        mostrar_tabuleiro(tabuleiro);
        printf("\nVez do jogador %c\n", jogador_atual);
        printf("Escolha a linha e a coluna (1-3): ");

        if (scanf("%d %d", &user_linha, &user_coluna) != 2) {
            printf("Entrada inválida! Use apenas números.\n");
            while (getchar() != '\n'); // limpa o buffer
            continue;
        }

        user_linha--;
        user_coluna--;

        if (user_linha < 0 || user_linha >= LINHAS || user_coluna < 0 || user_coluna >= COLUNAS) {
            printf("Posição fora do tabuleiro!\n");
            continue;
        }

        if (tabuleiro[user_linha][user_coluna] != ' ') {
            printf("Essa posição já está ocupada!\n");
            continue;
        }

        tabuleiro[user_linha][user_coluna] = jogador_atual;
        jogadas++;

        // verifica vitória
        if (verificar_vitoria(tabuleiro, jogador_atual)) {
            mostrar_tabuleiro(tabuleiro);
            printf("\n🏆 Jogador %c venceu!\n", jogador_atual);
            break;
        }

        // verifica empate
        if (jogadas >= 9) {
            mostrar_tabuleiro(tabuleiro);
            printf("\nEmpate! Nenhuma casa restante.\n");
            break;
        }

        // troca de jogador
        jogador_atual = (jogador_atual == 'X') ? 'O' : 'X';
    }

    return 0;
}
