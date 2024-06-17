#include <stdio.h>

void EscreveRegua(int n) {
    if (n == 0){
        return;
    }
    
    EscreveRegua(n - 1);
    
    for (int i = 0; i < n; i++){

        if (i==0)
        {
            printf(".");
        }
        
        printf("-");
    }
        
    printf("\n");
    
    EscreveRegua(n - 1);
}

int main() {
    int n;

    scanf("%d", &n);

    EscreveRegua(n);

    return 0;
}