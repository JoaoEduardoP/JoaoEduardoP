#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void enfileira(celula **f, int x) {
    celula *Celulas = (celula *)malloc(sizeof(celula));

    Celulas->dado = x;
    Celulas->prox = NULL;

    if (*f == NULL) {
        *f = (celula *)malloc(sizeof(celula));
        (*f)->prox = *f;
    }

    celula *Auxiliar = *f;

    while (Auxiliar->prox != *f) {
        Auxiliar = Auxiliar->prox;
    }
    
    Auxiliar->prox = Celulas;
    Celulas->prox = *f;
}

int desenfileira(celula *f, int *y) {
    if (f->prox == f || f == NULL) {
        return 0;
    }

    celula *Primeiro = f->prox;
    *y = Primeiro->dado;

    if (Primeiro == f) {
        f->prox = f;
    } 
    else {
        f->prox = Primeiro->prox;
    }
    free(Primeiro);
    return 1;
}

