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
}
void dijkstra(Graph graph[], int n, int source) {
    int dist[MAX];
    int visited[MAX] = {0};
    for (int i = 0; i < n; i++) {
        dist[i] = (i == source) ? 0 : MAX;
    }
    for (int i = 0; i < n - 1; i++) {
        int minDist = MAX, minIndex;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                minIndex = j;
            }
        }
        visited[minIndex] = 1;
        for (int k = 0; k < graph[minIndex].count; k++) {
            Edge edge = graph[minIndex].edges[k];
            if (!visited[edge.vertex] && dist[minIndex] != MAX && dist[minIndex] + edge.weight < dist[edge.vertex]) {
                dist[edge.vertex] = dist[minIndex] + edge.weight;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", (dist[i] == MAX) ? -1 : dist[i]);
    }
    printf("\n");
}
int main() {
    int n, m, u, v, w, source;
    Graph graph[MAX] = {0};

    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(graph, u - 1, v - 1, w); // Assuming vertices are 1-indexed
    }
    scanf("%d", &source);
    dijkstra(graph, n, source - 1); // Convert to 0-indexed

    return 0;
}
