#include <stdio.h>
#include <limits.h>

#define V 4

int min(int x, int y) {
	
    return (x < y) ? x : y;
    
}

int tsp(int graph[V][V]) {
    
    int dp[1 << V][V];
    int i, j, mask, u, v;
    
    for (i = 0; i < (1 << V); i++) {
        for (j = 0; j < V; j++) {
        	
            dp[i][j] = INT_MAX;
            
        }
    }

    dp[1][0] = 0;

    for (mask = 1; mask < (1 << V); mask++) {
        for (u = 0; u < V; u++) {
            
            if (mask & (1 << u)) {
        
                for (v = 0; v < V; v++) {
                    
                    if (!(mask & (1 << v)) && graph[u][v] && dp[mask][u] != INT_MAX) {
                    	
                        dp[mask | (1 << v)][v] = min(dp[mask | (1 << v)][v], dp[mask][u] + graph[u][v]);
                        
                    }
                    
                }
                
            }
            
        }
    }

    int min_cost = INT_MAX;
    
    for (i = 0; i < V; i++) {
        if (dp[(1 << V) - 1][i] != INT_MAX && graph[i][0] != 0) {
        	
            min_cost = min(min_cost, dp[(1 << V) - 1][i] + graph[i][0]);
            
        }
    }

    return min_cost;
}

int main() {
    
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int min_cost = tsp(graph);
    printf("Minimum cost of the traveling salesman tour is: %d\n", min_cost);

    return 0;
}

