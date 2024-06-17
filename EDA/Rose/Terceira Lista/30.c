#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

void pos_ordem(no *raiz) {
    no *pilha[100];
    int topo = -1;
    no *atual = raiz;
    no *ultimo_visitado = NULL;

    while (atual != NULL || topo != -1) {
        while (atual != NULL) {
            pilha[++topo] = atual;
            atual = atual->esq;
        }

        atual = pilha[topo];
        
        if (atual->dir == NULL || atual->dir == ultimo_visitado) {
            printf("%d ", atual->dado);
            ultimo_visitado = atual;
            topo--;
            atual = NULL;
        } else {
            atual = atual->dir;
        }
    }
}

no *novo_no(int dado) {
    no *n = (no *)malloc(sizeof(no));
    n->dado = dado;
    n->esq = NULL;
    n->dir = NULL;
    return n;
}