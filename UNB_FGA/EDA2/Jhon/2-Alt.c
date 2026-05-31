#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned long long codigo;
    int nota;
} Semente;

// comparação para quickselect — menor nota = melhor
static inline int melhorQue(const Semente a, const Semente b) {
    if (a.nota != b.nota) return a.nota < b.nota;
    return a.codigo < b.codigo;
}

static inline void trocar(Semente *a, Semente *b) {
    Semente tmp = *a; *a = *b; *b = tmp;
}

// Quickselect — rearranja para que as k melhores fiquem em [0..k-1]
static void quickselect(Semente *arr, int n, int k) {
    int lo = 0, hi = n - 1;
    while (lo < hi) {
        // pivô mediana de 3 para evitar pior caso
        int mid = lo + (hi - lo) / 2;
        if (melhorQue(arr[mid], arr[lo])) trocar(&arr[mid], &arr[lo]);
        if (melhorQue(arr[hi],  arr[lo])) trocar(&arr[hi],  &arr[lo]);
        if (melhorQue(arr[mid], arr[hi])) trocar(&arr[mid], &arr[hi]);
        Semente pivo = arr[hi];

        int i = lo - 1, j = lo;
        for (; j < hi; j++) {
            if (melhorQue(arr[j], pivo)) {
                i++;
                trocar(&arr[i], &arr[j]);
            }
        }
        trocar(&arr[i+1], &arr[hi]);
        int p = i + 1;

        if (p == k)      break;
        else if (p < k)  lo = p + 1;
        else             hi = p - 1;
    }
}

static int comparaCodigo(const void *a, const void *b) {
    const Semente *s1 = (Semente *) a;
    const Semente *s2 = (Semente *) b;
    return (s1->codigo > s2->codigo) - (s1->codigo < s2->codigo);
}

// I/O rápido com fread
#define BUFSZ (1 << 22)
static char inbuf[BUFSZ];
static int inpos = 0, inlen = 0;

static inline int gc() {
    if (inpos == inlen) {
        inlen = fread(inbuf, 1, BUFSZ, stdin);
        inpos = 0;
        if (inlen == 0) return EOF;
    }
    return (unsigned char)inbuf[inpos++];
}

static inline int lerLongLong(unsigned long long *out) {
    int c;
    unsigned long long x = 0;
    while ((c = gc()) < '0') if (c == EOF) return 0;
    do { x = x * 10 + (c - '0'); } while ((c = gc()) >= '0');
    *out = x;
    return 1;
}

static inline int lerInt(int *out) {
    int c, neg = 0;
    long long x = 0;
    while ((c = gc()) < '0') {
        if (c == '-') neg = 1;
        if (c == EOF) return 0;
    }
    do { x = x * 10 + (c - '0'); } while ((c = gc()) >= '0');
    *out = neg ? (int)-x : (int)x;
    return 1;
}

static char outbuf[1 << 23];
static int outpos = 0;

static inline void flushOut() { fwrite(outbuf, 1, outpos, stdout); }

static inline void writeULL(unsigned long long x) {
    char tmp[20]; int len = 0;
    if (x == 0) { outbuf[outpos++] = '0'; return; }
    while (x > 0) { tmp[len++] = '0' + (x % 10); x /= 10; }
    for (int i = len-1; i >= 0; i--) outbuf[outpos++] = tmp[i];
}

static inline void writeInt(int x) {
    if (x < 0) { outbuf[outpos++] = '-'; x = -x; }
    char tmp[12]; int len = 0;
    if (x == 0) { outbuf[outpos++] = '0'; return; }
    while (x > 0) { tmp[len++] = '0' + (x % 10); x /= 10; }
    for (int i = len-1; i >= 0; i--) outbuf[outpos++] = tmp[i];
}

int main(){
    int k = 0;
    lerInt(&k);

    Semente *sementes = malloc(10000000 * sizeof(Semente));
    int n = 0;

    while (lerLongLong(&sementes[n].codigo) && lerInt(&sementes[n].nota))
        n++;

    // limita k ao total de sementes lidas
    int saida = n < k ? n : k;

    // quickselect — O(n) médio — separa as saida melhores
    if (saida < n)
        quickselect(sementes, n, saida);

    // ordena só as k melhores por código — O(k log k)
    qsort(sementes, saida, sizeof(Semente), comparaCodigo);

    for (int i = 0; i < saida; i++) {
        writeULL(sementes[i].codigo);
        outbuf[outpos++] = ' ';
        writeInt(sementes[i].nota);
        outbuf[outpos++] = '\n';
    }

    flushOut();
    free(sementes);
    return 0;
}