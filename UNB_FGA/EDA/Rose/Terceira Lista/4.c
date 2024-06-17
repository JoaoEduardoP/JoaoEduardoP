#include <stdio.h>
#include <stdlib.h>

// Declaração da estrutura necessária
typedef struct fila {
    int *dados; // Vetor para armazenar os elementos da fila
    int N;      // Tamanho atual do vetor
    int p;      // Índice do início da fila
    int u;      // Índice do final da fila (primeira posição livre)
} fila;

// Função solicitada para inserir um elemento na fila circular
int enfileira(fila *f, int x) {
    // Verifica se a fila está cheia
    if ((f->u + 1) % f->N == f->p) {
        // Tenta redimensionar o vetor se a fila estiver cheia
        int novoTamanho = f->N * 2;
        int *novoDados = (int *)malloc(novoTamanho * sizeof(int));
        if (novoDados == NULL) {
            return 0; // Falha na alocação de memória
        }

        // Verifica se o índice p está depois do meio do vetor
        if (f->p > (f->N / 2) + (f->N % 2)) {
            // Copia elementos de p até o final do vetor original para o final do novo vetor
            int i = 0;
            for (int j = f->p; j < f->N; j++) {
                novoDados[novoTamanho - (f->N - j)] = f->dados[j];
            }
            // Copia elementos do início do vetor até u
            for (int j = 0; j < f->u; j++) {
                novoDados[j] = f->dados[j];
            }
            f->p = novoTamanho - (f->N - f->p);
        } else {
            // Copia elementos de p até u diretamente
            int i = 0;
            for (int j = f->p; j < f->u; j++) {
                novoDados[i++] = f->dados[j];
            }
            f->u = f->N;
        }

        free(f->dados);
        f->dados = novoDados;
        f->N = novoTamanho;
    }

    // Insere o elemento na posição u e incrementa u circularmente
    f->dados[f->u] = x;
    f->u = (f->u + 1) % f->N;

    return 1; // Inserção bem-sucedida
}