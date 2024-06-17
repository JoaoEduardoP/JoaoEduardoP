#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);

    char palavra[N + 1];
    scanf("%s", palavra);

    int i, j;
    int palindromo = 1;

    for (i = 0, j = N - 1; i < j; i++, j--) {
        if (palavra[i] != palavra[j]) {
            palindromo = 0;
            break;
        }
    }

    printf("%d\n", palindromo);

    return 0;
}
