#include <stdio.h>
#include <limits.h>

#define V 6  // Number of vertices

int minWeight(int weight[], int state[]) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < V; v++)
        if (state[v] == 0 && weight[v] < min)
            min = weight[v], minIndex = v;
    return minIndex;
}

void printMST(int parent[], int graph[V][V]) {
    printf("Edge\tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d\t%d\n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[V][V]) {
    int parent[V];
    int weight[V];
    int state[V];

    for (int i = 0; i < V; i++)
        weight[i] = INT_MAX, state[i] = 0;

    weight[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minWeight(weight, state);
        state[u] = 1;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && state[v] == 0 && graph[u][v] < weight[v])
                parent[v] = u, weight[v] = graph[u][v];
    }

    printMST(parent, graph);
}

int main() {
    int graph[V][V] = {
        {0, 4, 3, 0, 0, 0},
        {4, 0, 1, 2, 0, 0},
        {3, 1, 0, 4, 5, 0},
        {0, 2, 4, 0, 3, 6},
        {0, 0, 5, 3, 0, 7},
        {0, 0, 0, 6, 7, 0}
    };

    primMST(graph);
    return 0;
}
