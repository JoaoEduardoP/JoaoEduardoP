#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 101

typedef struct Node {
    char alteracao[MAX_SIZE];
    struct Node* next;
} Node;

Node* createNode(char* alteracao) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->alteracao, alteracao);
    newNode->next = NULL;
    return newNode;
}

void push(Node** top, char* alteracao) {
    Node* newNode = createNode(alteracao);
    newNode->next = *top;
    *top = newNode;
}

char* pop(Node** top) {
    if (*top == NULL) {
        return "NULL";
    }
    Node* temp = *top;
    *top = (*top)->next;
    char* alteracao = (char*)malloc(sizeof(char) * MAX_SIZE);
    strcpy(alteracao, temp->alteracao);
    free(temp);
    return alteracao;
}

int main() {
    Node* top = NULL;

    char comando[MAX_SIZE];
    while (scanf("%s", comando) != EOF) {
        if (strcmp(comando, "desfazer") == 0) {
            char* alteracao = pop(&top);
            printf("%s\n", alteracao);
            free(alteracao);
        } else {
            char alteracao[MAX_SIZE];
            scanf("%s", alteracao);
            push(&top, alteracao);
        }
    }

    return 0;
}