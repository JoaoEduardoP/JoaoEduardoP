#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long long ll;
typedef ll T;

T e = 0;
ll N;
ll* seg;

ll op(ll a, ll b) { return a + b; }

void assign(ll i, T v) {
    i += N;
    seg[i] = v;
    for (i >>= 1; i; i >>= 1) seg[i] = op(seg[2 * i], seg[2 * i + 1]);
}

T query(ll l, ll r) {
    T la = e, ra = e;
    l += N;
    r += N;

    while (l <= r) {
        if (l & 1) la = op(la, seg[l++]);
        if (~r & 1) ra = op(seg[r--], ra);
        l >>= 1;
        r >>= 1;
    }

    return op(la, ra);
}

int main() {
    ll M;
    scanf("%lld %lld", &N, &M);

    seg = calloc(N + N, sizeof(ll));

    ll el;
    for (ll i = 0; i < N; i++) {
        scanf("%lld", &el);
        assign(i, el);
    }

    ll tipo, A, B, X, K;
    for (ll i = 0; i < M; i++) {
        scanf("%lld", &tipo);
        if (tipo == 1) {
            scanf("%lld %lld", &K, &X);
            assign(K - 1, X);
        } else {
            scanf("%lld %lld", &A, &B);
            printf("%lld\n", query(A - 1, B - 1));
        }
    }

    free(seg);
    return 0;
}