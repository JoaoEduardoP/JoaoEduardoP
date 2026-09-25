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

void LiberaMemoria(Grafo *g, int *vizinhos){

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
    free(vizinhos);
}

int Compara(const void *a, const void *b){
    return(*(int*)a - *(int*)b);
}

void vizVertices(Grafo *g, int x, int *vizinhos){
    int n = 0;
    No *Busca = g->lista[x];

    while ( Busca != NULL){
        vizinhos[n] = Busca->vertice;
        Busca = Busca->prox;
        n++;
    }

    qsort(vizinhos, n, sizeof(int),Compara);
    
    for (int i = 0; i < n; i++){
        printf("%d ", vizinhos[i]);
    }

}

int main() {

    int V, A, v, a, x;
    
    scanf("%d %d", &V, &A);

    Grafo *grafo = CriaGrafo(V+1);

    int *vizinhos = (int*) calloc(V, sizeof(int));

    for(int i = 0; i < A; i++){
        scanf("%d %d", &v, &a);

        InsereAresta(grafo,v,a);
        InsereAresta(grafo,a,v);
    }

    int lidos = scanf("%d", &x);

    if ( lidos == 1 ){
        vizVertices(grafo, x, vizinhos);
    }
    
    LiberaMemoria(grafo, vizinhos);
    
    return 0;
}