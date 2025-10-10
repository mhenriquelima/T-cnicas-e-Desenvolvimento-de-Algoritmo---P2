#include <stdio.h>

typedef struct endereco {
    char rua[100];
    int numero;
    char cidade[50];
    char estado[3];
    char cep[10];
} Endereco;

typedef struct Pessoa {
        char nome[50];
        int idade;
        float altura;
        float peso;
        Endereco endereco;
    } Pessoa;

int main() {

    Pessoa pessoa1;
    pessoa1.idade = 30;
    pessoa1.altura = 1.75;
    pessoa1.peso = 70.5;
    snprintf(pessoa1.nome, sizeof(pessoa1.nome), "João");

    Pessoa pessoa2 = {"Ana", 28, 1.65, 60.0};

    return 0;
}