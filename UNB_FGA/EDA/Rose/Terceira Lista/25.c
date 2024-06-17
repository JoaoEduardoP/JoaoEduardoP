#include <stdio.h>

int main() {
    int count[61][2] = {0};
    int size, pairs = 0;
    char foot;

    while (scanf("%d %c", &size, &foot) != EOF) {
        if (foot == 'D') {
            count[size][0]++;
        } else if (foot == 'E') {
            count[size][1]++;
        }
    }

    for (int i = 30; i <= 60; i++) {
        pairs += count[i][0] < count[i][1] ? count[i][0] : count[i][1];
    }

    printf("%d\n", pairs);

    return 0;
}