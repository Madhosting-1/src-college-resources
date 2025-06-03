#include<stdio.h>            // Include standard input/output for printf
#include<limits.h>           // Include limits.h for INT_MAX definition
#define V 6                 // Number of vertices in graph
#define INF INT_MAX         // Define infinity as maximum integer value

int g[V][V], v[V], d[V], p[V]; // Graph matrix, visited array, distance array, parent array
char c[V] = "FDEACB";          // Vertex labels for printing

// Prim's algorithm function to find MST starting from vertex 0 ('F')
void prims() {
    for(int i=0; i<V; i++) d[i] = INF, v[i] = 0;  // Initialize distances as INF and visited as false
    d[0] = 0;                                    // Start from vertex 0, distance 0 to itself

    for(int i=0; i<V-1; i++) {                    // MST will have V-1 edges
        int u = -1, min = INF;                    // Initialize min distance and vertex
        for(int j=0; j<V; j++)                    // Find unvisited vertex with min distance
            if(!v[j] && d[j] < min) min = d[j], u = j;
        v[u] = 1;                                // Mark vertex u as visited (included in MST)
        for(int j=0; j<V; j++)                    // Update distances for neighbors of u
            if(!v[j] && g[u][j] && g[u][j] < d[j]) d[j] = g[u][j], p[j] = u;
    }
}

void main() {
    // Initialize undirected weighted graph edges with given pipe lengths
    g[0][1] = g[1][0] = 7; g[0][2] = g[2][0] = 8; g[1][2] = g[2][1] = 3;
    g[1][3] = g[3][1] = 6; g[2][3] = g[3][2] = 4; g[2][4] = g[4][2] = 3;
    g[3][4] = g[4][3] = 2; g[3][5] = g[5][3] = 5; g[4][5] = g[5][4] = 2;

    // Call Prim's algorithm to calculate MST starting from vertex 'F' (index 0)
    prims();

    int cost = 0;
    for(int i=1; i<V; i++) {        // Calculate total cost of MST edges
        cost += d[i];
        printf("%d-%d: %d\n", p[i], i, d[i]);  // Print edge: parent to current with weight
    }
    printf("\nTotal cost: %d\n", cost);       // Print total minimum pipe length required

    for(int i=0; i<V; i++)                  // Print vertex indices with their names
        printf("%d-%c\n", i, c[i]);
}

/* 
Modification notes for P1a: 
- Graph has 9 vertices and 14 edges, MST will have 8 edges.
- To apply for larger graph, update V and initialize g accordingly.
- Change starting vertex if needed by changing d[start_vertex] = 0.
*/
