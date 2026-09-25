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

Grafo* CriaDigrafo(int v){ 

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
    int n = 0;
    
    scanf("%d %d", &V, &A);

    Grafo *grafo = CriaDigrafo(V);

    for(int i = 0; i < A; i++){
        
        scanf("%d %d", &v, &a);

        InsereAresta(grafo,v,a);
    }

    for (int i = 0; i < V; i++){

        No *p = grafo->lista[i];

        if(p == NULL){
            n++;
        }

    }

    printf("%d", n);

    LiberaMemoria(grafo);
    
    return 0;
}