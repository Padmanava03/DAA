#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 100

void matrixChainOrder(int p[], int n) {
    
    int m[MAX_SIZE][MAX_SIZE];
    int s[MAX_SIZE][MAX_SIZE];

	int i, l, k;

    for (i = 1; i <= n; i++)
        m[i][i] = 0;

    for (l = 2; l <= n; l++) {
        for (i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("Optimal Parenthesizing: ");
    printOptimalParenthesis(s, 1, n);
    printf("\nMinimum Cost: %d\n", m[1][n]);
    
}

void printOptimalParenthesis(int s[][MAX_SIZE], int i, int j) {
	
    if (i == j)
        printf("A%d", i);
    else {
        printf("(");
        printOptimalParenthesis(s, i, s[i][j]);
        printOptimalParenthesis(s, s[i][j] + 1, j);
        printf(")");
    }
    
}

int main() {
	
    int p[] = {30, 35, 15, 5, 10, 20, 25};
    int n = sizeof(p) / sizeof(p[0]) - 1;

    matrixChainOrder(p, n);

    return 0;
    
}

