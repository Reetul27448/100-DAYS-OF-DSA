#include <stdio.h>
#define MAX 100
int graph[MAX][MAX];
void addEdge(int u, int v) {
    graph[u][v] = 1; // Directed graph
}
void printGraph(int n) {
    for (int i = 0; i < n; i++) {
        printf("Vertex %d: ", i);
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}
int main() {
    int n, m;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);
    
    // Initialize graph
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    
    printf("Adjacency List:\n");
    printGraph(n);
    
    return 0;
}
