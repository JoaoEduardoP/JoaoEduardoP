#include <stdio.h>
#include <stdlib.h>

int busca_binaria(int arr[], int n, int x) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] >= x)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return l;
}

int main() {
    int N, M;
    
    scanf("%d %d", &N, &M);
    
    int *arr = (int*)malloc(N * sizeof(int));
    int *queries = (int*)malloc(M * sizeof(int));
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    
    for (int i = 0; i < M; i++) {
        scanf("%d", &queries[i]);
    }
    
    for (int i = 0; i < M; i++) {
        int res = busca_binaria(arr, N, queries[i]);
        printf("%d\n", res);
    }
    
    free(arr);
    free(queries);
    
    return 0;
}
