#include<stdio.h>          // Standard I/O for printf

// Function to get max of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Dynamic Programming implementation of 0/1 Knapsack
void ks(int c, int wt[], int p[], int n) {
    int k[n+1][c+1], i, w;

    // Build table k[][] in bottom-up manner
    for(i=0; i<=n; i++)
        for(w=0; w<=c; w++)
            k[i][w] = (i == 0 || w == 0) ? 0 :                // Base case: no items or zero capacity
                      (wt[i-1] <= w) ?                          // If item i fits in capacity w
                        max(p[i-1] + k[i-1][w - wt[i-1]], k[i-1][w])  // Max of including or excluding item
                        : k[i-1][w];                            // Else exclude item

    printf("\nMax profit: %d", k[n][c]);                      // Print maximum profit achievable

    w = c;
    printf("\nItems: ");
    // Trace back which items are included in the optimal solution
    for(i = n; i > 0 && w > 0; i--)
        if(k[i][w] != k[i-1][w]) {                            // If profit changed, item was included
            printf("%d ", i);                                 // Print item index (1-based)
            w -= wt[i-1];                                     // Reduce remaining capacity
        }
}

void main() {
    int c = 8;                        // Knapsack capacity = 8
    int wt[] = {1,2,3,2};         // Weights of 4 items
    int p[] = {10,15,25,12};      // Profits of 4 items
    int n = sizeof(p)/sizeof(p[0]), i;

    printf("\nWeights: ");
    for(i=0; i<n; i++) printf("%d ", wt[i]);     // Print weights
    printf("\nProfits: ");
    for(i=0; i<n; i++) printf("%d ", p[i]);      // Print profits
    printf("\nCapacity: %d", c);

    ks(c, wt, p, n);                              // Call knapsack function
}

/* 
Modification notes for P3 and P6: 
- Add another object: Weight=3, Profit=25 (Add to wt and p arrays)
- Duplicate an object: Repeat any item weight and profit in arrays
- Change knapsack capacity: modify c (e.g., W=5 or W=10)
*/
