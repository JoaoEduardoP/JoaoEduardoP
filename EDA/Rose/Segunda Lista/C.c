#include <stdio.h>

long int fibonacci(int n) {

    static long int cache[81] = {0};

    if (n <= 1) return n;

    if (cache[n] != 0) {
        return cache[n];
    }
    
    cache[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return cache[n];
}