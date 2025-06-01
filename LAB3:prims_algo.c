#include <stdio.h> 
#define INF 999 
 
int main() { 
    int n, i, j, cost[10][10], visited[10] = {0}, min, u, v, total = 0; 
 
    printf("Enter number of nodes: "); 
    scanf("%d", &n); 
    printf("Enter adjacency matrix (0 for no edge):\n"); 
    for (i = 0; i < n; i++) 
        for (j = 0; j < n; j++) { 
            scanf("%d", &cost[i][j]); 
            if (cost[i][j] == 0 && i != j) cost[i][j] = INF; 
        } 
 
    visited[0] = 1; 
    for (int edges = 0; edges < n - 1; edges++) { 
        min = INF; 
        for (i = 0; i < n; i++) 
            if (visited[i]) 
                for (j = 0; j < n; j++) 
                    if (!visited[j] && cost[i][j] < min) 
                        min = cost[i][j], u = i, v = j; 
 
        printf("Edge %d: (%d-%d) cost: %d\n", edges + 1, u, v, min); 
        total += min; 
        visited[v] = 1; 
    } 
 
    printf("Minimum cost: %d\n", total); 
    return 0; 
} 
 
