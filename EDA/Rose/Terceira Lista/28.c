#include <stdio.h>

int main() {
    while (1) {
        int n;
        scanf("%d", &n);
        if (n == 0)
            break;

        int order[n];
        int stack[n];
        int top = -1;
        int target = 1;
        int possible = 1;

        for (int i = 0; i < n; i++)
            scanf("%d", &order[i]);

        for (int i = 0; i < n; i++) {
            while (top >= 0 && stack[top] == target) {
                target++;
                top--;
            }

            if (order[i] == target)
                target++;
            else if (top >= 0 && stack[top] < order[i]) {
                possible = 0;
                break;
            } else {
                stack[++top] = order[i];
            }
        }

        if (possible)
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}
