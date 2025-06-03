#include<stdio.h>             // Standard I/O for printf
#include<limits.h>            // For INT_MAX constant
#define V 6                  // Number of vertices in the graph
#define INF INT_MAX          // Infinity for initial distances

int g[V][V], v[V], d[V], p[V]; // Graph matrix, visited flags, distance array, parent array
char c[V] = "ABCDEF";          // Vertex labels for printing

// Prim's algorithm to find MST starting from vertex 0 (can be changed to any vertex)
void prims() {
    for(int i=0; i<V; i++) d[i] = INF, v[i] = 0; // Initialize distances as infinity, visited as false
    d[0] = 0;                                   // Starting vertex distance is zero

    for(int i=0; i<V-1; i++) {
        int u = -1, min = INF;                   // Minimum distance vertex to pick next
        for(int j=0; j<V; j++)
            if(!v[j] && d[j] < min) min = d[j], u = j;  // Pick vertex with minimum dist not visited
        v[u] = 1;                               // Mark chosen vertex as visited

        for(int j=0; j<V; j++)
            if(!v[j] && g[u][j] && g[u][j] < d[j])  // Update distance to neighbors if shorter edge found
                d[j] = g[u][j], p[j] = u;
    }
}

void main() {
    // Initialize graph edges (example weights for driving routes)
    g[0][1] = g[1][0] = 4; g[0][2] = g[2][0] = 2; g[1][2] = g[2][1] = 1;
    g[1][3] = g[3][1] = 5; g[2][3] = g[3][2] = 8; g[2][4] = g[4][2] = 10;
    g[3][4] = g[4][3] = 2; g[3][5] = g[5][3] = 6; g[4][5] = g[5][4] = 3;

    prims();                      // Run Prim’s MST starting from vertex 0 (A)

    int cost = 0;
    for(int i=1; i<V; i++) {
        cost += d[i];             // Sum of edge weights in MST
        printf("%d-%d: %d\n", p[i], i, d[i]);  // Print MST edges: parent to current vertex with weight
    }
    printf("\nTotal minimum driving route cost: %d\n", cost);

    for(int i=0; i<V; i++)
        printf("%d-%c\n", i, c[i]);    // Print vertex index and label
}

/*
Modification notes for P2:
- Start from any vertex by changing d[start_vertex] = 0.
- Graph size and edges can be updated for different maps.
*/
