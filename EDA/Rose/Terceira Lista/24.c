#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 102
#define MAX_COLS 102

typedef struct {
    int row;
    int col;
} Cell;

int abs_diff(int a, int b) {
    return a > b ? a - b : b - a;
}

void mark_visible_area(char terrain[MAX_ROWS][MAX_COLS], int n, int m, int row, int col, int height, int visible[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (abs_diff(row, i) + abs_diff(col, j) <= height) {
                visible[i][j] = 1;
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    char terrain[MAX_ROWS][MAX_COLS];
    int visible[MAX_ROWS][MAX_COLS] = {0};

    for (int i = 0; i < n; i++) {
        scanf("%s", terrain[i]);
    }

    int towers[MAX_ROWS * MAX_COLS] = {0};
    int num_towers = 0;
    while (scanf("%d", &towers[num_towers]) != EOF) {
        num_towers++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (terrain[i][j] == 't') {
                mark_visible_area(terrain, n, m, i, j, towers[num_towers - 1], visible);
                num_towers--;
            }
        }
    }

    int visible_areas = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (terrain[i][j] == '#' && visible[i][j] == 1) {
                terrain[i][j] = '.';
                visible_areas++;
            }
        }
    }

    printf("%d\n", visible_areas);
    for (int i = 0; i < n; i++) {
        printf("%s\n", terrain[i]);
    }

    return 0;
}