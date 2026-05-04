#include <stdio.h>
#define MAX 1000
int graph[MAX][MAX];
int visited[MAX];
void dfs(int vertex, int n) {
    visited[vertex] = 1;
    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            dfs(i, n);
        }
    }
}
int main() {
    int n, m, u, v;

    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        graph[u - 1][v - 1] = 1; // Assuming vertices are 1-indexed
        graph[v - 1][u - 1] = 1; // Since the graph is undirected
    }

    dfs(0, n); // Start DFS from the first vertex

    int isConnected = 1;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            isConnected = 0;
            break;
        }
    }

    if (isConnected) {
        printf("CONNECTED\n");
    } else {
        printf("NOT CONNECTED\n");
    }

    return 0;
}
