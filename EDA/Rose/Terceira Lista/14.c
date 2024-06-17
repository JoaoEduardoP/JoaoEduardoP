#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void empilha(celula *p, int x) {
    celula *nova = (celula *)malloc(sizeof(celula));
    nova->dado = x;
    nova->prox = p->prox;
    p->prox = nova;
}

int desempilha(celula *p, int *y) {
    if (p->prox == NULL) {
        return 0;
    }
    celula *temp = p->prox;
    *y = temp->dado;
    p->prox = temp->prox;
    free(temp);
    return 1;
}