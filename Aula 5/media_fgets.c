#include <stdio.h>
#include <string.h>

#define NOME_TAM 50
#define QNT_NOTAS 3

int main() {
	char nome[NOME_TAM];
	float notas[QNT_NOTAS];
	float soma = 0, media;

	printf("Digite o nome do aluno: ");
	fgets(nome, sizeof(nome), stdin);

	nome[strcspn(nome, "\n")] = '\0'; // Remover o \n que o fgets captura

	for (int i = 0; i < QNT_NOTAS; i++) {
		printf("Digite a nota %d: ", i + 1);
		scanf("%f", &notas[i]);
		soma += notas[i];
	}

	media = soma / QNT_NOTAS;

	// SaC-da
	printf("\nAluno: %s\n", nome);
	printf("MC)dia: %.2f\n", media);

	return 0;
}
