#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int empilha(celula *p, int x) {
    celula *nova = (celula *)malloc(sizeof(celula));
    if (nova == NULL) {
        return 0;
    }
    nova->dado = x;
    nova->prox = p->prox;
    p->prox = nova;
    return 1;
}