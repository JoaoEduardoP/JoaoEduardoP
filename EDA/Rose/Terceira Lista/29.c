#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

void em_ordem(no *raiz) {
    no *pilha[100];
    int topo = -1;
    no *atual = raiz;

    while (atual != NULL || topo != -1) {
        while (atual != NULL) {
            pilha[++topo] = atual;
            atual = atual->esq;
        }
        atual = pilha[topo--];
        printf("%d ", atual->dado);
        atual = atual->dir;
    }
}

no *novo_no(int dado) {
    no *n = (no *)malloc(sizeof(no));
    n->dado = dado;
    n->esq = NULL;
    n->dir = NULL;
    return n;
}