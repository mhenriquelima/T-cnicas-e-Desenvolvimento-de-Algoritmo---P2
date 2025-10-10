#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 8

void iniciarTabuleiro(char tabuleiro[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((i + j) % 2 != 0) {
                if (i < 3)
                    tabuleiro[i][j] = 'O';
                else if (i > 4)
                    tabuleiro[i][j] = 'X';
                else
                    tabuleiro[i][j] = ' ';
            } else {
                tabuleiro[i][j] = ' ';
            }
        }
    }
}

void mostrarTabuleiro(char tabuleiro[SIZE][SIZE]) {
    printf("  ");
    for (int i = 0; i < SIZE; i++)
        printf(" %d", i);
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int movimentoValido(char tabuleiro[SIZE][SIZE], int x1, int y1, int x2, int y2, char jogador) {
    if (x2 < 0 || x2 >= SIZE || y2 < 0 || y2 >= SIZE) return 0;
    if (tabuleiro[x2][y2] != ' ') return 0;

    int dx = x2 - x1;
    int dy = y2 - y1;
    char oponente = (jogador == 'X') ? 'O' : 'X';

    // Movimento simples
    if ((dx == -1 && jogador == 'X') || (dx == 1 && jogador == 'O') || (abs(dx) == 1 && (tabuleiro[x1][y1] == 'D' || tabuleiro[x1][y1] == 'U'))) {
        if (abs(dy) == 1)
            return 1;
    }

    // Captura
    if ((dx == -2 && jogador == 'X') || (dx == 2 && jogador == 'O') || (abs(dx) == 2 && (tabuleiro[x1][y1] == 'D' || tabuleiro[x1][y1] == 'U'))) {
        if (abs(dy) == 2) {
            int midX = (x1 + x2) / 2;
            int midY = (y1 + y2) / 2;
            if (tabuleiro[midX][midY] == oponente || tabuleiro[midX][midY] == toupper(oponente))
                return 2; // Captura
        }
    }

    return 0;
}

void moverPeca(char tabuleiro[SIZE][SIZE], int x1, int y1, int x2, int y2, int captura) {
    if (captura) {
        int midX = (x1 + x2) / 2;
        int midY = (y1 + y2) / 2;
        tabuleiro[midX][midY] = ' ';
    }

    tabuleiro[x2][y2] = tabuleiro[x1][y1];
    tabuleiro[x1][y1] = ' ';

    // Promoção
    if (tabuleiro[x2][y2] == 'X' && x2 == 0)
        tabuleiro[x2][y2] = 'D';
    if (tabuleiro[x2][y2] == 'O' && x2 == SIZE - 1)
        tabuleiro[x2][y2] = 'U';
}

int venceu(char tabuleiro[SIZE][SIZE], char jogador) {
    char oponente = (jogador == 'X') ? 'O' : 'X';
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (tabuleiro[i][j] == oponente || tabuleiro[i][j] == toupper(oponente))
                return 0;
    return 1;
}

int main() {
    char tabuleiro[SIZE][SIZE];
    iniciarTabuleiro(tabuleiro);

    char jogador = 'X';
    int x1, y1, x2, y2;

    while (1) {
        mostrarTabuleiro(tabuleiro);
        printf("Jogador %c, informe a linha e coluna da peça e destino (x1 y1 x2 y2): ", jogador);
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        int valido = movimentoValido(tabuleiro, x1, y1, x2, y2, jogador);
        if (valido) {
            moverPeca(tabuleiro, x1, y1, x2, y2, valido == 2);
            if (venceu(tabuleiro, jogador)) {
                mostrarTabuleiro(tabuleiro);
                printf("Jogador %c venceu!\n", jogador);
                break;
            }
            jogador = (jogador == 'X') ? 'O' : 'X';
        } else {
            printf("Movimento inválido!\n");
        }
    }

    return 0;
}
