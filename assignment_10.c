#include <stdio.h>

#define V 4
#define INF 9999

void floydWarshall(int dist[][V])
{
	int i, j, k;

	for (k = 0; k < V; k++) {
		for (i = 0; i < V; i++) {
			for (j = 0; j < V; j++) {
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	printSolution(dist);
}

void printSolution(int dist[][V])
{
	int i, j;
	
	printf("The following matrix shows the shortest distances between every pair of vertices \n");
	for (i = 0; i < V; i++) {
		for (j = 0; j < V; j++) {
			if (dist[i][j] == INF)
				printf("%7s", "INF");
			else
				printf("%7d", dist[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	
	int graph[V][V] = { { 0, 3, INF, INF },
						{ INF, 0, 12, 5 },
						{ 4, INF, 0, -1 },
						{ 2, -4, INF, 0 } };

	floydWarshall(graph);
	return 0;
	
}

