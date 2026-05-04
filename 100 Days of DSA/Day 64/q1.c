#include <stdio.h>
#define MAX 100
int graph[MAX][MAX];
int visited[MAX];
void BFS(int source, int n) {
    int queue[MAX], front = 0, rear = 0;
    visited[source] = 1;
    queue[rear++] = source;

    while (front < rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);

        for (int i = 0; i < n; i++) {
            if (graph[vertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}
int main() {
    int n, m;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);
    
    // Initialize graph and visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1; // Directed graph
    }
    
    int source;
    printf("Enter source vertex: ");
    scanf("%d", &source);
    
    printf("BFS Traversal: ");
    BFS(source, n);
    
    return 0;
}