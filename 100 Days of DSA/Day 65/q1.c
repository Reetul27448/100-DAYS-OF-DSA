#include <stdio.h>
#define MAX 100
int graph[MAX][MAX];
int visited[MAX];
int parent[MAX];
int DFS(int vertex, int n) {
    visited[vertex] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1) {
            if (!visited[i]) {
                parent[i] = vertex;
                if (DFS(i, n)) {
                    return 1; // Cycle detected
                }
            } else if (parent[vertex] != i) {
                return 1; // Cycle detected
            }
        }
    }

    return 0;
}
int main() {
    int n, m;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);
    
    // Initialize graph, visited and parent arrays
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        parent[i] = -1;
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1; // Undirected graph
        graph[v][u] = 1; // Undirected graph
    }
    
    int cycleExists = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (DFS(i, n)) {
                cycleExists = 1;
                break;
            }
        }
    }
    
    if (cycleExists) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}
