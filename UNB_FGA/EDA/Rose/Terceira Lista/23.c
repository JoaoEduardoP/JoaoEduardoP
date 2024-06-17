#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100001

typedef struct Node {
    char c;
    struct Node* next;
} Node;

Node* createNode(char c) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->c = c;
    newNode->next = NULL;
    return newNode;
}

void push(Node** top, char c) {
    Node* newNode = createNode(c);
    newNode->next = *top;
    *top = newNode;
}

char pop(Node** top) {
    if (*top == NULL) {
        return '\0';
    }
    Node* temp = *top;
    *top = (*top)->next;
    char c = temp->c;
    free(temp);
    return c;
}

char validarTexto(char** texto, int n) {
    Node* pilha = NULL;

    for (int i = 0; i < n; i++) {
        int tamanho = strlen(texto[i]);

        for (int j = 0; j < tamanho; j++) {
            if (texto[i][j] == '*' || texto[i][j] == '/' || texto[i][j] == '_') {
                push(&pilha, texto[i][j]);
            } else if (texto[i][j] == '*' || texto[i][j] == '/' || texto[i][j] == '_') {
                char topo = pop(&pilha);
                if (texto[i][j] != topo) {
                    return 'E'; 
                }
            }
        }
    }

    if (pilha != NULL) {
        return 'E';
    }

    return 'C';
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();

    char **texto = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        texto[i] = (char*)malloc(MAX_SIZE * sizeof(char));
        fgets(texto[i], MAX_SIZE, stdin);
        texto[i][strcspn(texto[i], "\n")] = '\0';
    }

    char resultado = validarTexto(texto, n);
    printf("%c\n", resultado);

    for (int i = 0; i < n; i++) {
        free(texto[i]);
    }
    free(texto);

    return 0;
}
