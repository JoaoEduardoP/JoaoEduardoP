#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100000

typedef struct {
    int  Quantidade;
    char Caractere;
    int  Posicao;
} Sequencia;

int Ordenacao(const void *a, const void *b) {
    const Sequencia *Sequencia_A = (const Sequencia *)a;
    const Sequencia *Sequencia_B = (const Sequencia *)b;

    if (Sequencia_A->Quantidade != Sequencia_B->Quantidade) {

        return Sequencia_B->Quantidade - Sequencia_A->Quantidade;

    }
    
    return Sequencia_A->Posicao-Sequencia_B->Posicao;
}

int main() {
    char Texto[MAX_SIZE + 1];
    
    if (fgets(Texto, sizeof(Texto), stdin) == NULL) {
        return 1;
    }

    int Tamanho_Texto = strlen(Texto);
    if (Texto[Tamanho_Texto-1] == '\n') {
        Texto[Tamanho_Texto-1] = '\0';
    }

    Tamanho_Texto = strlen(Texto);
    Sequencia Sequencias[MAX_SIZE];
    int  Sequencias_Tamanho = 0;
    int  Posicao_Inicial = 0;
    char Char_Uso = Texto[0];
    int  Tamanho_Uso = 1;

    for (int i = 1; i <= Tamanho_Texto; i++) {

        if (Texto[i] == Char_Uso) {
            Tamanho_Uso++;
        } else {

            Sequencias[Sequencias_Tamanho].Quantidade = Tamanho_Uso;
            Sequencias[Sequencias_Tamanho].Posicao = Posicao_Inicial;
            Sequencias[Sequencias_Tamanho].Caractere = Char_Uso;
            
            Sequencias_Tamanho++;
            Char_Uso = Texto[i];
            Posicao_Inicial = i;
            Tamanho_Uso = 1;

        }
    }

    qsort(Sequencias, Sequencias_Tamanho, sizeof(Sequencia), Ordenacao);

    for (int i = 0; i < Sequencias_Tamanho; i++) {
        printf("%d %c %d\n", Sequencias[i].Quantidade, Sequencias[i].Caractere, Sequencias[i].Posicao);
    }

    return 0;
}