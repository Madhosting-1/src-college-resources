#include<stdio.h>             // For printf
#include<limits.h>            // For INT_MAX
#define V 6                  // Number of vertices (campsites)
#define INF INT_MAX          // Define infinity

int g[V][V], v[V], d[V], p[V]; // Graph adjacency matrix, visited, distance, parent arrays
char c[V] = "ABCDEF";          // Vertex labels representing campsites

// Prim's algorithm to find MST minimizing pipe length for water connection
void prims() {
    for(int i=0; i<V; i++) d[i] = INF, v[i] = 0;  // Initialize distances and visited
    d[0] = 0;                                    // Start from vertex 0

    for(int i=0; i<V-1; i++) {
        int u = -1, min = INF;
        for(int j=0; j<V; j++)
            if(!v[j] && d[j] < min) min = d[j], u = j;  // Pick closest vertex not in MST
        v[u] = 1;                                    // Include vertex u in MST

        for(int j=0; j<V; j++)
            if(!v[j] && g[u][j] && g[u][j] < d[j])  // Relax edges to update distances
                d[j] = g[u][j], p[j] = u;
    }
}

void main() {
    // Graph edges representing pipe lengths between campsites
    g[0][1] = g[1][0] = 5; g[0][3] = g[3][0] = 4;
    g[1][2] = g[2][1] = 7; g[1][3] = g[3][1] = 9;
    g[2][3] = g[3][2] = 9; g[2][4] = g[4][2] = 5;
    g[3][4] = g[4][3] = 8; g[4][5] = g[5][4] = 6;

    prims();                                // Run Prim's MST from vertex 0

    int cost = 0;
    for(int i=1; i<V; i++) {
        cost += d[i];                      // Sum pipe lengths in MST
        printf("%d-%d: %d\n", p[i], i, d[i]);  // Print edge parent->child with weight
    }
    printf("\nTotal pipe length needed: %d\n", cost);

    for(int i=0; i<V; i++)
        printf("%d-%c\n", i, c[i]);        // Print campsite indices and names
}

/*
Modification notes for P5:
- Update V, graph edges for different campsite maps.
- Change starting vertex by modifying d[start_vertex] = 0.
- Update vertex labels in c[] accordingly.
*/
