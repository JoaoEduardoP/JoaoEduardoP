#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int   Topo;
    char *Dados;
    int   Tamanho;
    int   Espaco;
} Node;

void Inicia_Pilha(Node *p) {
    p->Topo = 0;
    p->Tamanho = 1;
    p->Dados = malloc(p->Tamanho * sizeof(char));
    p->Espaco = p->Tamanho;
}

void Empilha(Node *p, char x) {
    if (p->Topo == p->Espaco) {
        p->Espaco *= 2;
        p->Dados = realloc(p->Dados, p->Espaco * sizeof(char));
    }
    p->Dados[p->Topo++] = x;
}

int Vazia(Node *p) {
    return p->Topo == 0;
}

void Desempilha(Node *p) {
    if (p->Topo > 0) {
        p->Topo--;
    }
}

void Formada(Node *p, char *Caracteres) {
    for (int i = 0; Caracteres[i] != '\0'; i++) {
        if (Caracteres[i] == '*') {
            if (p->Topo == 0 || p->Dados[p->Topo - 1] != '*' || (p->Topo > 0 && p->Dados[p->Topo - 1] == '/')) {
                Empilha(p, '*');
            } else {
                Desempilha(p);
            }
        } else if (Caracteres[i] == '/') {
            if (p->Topo == 0 || p->Dados[p->Topo - 1] != '/' || (p->Topo > 0 && p->Dados[p->Topo - 1] == '*')) {
                Empilha(p, '/');
            } else {
                Desempilha(p);
            }
        } else if (Caracteres[i] == '_') {
            if (p->Topo == 0 || p->Dados[p->Topo - 1] != '_') {
                Empilha(p, '_');
            } else {
                Desempilha(p);
            }
        }
    }
}

int main() {
    Node Pilha;
    Inicia_Pilha(&Pilha);

    int N;
    scanf("%d\n", &N);

    char Palavras[100001];
    for (int i = 0; i < N; i++) {
        Palavras[strcspn(Palavras, "\n")] = '\0';
        Formada(&Pilha, Palavras);
    }

    if (Vazia(&Pilha)) {
        printf("C\n");
    } else {
        printf("E\n");
    }

    free(Pilha.Dados);

    return 0;
}
