#include <stdio.h>
#include <stdlib.h>

#define V 6  // Number of vertices
#define E 9  // Number of edges

// Edge structure
typedef struct {
    int src, dest, weight;
} Edge;

// Graph structure using adjacency list for Kruskal (list of edges)
Edge edges[E] = {
    {1, 2, 3}, {0, 1, 7}, {0, 2, 8}, {1, 3, 6}, {2, 3, 4},
    {2, 4, 3}, {3, 4, 2}, {3, 5, 5}, {4, 5, 2}
};

int parent[V];

// Find function for Union-Find
int find(int i) {
    while(parent[i] != i) i = parent[i];
    return i;
}

// Union function for Union-Find
void union_set(int u, int v) {
    int set_u = find(u);
    int set_v = find(v);
    parent[set_v] = set_u;
}

// Comparator for qsort to sort edges by weight ascending
int cmp(const void *a, const void *b) {
    Edge *e1 = (Edge *)a;
    Edge *e2 = (Edge *)b;
    return e1->weight - e2->weight;
}

int main() {
    // Initialize parent array for union-find
    for(int i = 0; i < V; i++) parent[i] = i;

    // Sort edges by ascending weight
    qsort(edges, E, sizeof(Edge), cmp);

    printf("Weights are in ascending order:\n");
    for(int i=0; i<E; i++)
        printf("%d ", edges[i].weight);
    printf("\n");

    int mst_edges = 0, cost = 0;
    printf("Edges in MST (starting from B):\n");
    for(int i=0; i<E && mst_edges < V-1; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int set_u = find(u);
        int set_v = find(v);

        if(set_u != set_v) {  // If no cycle
            printf("%c-%c: %d\n", u + 'A', v + 'A', edges[i].weight);
            cost += edges[i].weight;
            union_set(set_u, set_v);
            mst_edges++;
        }
    }
    printf("Total cost of MST: %d\n", cost);

    return 0;
}

/* 
Modifications:
- Sorted edges ascending using qsort.
- MST start vertex considered B (vertex 1), but Kruskal does not depend on start vertex.
- Used edge list (adjacency list) instead of matrix.
*/
