#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int Tamanho;
    int Espaco;
    int Proximo;
    int Anterior;
} Fila;

int Vazio(Fila* Filas) {
    return (Filas->Tamanho == 0);
}

Fila* Cria_Fila(int Espaco) {
    Fila* Filas = (Fila*)malloc(sizeof(Fila));

    Filas->Espaco = Espaco;
    Filas->Proximo = Filas->Tamanho = 0;
    Filas->Anterior = Espaco - 1;
    Filas->data = (int*)malloc(Filas->Espaco * sizeof(int));

    return Filas;
}

void Insere_Fila(Fila* Filas, int Valor) {
    Filas->Anterior = (Filas->Anterior + 1) % Filas->Espaco;
    Filas->data[Filas->Anterior] = Valor;
    Filas->Tamanho++;
}

int Retira_Fila(Fila* Filas) {
    int Valor = Filas->data[Filas->Proximo];
    Filas->Proximo = (Filas->Proximo + 1) % Filas->Espaco;
    Filas->Tamanho--;

    return Valor;
}

int main() {
    int n;
    scanf("%d", &n);

    Fila* Filas = Cria_Fila(n);

    for (int i = 1; i <= n; i++) {
        Insere_Fila(Filas, i);
    }

    printf("Cartas descartadas: ");

    while (Filas->Tamanho > 1) {

        int Descartado = Retira_Fila(Filas);
        printf("%d", Descartado);
        if (Filas->Tamanho > 1) {
            printf(", ");
        }

        int Retirado = Retira_Fila(Filas);
        Insere_Fila(Filas, Retirado);
    }

    printf("\nCarta restante: %d\n", Filas->data[Filas->Proximo] );

    free(Filas->data);
    free(Filas);

    return 0;
}
