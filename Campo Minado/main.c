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
    for (int linha = 0; linha < LINHAS; linha++) {
        for (int coluna = 0; coluna < COLUNAS; coluna++) {
            campo[linha][coluna].minas = 0;
            campo[linha][coluna].revelado = 0;
            campo[linha][coluna].marcado = 0;
            campo[linha][coluna].minas_vizinhas = 0;
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
            for (int linha_vizinha = -1; linha_vizinha <= 1; linha_vizinha++) {
                for (int coluna_vizinha = -1; coluna_vizinha <= 1; coluna_vizinha++) {
                    if (ta_dentro(linha + linha_vizinha, coluna + coluna_vizinha) && !(linha_vizinha == 0 && coluna_vizinha == 0)) {
                        campo[linha + linha_vizinha][coluna + coluna_vizinha].minas_vizinhas++;
                    }
                }
            }
        }
    }
}

void imprimir_campo(int revelar_tudo) {
    printf("   ");
    for (int coluna = 0; coluna < COLUNAS; coluna++) {
        printf("%2d ", coluna);
    }
    printf("\n");
    for (int linha = 0; linha < LINHAS; linha++) {
        printf("%2d ", linha);
        for (int coluna = 0; coluna < COLUNAS; coluna++) {
            if (revelar_tudo || campo[linha][coluna].revelado) {
                if (campo[linha][coluna].minas) {
                    printf(" B ");
                } else if (campo[linha][coluna].minas_vizinhas > 0) {
                    printf(" %d ", campo[linha][coluna].minas_vizinhas);
                } else {
                    printf(" . ");
                }
            } else if (campo[linha][coluna].marcado) {
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
        for (int linha_vizinha = -1; linha_vizinha <= 1; linha_vizinha++) {
            for (int coluna_vizinha = -1; coluna_vizinha <= 1; coluna_vizinha++) {
                if (!(linha_vizinha == 0 && coluna_vizinha == 0)) {
                    revelar_celula(linha + linha_vizinha, coluna + coluna_vizinha);
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
    for (int linha = 0; linha < LINHAS; linha++) {
        for (int coluna = 0; coluna < COLUNAS; coluna++) {
            if (campo[linha][coluna].revelado) {
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