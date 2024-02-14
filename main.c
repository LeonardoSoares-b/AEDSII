/* Includes*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // inclua essa biblioteca
#include "funcionario.h" // inclua esse arquivo de cabeçalho
#include "buscaSequencial.c"
#include "buscaBinaria.c"

/* Definition of TBusca struct*/
typedef struct {
    TFunc *resultado;
    clock_t tempoInicio;
    clock_t tempoFim;
    int comparacoes;
} TBusca;

/* Function to write log data to a file*/
void gravarLog(TBusca busca, const char *nomeArquivo) {
    FILE *arq = fopen(nomeArquivo, "a");
    if (arq == NULL) {
        printf("Erro ao abrir arquivo de log\n");
        exit(1);
    }
    fprintf(arq, "Resultado: %d, %f, %d, %d\n", busca.resultado->matricula, busca.resultado->salario, busca.resultado->horasTrabalhadas, busca.resultado->departamento);
    fprintf(arq, "Tempo: %f\n", (double)(busca.tempoFim - busca.tempoInicio) / CLOCKS_PER_SEC);
    fprintf(arq, "Comparacoes: %d\n\n", busca.comparacoes);
    fclose(arq);
}

/* Function to get the size of the file*/
long tamanho_arquivo(FILE *arq) {
    long size;
    fseek(arq, 0, SEEK_END);
    size = ftell(arq);
    rewind(arq);
    return size;
}

/* Main function*/
int main() {
    FILE *arq;
    TFunc *f;
    TBusca busca;
    TFunc *dummy; // dummy variable to store the return value of buscaSequencial and busca_binaria

    if ((arq = fopen("funcionario.dat", "w+b")) == NULL) {
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }

    else {

        criarBase(arq, arq);
        imprimirBase(arq);
        system("pause");
        f = buscaSequencial(10, arq);
        dummy = buscaSequencial(10, arq);
        imprime(f);
        f = busca_binaria(10, arq, 0, tamanho_arquivo(arq)-1);
        dummy = busca_binaria(10, arq, 0, tamanho_arquivo(arq)-1);
        imprime(f);
        free(f);
    }

    if ((arq = fopen("funcionario.dat", "w+b")) == NULL) {
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }
    int n(int i) { return i; }
    if (criarBase(arq, 50) == 0) {
        printf("Erro ao criar base\n");
        fclose(arq);
        exit(1);
    }

    if (imprimirBase(arq) == 0) {
        printf("Erro ao imprimir base\n");
        fclose(arq);
        exit(1);
    }

    busca.tempoInicio = clock();
    f = buscaSequencial(10, arq);
    busca.tempoFim = clock();
    if (f == NULL) {
        printf("Elemento nao encontrado\n");
    } else {
        busca.resultado = f;
        busca.comparacoes = 10; // atualizea variável com o número real de comparações realizadas
        imprime(f);
        free(f);
        gravarLog(busca, "log.txt");
    }

    fclose(arq);

    return 0;
}