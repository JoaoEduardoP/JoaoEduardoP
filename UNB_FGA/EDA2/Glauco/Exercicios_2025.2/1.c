#include <stdio.h>
#include <stdlib.h>

typedef struct Grafo{
    int v;
    int **matriz;
}Grafo;

Grafo* cria_Grafo(int V){
    
    Grafo *n = malloc(sizeof(Grafo));
    
    n->v = V;
    
    n->matriz = malloc(V * sizeof(int*));
    
    for(int i = 0; i < V; i++){

        n->matriz[i] = malloc(V * sizeof(int));

        for(int j = 0; j < V; j++){
            n->matriz[i][j] = 0;
        }
    }

    return n;
};

void inserir_Aresta(Grafo *g, int v,int a){
    g->matriz[v][a] = 1;
    g->matriz[a][v] = 1;
};

void libera_Grafo(Grafo *g) {
    free(g->matriz);
    free(g->v);
    free(g);
}


int main() {
    int V, A, v1, v2;
    int Q = 0;

    scanf("%d %d", &V, &A);

    Grafo *g = cria_Grafo(V);

    for(int k = 0; k < A; k++){
        
        scanf("%d %d", &v1, &v2);

        inserir_Aresta(g, v1, v2);
    }

    for (int i = 0; i < V; i++){   
        for (int j = 0; j < V; j++){
            if (g->matriz[i][j] == 1) {
                Q++;
            }
        }
        
        printf("%d\n", Q);
        Q = 0;
    }
    
    libera_Grafo(g);
    return 0;
}