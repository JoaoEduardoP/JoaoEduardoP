#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void enfileira(celula **f, int x) {
    celula *nova = (celula *)malloc(sizeof(celula));
    if (nova == NULL) {
        return;
    }
    nova->dado = x;

    if (*f == NULL) {
        nova->prox = nova;
        *f = nova;
    } else {
        nova->prox = (*f)->prox;
        (*f)->prox = nova;
        *f = nova; 
    }
}

int desenfileira(celula *f, int *y) {
    if (f == NULL) {
        return 0;
    }

    celula *remover = f->prox;
    *y = remover->dado;

    if (remover == f) {
        free(remover);
        f = NULL;
    } else {
        f->prox = remover->prox;
        free(remover);
    }
    
    return 1;
}