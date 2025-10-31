#include <stdio.h>
#include <stdlib.h>

#define V 8

typedef struct { int u, v, w; } Edge;
typedef struct { int parent, rank; } DSU;

int cmpEdge(const void *a, const void *b) {
    return ((Edge*)a)->w - ((Edge*)b)->w;
}

int findSet(DSU d[], int x) {
    if (d[x].parent != x) d[x].parent = findSet(d, d[x].parent);
    return d[x].parent;
}

void unionSet(DSU d[], int a, int b) {
    int ra = findSet(d, a), rb = findSet(d, b);
    if (ra == rb) return;
    if (d[ra].rank < d[rb].rank) d[ra].parent = rb;
    else if (d[ra].rank > d[rb].rank) d[rb].parent = ra;
    else { d[rb].parent = ra; d[ra].rank++; }
}

void kruskal(Edge edges[], int E) {
    qsort(edges, E, sizeof(edges[0]), cmpEdge);

    DSU *d = malloc(V * sizeof(DSU));
    for (int i = 0; i < V; ++i) { d[i].parent = i; d[i].rank = 0; }

    Edge *mst = malloc((V - 1) * sizeof(Edge));
    int taken = 0, idx = 0, total = 0;

    while (taken < V - 1 && idx < E) {
        Edge cur = edges[idx++];
        int ru = findSet(d, cur.u);
        int rv = findSet(d, cur.v);
        if (ru != rv) {
            mst[taken++] = cur;
            total += cur.w;
            unionSet(d, ru, rv);
        }
    }

    printf("Edges in MST:\n");
    for (int i = 0; i < taken; ++i)
        printf("%c - %c  (%d)\n", 'a' + mst[i].u, 'a' + mst[i].v, mst[i].w);
    printf("Total Weight: %d\n", total);

    free(d);
    free(mst);
}

int main(void) {
    Edge edges[] = {
        {4, 6, 1}, {3, 4, 2}, {1, 2, 3},
        {4, 5, 5}, {3, 7, 5}, {0, 1, 5},
        {6, 3, 6}, {5, 6, 7}, {7, 6, 12}
    };

    int E = sizeof(edges) / sizeof(edges[0]);
    kruskal(edges, E);
    return 0;
}
