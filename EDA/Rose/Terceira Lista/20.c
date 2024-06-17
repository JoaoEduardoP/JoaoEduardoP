#include <stdio.h>

#define MAX_FLOORS 1000001
#define INF 1000000000

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int f, s, g, u, d;
    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);

    int dist[MAX_FLOORS];
    int visited[MAX_FLOORS] = {0};

    for (int i = 1; i <= f; i++) {
        dist[i] = INF;
    }

    dist[s] = 0;
    visited[s] = 1;
    int queue[MAX_FLOORS];
    int front = 0, rear = 0;
    queue[rear++] = s;

    while (front < rear) {
        int current = queue[front++];
        
        int up_floor = current + u;
        if (up_floor <= f && !visited[up_floor]) {
            dist[up_floor] = dist[current] + 1;
            visited[up_floor] = 1;
            queue[rear++] = up_floor;
        }

        int down_floor = current - d;
        if (down_floor >= 1 && !visited[down_floor]) {
            dist[down_floor] = dist[current] + 1;
            visited[down_floor] = 1;
            queue[rear++] = down_floor;
        }
    }

    if (visited[g]) {
        printf("%d\n", dist[g]);
    } else {
        printf("use the stairs\n");
    }

    return 0;
}