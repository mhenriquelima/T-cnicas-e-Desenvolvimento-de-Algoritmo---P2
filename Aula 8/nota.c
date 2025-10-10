#include <stdio.h>

typedef struct aluno {
    char nome[50];
    float nota1;
    float nota2;
    int matricula;
} Aluno;

void maior_nota(Aluno alunos[], int tamanho) {
    float maior = 0.0;
    char nome_maior[50];

    for (int i = 0; i < tamanho; i++) {
        float nota1 = alunos[i].nota1;
        if (nota1 > maior) {
            maior = nota1;
            snprintf(nome_maior, sizeof(nome_maior), "%s", alunos[i].nome);
        }
    }

    printf("Aluno com maior nota geral: %s (%.2f)\n", nome_maior, maior);
}

void maior_nota_geral(Aluno alunos[], int tamanho) {
    float maior = 0.0;
    char nome_maior[50];

    for (int i = 0; i < tamanho; i++) {
        float nota_geral = alunos[i].nota1 + alunos[i].nota2;
        if (nota_geral > maior) {
            maior = nota_geral;
            snprintf(nome_maior, sizeof(nome_maior), "%s", alunos[i].nome);
        }
    }

    printf("Aluno com maior nota geral: %s (%.2f)\n", nome_maior, maior);
}

void menor_media_geral(Aluno alunos[], int tamanho) {
    float menor = 10.0;
    char nome_menor[50];
    for (int i = 0; i < tamanho; i++) {
        float media_geral = (alunos[i].nota1 + alunos[i].nota2) / 2.0;
        if (media_geral < menor) {
            menor = media_geral;
            snprintf(nome_menor, sizeof(nome_menor), "%s", alunos[i].nome);
        }
    }
    printf("Aluno com menor media geral: %s (%.2f)\n", nome_menor, menor);
}

void aprovado_reprovado(float media) {
    if (media >= 6.0) {
        printf("Aprovado\n");
    } else {
        printf("Reprovado\n");
    }
}

int main() {
    // n qro fazer input
    Aluno aluno1 = {"Carlos", 8.5, 7.0, 12345};
    Aluno aluno2 = {"Mariana", 9.0, 8.5, 67890};
    Aluno aluno3 = {"Pedro", 6.5, 7.5, 11223};
    Aluno aluno4 = {"Ana", 10.0, 9.5, 44556};
    Aluno aluno5 = {"Lucas", 5.0, 6.0, 77889};

    Aluno alunos[5] = {aluno1, aluno2, aluno3, aluno4, aluno5};
    int tamanho = sizeof(alunos) / sizeof(alunos[0]);   //sizeof(alunos) retorna o tamanho total do array em bytes.
                                                        //sizeof(alunos[0]) retorna o tamanho de um único elemento do array
    maior_nota(alunos, tamanho);
    maior_nota_geral(alunos, tamanho);
    menor_media_geral(alunos, tamanho);
    for (int i = 0; i < tamanho; i++) {
        float media = (alunos[i].nota1 + alunos[i].nota2) / 2.0;
        printf("Aluno: %s - Media: %.2f - ", alunos[i].nome, media);
        aprovado_reprovado(media);
    }

    return 0;
};