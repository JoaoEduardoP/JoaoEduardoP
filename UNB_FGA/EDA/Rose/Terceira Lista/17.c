#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de carta
typedef struct {
    int *cartas; // Array para armazenar as cartas
    int tamanho; // Tamanho do array
} PilhaCartas;

// Função para inicializar a pilha de cartas
PilhaCartas inicializar_pilha(int n) {
    PilhaCartas pilha;
    pilha.cartas = malloc(n * sizeof(int));
    pilha.tamanho = 0;

    // Inicializa a pilha com os números de 1 até n
    for (int i = 0; i < n; i++) {
        pilha.cartas[i] = i + 1;
        pilha.tamanho++;
    }
    return pilha;
}

// Função para descartar uma carta da pilha
void descartar_carta(PilhaCartas *pilha) {
    pilha->tamanho--;
    
    // Descarta a carta do topo
    for (int i = 0; i < pilha->tamanho; i++) {
        if (pilha->cartas[i+1] != 0)
        {
            pilha->cartas[i] = pilha->cartas[i + 1];
        }
    }

    // Move a carta do topo para o final da pilha
    pilha->cartas[pilha->tamanho] = pilha->cartas[0];
    
    // Descarta a carta do topo novamente para corrigir o array
    for (int i = 0; i < pilha->tamanho; i++) {
        if (pilha->cartas[i+1] != 0)
        {
            pilha->cartas[i] = pilha->cartas[i + 1];
        }
    }
}

// Função para executar o jogo de cartas
void jogar_cartas(int n) {
    PilhaCartas Pilha = inicializar_pilha(n);
    printf("Cartas descartadas: ");
    while (Pilha.tamanho > 1) {
        printf("%d", Pilha.cartas[0]);
        if (Pilha.tamanho > 2) {
            printf(", ");
        }
        descartar_carta(&Pilha);
    }

    // Imprime a carta restante
    printf("\nCarta restante: %d\n", Pilha.cartas[0]);
    free(Pilha.cartas);
}

int main() {
    int n;
    scanf("%d", &n);
    jogar_cartas(n);
    return 0;
}