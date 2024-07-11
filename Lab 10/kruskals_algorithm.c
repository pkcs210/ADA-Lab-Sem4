#include <stdio.h>

#define INF 9999
#define MAX 100

void kruskals(int c[MAX][MAX], int n) {
    int parent[MAX];
    int ne = 0;
    int mincost = 0;

    for (int i = 1; i <= n; i++) {
        parent[i] = 0;
    }

    while (ne != n - 1) {
        int min = INF;
        int u = 0, v = 0, a = 0, b = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (c[i][j] < min) {
                    min = c[i][j];
                    u = i;
                    a = i;
                    v = j;
                    b = j;
                }
            }
        }

        while (parent[u] != 0) {
            u = parent[u];
        }

        while (parent[v] != 0) {
            v = parent[v];
        }

        if (u != v) {
            printf("Edge %d-%d with cost %d\n", a, b, min);
            parent[v] = u;
            ne++;
            mincost += min;
        }

        c[a][b] = INF;
        c[b][a] = INF;
    }

    printf("Minimum cost of spanning tree: %d\n", mincost);
}

int main() {
    int n;
    int cost[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = INF;
            }
        }
    }

    kruskals(cost, n);

    return 0;
}

