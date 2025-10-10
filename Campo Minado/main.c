#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINHAS 16
#define COLUNAS 16
#define MINAS 40

typedef struct {
    int minas;
    int revelado;
    int marcado;
    int minas_vizinhas;
} Celula;

Celula campo[LINHAS][COLUNAS];

int ta_dentro(int linha, int coluna) {
    return linha >= 0 && linha < LINHAS && coluna >= 0 && coluna < COLUNAS;
}

void inicializar_campo() {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            campo[i][j].minas = 0;
            campo[i][j].revelado = 0;
            campo[i][j].marcado = 0;
            campo[i][j].minas_vizinhas = 0;
        }
    }
    srand(time(NULL));
    int minas_colocadas = 0;
    while (minas_colocadas < MINAS) {
        int linha = rand() % LINHAS;
        int coluna = rand() % COLUNAS;
        if (campo[linha][coluna].minas == 0) {
            campo[linha][coluna].minas = 1;
            minas_colocadas++;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (ta_dentro(linha + i, coluna + j) && !(i == 0 && j == 0)) {
                        campo[linha + i][coluna + j].minas_vizinhas++;
                    }
                }
            }
        }
    }
}

void imprimir_campo(int revelar_tudo) {
    printf("   ");
    for (int j = 0; j < COLUNAS; j++) {
        printf("%2d ", j);
    }
    printf("\n");
    for (int i = 0; i < LINHAS; i++) {
        printf("%2d ", i);
        for (int j = 0; j < COLUNAS; j++) {
            if (revelar_tudo || campo[i][j].revelado) {
                if (campo[i][j].minas) {
                    printf(" * ");
                } else if (campo[i][j].minas_vizinhas > 0) {
                    printf(" %d ", campo[i][j].minas_vizinhas);
                } else {
                    printf(" . ");
                }
            } else if (campo[i][j].marcado) {
                printf(" M ");
            } else {
                printf(" # ");
            }
        }
        printf("\n");
    }
}

void revelar_celula(int linha, int coluna) {
    if (!ta_dentro(linha, coluna) || campo[linha][coluna].revelado || campo[linha][coluna].marcado) {
        return;
    }
    campo[linha][coluna].revelado = 1;
    if (campo[linha][coluna].minas_vizinhas == 0 && !campo[linha][coluna].minas) {
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (!(i == 0 && j == 0)) {
                    revelar_celula(linha + i, coluna + j);
                }
            }
        }
    }
}

void marcar_celula(int linha, int coluna) {
    if (ta_dentro(linha, coluna) && !campo[linha][coluna].revelado) {
        campo[linha][coluna].marcado = !campo[linha][coluna].marcado;
    }
}

int verificar_vitoria() {
    int celulas_reveladas = 0;
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (campo[i][j].revelado) {
                celulas_reveladas++;
            }
        }
    }
    return celulas_reveladas == (LINHAS * COLUNAS - MINAS);
}

int main() {
    inicializar_campo();
    int jogo_ativo = 1;
    while (jogo_ativo) {
        imprimir_campo(0);
        printf("Digite 'r linha coluna' para revelar ou 'm linha coluna' para marcar/desmarcar: ");
        char comando;
        int linha, coluna;
        scanf(" %c %d %d", &comando, &linha, &coluna);
        if (comando == 'r') {
            if (ta_dentro(linha, coluna)) {
                if (campo[linha][coluna].minas) {
                    printf("Você perdeu!\n");
                    imprimir_campo(1);
                    jogo_ativo = 0;
                } else {
                    revelar_celula(linha, coluna);
                    if (verificar_vitoria()) {
                        printf("Você venceu!\n");
                        imprimir_campo(1);
                        jogo_ativo = 0;
                    }
                }
            } else {
                printf("Coordenadas inválidas!\n");
            }
        } else if (comando == 'm') {
            if (ta_dentro(linha, coluna)) {
                marcar_celula(linha, coluna);
            } else {
                printf("Coordenadas inválidas!\n");
            }
        } else {
            printf("Comando inválido!\n");
        }
    }
    return 0;
}