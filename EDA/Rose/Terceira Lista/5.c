#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *enfileira(celula *f, int x) {
    celula *nova = (celula *)malloc(sizeof(celula));
    if (nova == NULL) {
        return NULL; 
    }

    nova->dado = x;
    nova->prox = NULL;

    if (f == NULL) {
        return nova;
    }

    celula *atual = f;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    atual->prox = nova;

    return f;
}