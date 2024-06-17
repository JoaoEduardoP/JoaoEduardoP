#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100001

int is_well_defined(char *expression, int length) {
    int stack[MAX_LENGTH], top = -1;

    for (int i = 0; i < length; i++) {
        char c = expression[i];

        if (c == '(' || c == '[' || c == '{') {
            stack[++top] = c;
        } else if (c == ')' || c == ']' || c == '}') {
            if (top == -1) {
                return 0;
            }

            char last = stack[top--];

            if ((c == ')' && last != '(') || (c == ']' && last != '[') || (c == '}' && last != '{')) {
                return 0;
            }
        }
    }

    return top == -1;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        char expression[MAX_LENGTH];
        scanf("%s", expression);

        int length = strlen(expression);
        if (is_well_defined(expression, length)) {
            printf("S\n");
        } else {
            printf("N\n");
        }
    }

    return 0;
}
