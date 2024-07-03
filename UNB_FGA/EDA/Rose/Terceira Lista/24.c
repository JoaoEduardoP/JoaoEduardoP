#include <stdio.h>
#include <stdlib.h>

#define MAX_N 102
#define MAX_M 102

char terrain[MAX_N][MAX_M];
int heights[MAX_N * MAX_M];
int N, M, T;

void markVisibleAreas(int x, int y, int height) {
    for (int i = -height; i <= height; i++) {
        for (int j = -height; j <= height; j++) {
            int nx = x + i;
            int ny = y + j;
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && terrain[nx][ny] == '#') {
                terrain[nx][ny] = '.';
            }
        }
    }
}

int countVisibleAreas() {
    int visible = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (terrain[i][j] == '.') {
                visible++;
            }
        }
    }
    return visible;
}

void printOutput(int visible) {
    printf("%d\n", visible);
    for (int i = 0; i < N; i++) {
        printf("%s\n", terrain[i]);
    }
}

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%s", terrain[i]);
    }

    T = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (terrain[i][j] == 't') {
                T++;
            }
        }
    }

    for (int i = 0; i < T; i++) {
        scanf("%d", &heights[i]);
    }

    int index = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (terrain[i][j] == 't') {
                markVisibleAreas(i, j, heights[index]);
                index++;
            }
        }
    }

    int visible = countVisibleAreas();
    printOutput(visible);

    return 0;
}
