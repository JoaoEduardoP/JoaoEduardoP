#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_SIZE 101

typedef struct Node {
    char Alteracao[MAX_STR_SIZE];
    struct Node* next;
} Node;

typedef struct Stack {
    Node* Topo;
} Stack;

char* Estoura(Stack* Stacks) {
    if (Stacks->Topo == NULL) {
        return "";
    }
    Node* Temporario = Stacks->Topo;
    Stacks->Topo = Stacks->Topo->next;
    char* Resultado = (char*)malloc(MAX_STR_SIZE * sizeof(char));

    strcpy(Resultado, Temporario->Alteracao);
    free(Temporario);

    return Resultado;
}

void Empurrar(Stack* Stacks, const char* String) {
    Node* Novo_Node = (Node*)malloc(sizeof(Node));

    strcpy(Novo_Node->Alteracao, String);
    Novo_Node->next = Stacks->Topo;
    Stacks->Topo = Novo_Node;
}

void Inicio_Node(Stack* Stacks) {
    Stacks->Topo = NULL;
}

int main() {
    Stack Stacks;
    Inicio_Node(&Stacks);

    char input[256];

    while (fgets(input, sizeof(input), stdin) != NULL) {
        if (strncmp(input, "inserir ", 8) == 0) {
            char* String = input + 8;
            String[strcspn(String, "\n")] = '\0';
            
            Empurrar(&Stacks, String);

        } else if (strncmp(input, "desfazer", 8) == 0) {
            char* Resultado = Estoura(&Stacks);

            printf("%s\n", Resultado);
            if (strcmp(Resultado, "NULL") != 0) {
                free(Resultado);
            }

        }
    }

    while (Stacks.Topo != NULL) {
        Node* Temporario = Stacks.Topo;
        Stacks.Topo = Stacks.Topo->next;
        free(Temporario);
    }

    return 0;
}