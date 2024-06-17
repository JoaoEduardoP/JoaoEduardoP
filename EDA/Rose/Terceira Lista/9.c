#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N;
    int p;
    int u;
} fila;

int desenfileira(fila *f, int *y) {
    if (f->p == f->u) {
        return 0;
    }
    *y = f->dados[f->p];
    f->p = (f->p + 1) % f->N;
    return 1;
}