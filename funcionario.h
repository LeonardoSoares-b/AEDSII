#ifndef FUNCIONARIO_H_INCLUDED
#define FUNCIONARIO_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

typedef struct Funcionario {
    int cod;
    char nome[50];
    char cpf[15];
    char data_nascimento[11];
    double salario;
    int matricula;
    int departamento;
    int horasTrabalhadas;  
} TFunc;


// Retorna tamanho do funcionario em bytes
int tamanho_registro();

// Cria funcionario.
TFunc *funcionario(int cod, char *nome, char *cpf, char *data_nascimento, double salario);


// Salva funcionario no arquivo out, na posicao atual do cursor
void salva(TFunc *func, FILE *out);


// Le um funcionario do arquivo in na posicao atual do cursor
// Retorna um ponteiro para funcionario lido do arquivo
TFunc *le(FILE *in);


// Imprime funcionario
void imprime(TFunc *func);


// Cria base de dados
int criarBase(FILE *arq, int (*n)(int i));

//embaralha base de dados
void shuffle(int *vet,int MAX,int MIN);

// Imprime a base de dados
void imprimirBase(FILE *out);



#endif // FUNCIONARIO_H_INCLUDED
