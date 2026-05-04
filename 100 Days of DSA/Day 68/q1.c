#include <stdio.h>
#define MAX 100
int graph[MAX][MAX];
int inDegree[MAX];
void topologicalSort(int n) {
    int queue[MAX], front = 0, rear = 0;
    
    // Enqueue vertices with in-degree 0
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    while (front < rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);

        for (int i = 0; i < n; i++) {
            if (graph[vertex][i] == 1) {
                inDegree[i]--;
                if (inDegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }
}
int main() {
    int n, m;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);
    
    // Initialize graph and in-degree array
    for (int i = 0; i < n; i++) {
        inDegree[i] = 0;
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1; // Directed graph
        inDegree[v]++;
    }
    
    printf("Topological Sort: ");
    topologicalSort(n);
    
    return 0;
}
