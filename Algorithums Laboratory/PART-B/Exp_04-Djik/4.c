#include<stdio.h>              // Standard I/O for printf
#include<limits.h>             // For INT_MAX
#define V 7                   // Number of vertices in the graph
#define INF INT_MAX           // Infinity value for initial distances

int g[V][V], v[V], d[V], p[V]; // Graph adjacency matrix, visited array, distance array, parent array
char c[V][15] = {"SF", "LA", "DE", "C", "DA", "B", "NY"};  // City names for printing

// Dijkstra's algorithm to find shortest path from vertex 0 (San Francisco)
void dijk() {
    for(int i=0; i<V; i++) d[i] = INF, v[i] = 0;  // Initialize distances to INF and visited false
    d[0] = 0;                                     // Distance to start vertex 0 is 0

    for(int i=0; i<V-1; i++) {                     // Loop to find shortest path to all vertices
        int u = -1, min = INF;                     // Initialize min distance and vertex
        for(int j=0; j<V; j++)                      // Find unvisited vertex with minimum distance
            if(!v[j] && d[j] < min) min = d[j], u = j;

        v[u] = 1;                                 // Mark vertex u as visited

        for(int j=0; j<V; j++)                     // Update distances for neighbors of u
            if(!v[j] && g[u][j] && d[u] + g[u][j] < d[j])
                d[j] = g[u][j] + d[u], p[j] = u;  // Relax edge if shorter path found
    }
}

void main() {
    // Initialize undirected weighted graph edges with distances between cities
    g[0][1] = g[1][0] = 3; g[0][2] = g[2][0] = 4; g[0][3] = g[3][0] = 5;
    g[1][4] = g[4][1] = 5; g[2][3] = g[3][2] = 6; g[2][4] = g[4][2] = 4;
    g[3][4] = g[4][3] = 5; g[3][5] = g[5][3] = 3; g[3][6] = g[6][3] = 4;
    g[5][6] = g[6][5] = 2; g[4][6] = g[6][4] = 6;

    dijk();      // Call Dijkstra's algorithm from San Francisco (index 0)

    for(int i=1; i<V; i++)                         // Print shortest distances from SF to other cities
        printf("%s-%s: %d\n", c[0], c[i], d[i]);
}

/*
Modification notes for P4:
- Change graph edges or number of vertices to reflect different cities.
- Change start city by modifying d[start_vertex] = 0 and adjacency matrix accordingly.
*/
