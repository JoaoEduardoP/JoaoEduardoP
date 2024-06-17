#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

typedef struct pilha {
    no *nodo;
    struct pilha *proximo;
} pilha;

void empilhar(pilha **topo, no *nodo) {
    pilha *novo = (pilha *)malloc(sizeof(pilha));
    if (novo == NULL) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    novo->nodo = nodo;
    novo->proximo = *topo;
    *topo = novo;
}

no* desempilhar(pilha **topo) {
    if (*topo == NULL) return NULL;
    pilha *temp = *topo;
    no *nodo = temp->nodo;
    *topo = temp->proximo;
    free(temp);
    return nodo;
}

void pre_ordem(no *raiz) {
    if (raiz == NULL) return;

    pilha *topo = NULL;
    empilhar(&topo, raiz);

    while (topo != NULL) {
        no *atual = desempilhar(&topo);
        printf("%d ", atual->dado);

        if (atual->dir != NULL) empilhar(&topo, atual->dir);
        if (atual->esq != NULL) empilhar(&topo, atual->esq);
    }
}

no* novo_no(int dado) {
    no *n = (no *)malloc(sizeof(no));
    if (n == NULL) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    n->dado = dado;
    n->esq = n->dir = NULL;
    return n;
}