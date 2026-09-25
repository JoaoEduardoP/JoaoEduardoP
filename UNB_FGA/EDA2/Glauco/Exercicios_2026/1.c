#include <stdio.h>
#include <stdlib.h>

typedef struct No{

    int vertice;
    struct No *prox;

} No;

typedef struct Grafo{   

    int v;
    No **lista;

} Grafo;

Grafo* CriaGrafo(int v){ 

    Grafo *g = (Grafo*) malloc(sizeof(Grafo));

    g->lista = (No**) malloc( v * sizeof(No*));

    g->v = v;

    for(int i = 0; i < v; i++){
        g->lista[i] = NULL;
    }

    return g;
}

void InsereAresta(Grafo *g, int verGrafo, int vertice){

    No *novo = (No*) malloc(sizeof(No));

    novo->vertice = vertice;

    novo->prox = g->lista[verGrafo];

    g->lista[verGrafo] = novo;
}

void LiberaMemoria(Grafo *g){

    for (int i = 0; i < g->v; i++){

        No *n = g->lista[i];
        
        while ( n != NULL){
            No *prox = n->prox;
            free(n);
            n = prox;
        }

    }

    free(g->lista);
    free(g);
}

int main() {

    int V, A, v, a;
    
    scanf("%d %d", &V, &A);

    Grafo *grafo = CriaGrafo(V);

    for(int i = 0; i < A; i++){
        scanf("%d %d", &v, &a);

        InsereAresta(grafo,v,a);
        InsereAresta(grafo,a,v);
    }

    for (int i = 0; i < V; i++){
        int n = 0;

        No *p = grafo->lista[i];

        while (p != NULL){
            p = p->prox;
            n++;
        }

        printf("%d \n", n);

    }

    LiberaMemoria(grafo);
    
    return 0;
}