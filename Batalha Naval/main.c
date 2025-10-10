#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABULEIRO_TAMANHO 10
#define MAX_NAVIOS 5

typedef enum {
    VAZIO = '~',
    NAVIO = 'N',
    TIRO_CERTO = 'X',
    TIRO_ERRADO = 'O',
} EstadoCelula;

typedef struct {
    int x;
    int y;
    int tamanho;
    int orientacao; // 0 = horizontal, 1 = vertical
    int afundado;
} Navio;

typedef struct {
    char nome[50];
    char tabuleiro[TABULEIRO_TAMANHO][TABULEIRO_TAMANHO];
    Navio navios[MAX_NAVIOS];
    int numNavios;
} Jogador;

// ---------------- Funções auxiliares ----------------
int ta_dentro(int linha, int coluna) {
    return linha >= 0 && linha < TABULEIRO_TAMANHO && coluna >= 0 && coluna < TABULEIRO_TAMANHO;
}

void inicializar_tabuleiro(Jogador *jogador) {
    for (int i = 0; i < TABULEIRO_TAMANHO; i++) {
        for (int j = 0; j < TABULEIRO_TAMANHO; j++) {
            jogador->tabuleiro[i][j] = VAZIO;
        }
    }
}

void exibir_tabuleiro(Jogador *jogador, int revelar) {
    printf("\n  ");
    for (int j = 0; j < TABULEIRO_TAMANHO; j++)
        printf("%d ", j);
    printf("\n");

    for (int i = 0; i < TABULEIRO_TAMANHO; i++) {
        printf("%d ", i);
        for (int j = 0; j < TABULEIRO_TAMANHO; j++) {
            char celula = jogador->tabuleiro[i][j];
            if (!revelar && celula == NAVIO)
                printf("~ ");
            else
                printf("%c ", celula);
        }
        printf("\n");
    }
}

void posicionar_navio_aleatorio(Jogador *jogador, int tamanho) {
    int colocado = 0;
    while (!colocado) {
        int x = rand() % TABULEIRO_TAMANHO;
        int y = rand() % TABULEIRO_TAMANHO;
        int orientacao = rand() % 2;
        int pode = 1;

        for (int i = 0; i < tamanho; i++) {
            int nx = x + (orientacao == 0 ? 0 : i);
            int ny = y + (orientacao == 0 ? i : 0);
            if (!ta_dentro(nx, ny) || jogador->tabuleiro[nx][ny] != VAZIO) {
                pode = 0;
                break;
            }
        }

        if (pode) {
            for (int i = 0; i < tamanho; i++) {
                int nx = x + (orientacao == 0 ? 0 : i);
                int ny = y + (orientacao == 0 ? i : 0);
                jogador->tabuleiro[nx][ny] = NAVIO;
            }
            colocado = 1;
        }
    }
}

void posicionar_navios_jogador(Jogador *jogador) {
    printf("\nColocando navios para %s:\n", jogador->nome);
    for (int i = 0; i < MAX_NAVIOS; i++) {
        int x, y, orientacao;
        int tamanho = 3; // fixo pra simplificar
        printf("Navio %d (tamanho %d):\n", i + 1, tamanho);
        printf("Digite linha e coluna iniciais: ");
        scanf("%d %d", &x, &y);
        printf("Orientacao (0=horizontal, 1=vertical): ");
        scanf("%d", &orientacao);

        int pode = 1;
        for (int j = 0; j < tamanho; j++) {
            int nx = x + (orientacao == 0 ? 0 : j);
            int ny = y + (orientacao == 0 ? j : 0);
            if (!ta_dentro(nx, ny) || jogador->tabuleiro[nx][ny] != VAZIO) {
                pode = 0;
                break;
            }
        }

        if (!pode) {
            printf("Posição inválida! Tentando novamente.\n");
            i--;
            continue;
        }

        for (int j = 0; j < tamanho; j++) {
            int nx = x + (orientacao == 0 ? 0 : j);
            int ny = y + (orientacao == 0 ? j : 0);
            jogador->tabuleiro[nx][ny] = NAVIO;
        }
        exibir_tabuleiro(jogador, 1);
    }
}

int jogar(Jogador *atacante, Jogador *defensor) {
    int x, y;
    printf("\n%s, digite coordenadas para atacar (linha coluna): ", atacante->nome);
    scanf("%d %d", &x, &y);

    if (!ta_dentro(x, y)) {
        printf("Coordenada fora do tabuleiro!\n");
        return 0;
    }

    if (defensor->tabuleiro[x][y] == NAVIO) {
        defensor->tabuleiro[x][y] = TIRO_CERTO;
        printf("🎯 Acertou um navio!\n");
    } else if (defensor->tabuleiro[x][y] == VAZIO) {
        defensor->tabuleiro[x][y] = TIRO_ERRADO;
        printf("💦 Água!\n");
    } else {
        printf("Você já atirou aí!\n");
    }

    return 0;
}

int todos_navios_afundados(Jogador *jogador) {
    for (int i = 0; i < TABULEIRO_TAMANHO; i++)
        for (int j = 0; j < TABULEIRO_TAMANHO; j++)
            if (jogador->tabuleiro[i][j] == NAVIO)
                return 0;
    return 1;
}

// ---------------- Função principal ----------------
int main() {
    srand(time(NULL));

    int modo;
    printf("Escolha o modo de jogo:\n1 - Um jogador (contra o computador)\n2 - Dois jogadores\n> ");
    scanf("%d", &modo);

    Jogador jogador1, jogador2;

    printf("Digite o nome do Jogador 1: ");
    scanf("%s", jogador1.nome);
    inicializar_tabuleiro(&jogador1);

    if (modo == 2) {
        printf("Digite o nome do Jogador 2: ");
        scanf("%s", jogador2.nome);
        inicializar_tabuleiro(&jogador2);

        // Ambos colocam navios manualmente
        posicionar_navios_jogador(&jogador1);
        posicionar_navios_jogador(&jogador2);
    } else {
        // CPU
        sprintf(jogador2.nome, "Computador");
        inicializar_tabuleiro(&jogador2);
        for (int i = 0; i < MAX_NAVIOS; i++)
            posicionar_navio_aleatorio(&jogador2, 3);

        posicionar_navios_jogador(&jogador1);
    }

    // Loop principal do jogo
    while (1) {
        exibir_tabuleiro(&jogador2, 0);
        jogar(&jogador1, &jogador2);
        if (todos_navios_afundados(&jogador2)) {
            printf("\n🏆 %s venceu!\n", jogador1.nome);
            break;
        }

        if (modo == 2) {
            exibir_tabuleiro(&jogador1, 0);
            jogar(&jogador2, &jogador1);
            if (todos_navios_afundados(&jogador1)) {
                printf("\n🏆 %s venceu!\n", jogador2.nome);
                break;
            }
        } else {
            // Turno do computador
            int x = rand() % TABULEIRO_TAMANHO;
            int y = rand() % TABULEIRO_TAMANHO;
            printf("\nComputador ataca (%d, %d)...\n", x, y);
            if (jogador1.tabuleiro[x][y] == NAVIO) {
                jogador1.tabuleiro[x][y] = TIRO_CERTO;
                printf("💥 O computador acertou um navio!\n");
            } else if (jogador1.tabuleiro[x][y] == VAZIO) {
                jogador1.tabuleiro[x][y] = TIRO_ERRADO;
                printf("💦 O computador errou!\n");
            }

            if (todos_navios_afundados(&jogador1)) {
                printf("\n💀 O computador venceu!\n");
                break;
            }
        }
    }

    return 0;
}
