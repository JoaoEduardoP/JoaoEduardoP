#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;

int enfileira(fila *f, int x) {
    
    if (f->u == f->N) {
        int novoTamanho = f->N * 2;
        int *novoDados = (int *)realloc(f->dados, novoTamanho * sizeof(int));
        if (novoDados == NULL) {
            return 0;
        }
        f->dados = novoDados;
        f->N = novoTamanho;
    }

    f->dados[f->u] = x;
    f->u++;

    return 1;
}