#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coluna;
    int valor;
    struct Node* prox;
} Node;

Node* novoNo(int coluna, int valor) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->coluna = coluna;
    novo->valor = valor;
    novo->prox = NULL;
    return novo;
}

void liberarLista(Node* lista) {
    Node* atual = lista;
    Node* proximo;
    while (atual != NULL) {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    Node** linhas = (Node**)malloc(m * sizeof(Node*));
    for (int i = 0; i < m; i++) {
        linhas[i] = NULL;
    }

    int linha, coluna, valor;
    while (1) {
        scanf("%d %d %d", &linha, &coluna, &valor);
        if (linha == -1 && coluna == -1 && valor == -1) {
            break;
        }
        Node* novo = novoNo(coluna, valor);
        novo->prox = linhas[linha];
        linhas[linha] = novo;
    }

    int* vetor = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    int* resultado = (int*)calloc(m, sizeof(int));
    for (int i = 0; i < m; i++) {
        Node* atual = linhas[i];
        while (atual != NULL) {
            resultado[i] += atual->valor * vetor[atual->coluna];
            atual = atual->prox;
        }
    }

    for (int i = 0; i < m; i++) {
        printf("%d\n", resultado[i]);
    }

    for (int i = 0; i < m; i++) {
        liberarLista(linhas[i]);
    }
    free(linhas);
    free(vetor);
    free(resultado);

    return 0;
}