#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *v; // Vetor que contem os elementos da pilha
    int N; // Tamanho de v
    int topo; // Indicador do topo
} pilha;

void empilha(pilha *p, int x) {
    if (p->topo == p->N) { // Pilha cheia, redimensiona
        p->N *= 2;
    }
    p->v[p->topo++] = x;
}

int desempilha(pilha *p, int *y) {
    if (p == NULL || p->topo == 0 || p->v == NULL) { // Pilha vazia
        return 0;
    } else {
        *y = p->v[--(p->topo)];
        return 1;
    }
}
