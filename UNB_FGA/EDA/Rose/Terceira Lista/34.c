#include <stdio.h>
#include <stdlib.h>

typedef long long Variavel_L;
typedef Variavel_L Variavel_T;

Variavel_T f = 0;
Variavel_L Total;
Variavel_L *Segundo;

Variavel_L O(Variavel_L a, Variavel_L b){
    return a + b; 
}

Variavel_T Pilha(Variavel_L l, Variavel_L r) {
    Variavel_T la = f, ra = f;
    l += Total;
    r += Total;

    while (l <= r) {
        if (l & 1) la = O(la, Segundo[l++]);
        if (~r & 1) ra = O(Segundo[r--], ra);
        l >>= 1;
        r >>= 1;
    }

    return O(la, ra);
}

void Designar(Variavel_L i, Variavel_T v) {
    i += Total;
    Segundo[i] = v;
    for (i >>= 1; i; i >>= 1) Segundo[i] = O(Segundo[2 * i], Segundo[2 * i + 1]);
}

int main() {
    Variavel_L q;

    scanf("%lld %lld", &Total, &q);

    Segundo = calloc(Total + Total, sizeof(Variavel_L));

    Variavel_L arr[Total];
    for (Variavel_L i = 0; i < Total; i++) {
        scanf(" %lld", &arr[i]);

        Designar(i, arr[i]);
    }


    for (Variavel_L i = 0; i < q; i++) {
        Variavel_L type;
        scanf("%lld", &type);
        if (type == 1) {
            Variavel_L k, x;
            scanf("%lld %lld", &k, &x);

            Designar(k-1, x);
        } else if (type == 2) {
            Variavel_L a, b;
            scanf("%lld %lld", &a, &b);

            Variavel_L result = Pilha(a-1, b-1);
            printf("%lld\n", result);
        }
    }

    free(Segundo);

    return 0;
}