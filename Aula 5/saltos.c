#include <stdio.h>
#define SALTOS 5
#define NOME_TAM 30

int main()
{
	char nome[NOME_TAM];
	int saltos[SALTOS];
	int soma = 0;
	float media;

	printf("nome > ");
	fgets(nome, sizeof(nome), stdin); //LER STRINGS ASSIM

	for (int i = 0; i < SALTOS; i++) {
		printf("informe um numero > ");
		scanf("%d", &saltos[i]);
		soma += saltos[i];
	}

	media = soma / (float) SALTOS;

	printf("\n----------\n");
	printf("nome > %s\n", nome);

	printf("todos os saltos: ");
	for (int i = 0; i < SALTOS; i++) {
		printf("%d ", saltos[i]);
	}

	printf("\nmedia = %.2f\n", media);
	printf("\n----------\n");


	return 0;
}
