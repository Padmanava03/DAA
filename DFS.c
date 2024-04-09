#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct graph{
	
	int vertices;
	int edges;
	int adjMat[MAX_VERTICES][MAX_VERTICES];
	
}Graph;

void Initialize(Graph* graph, int vertices){
	
	int i,j;
	
	graph->vertices = vertices;
	graph->edges = 0;
	
	for(i=0; i<graph->vertices; i++){
		for(j=0; j<graph->vertices; j++){
			graph->adjMat[i][j] = 0;
		}
	}
	
}

void addEdge(Graph* graph, int source, int destination){
	
	if(source>=0 && source<graph->vertices && destination>=0 && destination<graph->vertices){
		graph->adjMat[source][destination] = 1;
		graph->adjMat[destination][source] = 1;
		graph->edges++;
	}else{
		printf("Invalid edges!");
	}
	
}

void DFS(Graph* graph, int start, bool visited[]){
	
	int i;
	visited[start] = true;
	printf("%d ",start);
	for(i=0; i<graph->vertices; i++){
		if(graph->adjMat[start][i] && !visited[i])
			DFS(graph, i, visited);
	}
	
}

int main()
{
	
	Graph graph;
	int vertices, edges, startingVertex, source, destination, i;
	bool visited[MAX_VERTICES] = {false};
	
	printf("Enter the number of vertices = ");
	scanf("%d",&vertices);
	
	Initialize(&graph, vertices);
	
	printf("Enter the number of edges = ");
	scanf("%d",&edges);
	
	printf("\nEnter the edges:\n");
	for(i=0; i<edges; i++){
		printf("Edge %d : ",i+1);
		scanf("%d %d",&source,&destination);
		addEdge(&graph, source, destination);
	}
	
	printf("\nEnter the starting vertex = ");
	scanf("%d",&startingVertex);
	printf("DFS Traversal:\n");
	DFS(&graph, startingVertex, visited);
	
	return 0;
	
}
