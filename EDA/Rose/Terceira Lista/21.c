#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

typedef struct {
    int x, y;
} Movimento;

int movimentoValido(int x, int y) {
    return (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE);
}

int minMovimentos(char *inicio, char *destino) {
    int x1 = inicio[0] - 'a';
    int y1 = inicio[1] - '1';
    int x2 = destino[0] - 'a';
    int y2 = destino[1] - '1';

    Movimento movimentos[8] = {
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2},
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1}
    };

    int visitado[BOARD_SIZE][BOARD_SIZE];
    memset(visitado, 0, sizeof(visitado));
    visitado[x1][y1] = 1;

    int distancia[BOARD_SIZE][BOARD_SIZE];
    memset(distancia, 0, sizeof(distancia));

    int filaX[BOARD_SIZE * BOARD_SIZE];
    int filaY[BOARD_SIZE * BOARD_SIZE];
    int inicioFila = 0, fimFila = 0;
    filaX[fimFila] = x1;
    filaY[fimFila++] = y1;

    // BFS
    while (inicioFila < fimFila) {
        int x = filaX[inicioFila];
        int y = filaY[inicioFila++];

        if (x == x2 && y == y2) {
            return distancia[x][y];
        }

        for (int i = 0; i < 8; i++) {
            int novoX = x + movimentos[i].x;
            int novoY = y + movimentos[i].y;
            if (movimentoValido(novoX, novoY) && !visitado[novoX][novoY]) {
                visitado[novoX][novoY] = 1;
                distancia[novoX][novoY] = distancia[x][y] + 1;
                filaX[fimFila] = novoX;
                filaY[fimFila++] = novoY;
            }
        }
    }

    return -1;
}

int main() {
    char inicio[3], destino[3];
    while (scanf("%s %s", inicio, destino) != EOF) {
        int movimentos = minMovimentos(inicio, destino);
        printf("To get from %s to %s takes %d knight moves.\n", inicio, destino, movimentos);
    }
    return 0;
}
