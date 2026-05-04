#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
typedef struct {
    int vertex;
    int weight;
} Edge;
typedef struct {
    Edge edges[MAX];
    int count;
} Graph;
void addEdge(Graph *graph, int u, int v, int w) {
    graph[u].edges[graph[u].count].vertex = v;
    graph[u].edges[graph[u].count].weight = w;
    graph[u].count++;
    graph[v].edges[graph[v].count].vertex = u; // Since the graph is undirected
    graph[v].edges[graph[v].count].weight = w;
    graph[v].count++;
}
void prim(Graph graph[], int n) {
    int parent[MAX];
    int key[MAX];
    int mstSet[MAX] = {0};
    for (int i = 0; i < n; i++) {
        key[i] = MAX;
        parent[i] = -1;
    }
    key[0] = 0; // Start from the first vertex
    for (int count = 0; count < n - 1; count++) {
        int minKey = MAX, minIndex;
        for (int v = 0; v < n; v++) {
            if (!mstSet[v] && key[v] < minKey) {
                minKey = key[v];
                minIndex = v;
            }
        }
        mstSet[minIndex] = 1;
        for (int k = 0; k < graph[minIndex].count; k++) {
            Edge edge = graph[minIndex].edges[k];
            if (!mstSet[edge.vertex] && edge.weight < key[edge.vertex]) {
                parent[edge.vertex] = minIndex;
                key[edge.vertex] = edge.weight;
            }
        }
    }
    int totalWeight = 0;
    for (int i = 1; i < n; i++) {
        totalWeight += key[i];
    }
    printf("%d\n", totalWeight);
}
int main() {
    int n, m, u, v, w;
    Graph graph[MAX] = {0};

    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(graph, u - 1, v - 1, w); // Assuming vertices are 1-indexed
    }
    prim(graph, n);

    return 0;
}
