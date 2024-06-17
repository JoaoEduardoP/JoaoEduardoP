#include <stdio.h>

#define MAX_PISTAS 5001

typedef struct {
    int valor;
    int proxima;
} Pista;

int main() {
    int n = 0;
    int j = 0;
    int primeiro = 0;
    scanf("%d", &n);

    Pista pistas[MAX_PISTAS];

    int identificador, valor, proxima;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &identificador, &valor, &proxima);
        if(primeiro == 0) {
            primeiro = identificador;
        }
        pistas[identificador].valor = valor;
        pistas[identificador].proxima = proxima;
    }

    // A primeira pista é a primeira na entrada
    int atual = primeiro;

    // Listar os valores em ordem
    while (atual != -1) {
        if (j == 0) {
            printf("%d\n", pistas[atual].valor);
            atual = pistas[atual].proxima;

        } else{
            printf("%d\n", pistas[atual].valor);
            atual = pistas[atual].proxima;
        }
        j++;
    }

    return 0;
}