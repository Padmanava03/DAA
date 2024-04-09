#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 9999
#define MAX_VERTICES 100

typedef struct graph{
	
	int vertices;
	int adjMat[MAX_VERTICES][MAX_VERTICES];
	
}Graph;

void Initialize(Graph* graph, int vertices){
	
	graph->vertices = vertices;
	
	int i,j;
	for(i = 0; i < graph->vertices; i++){
		for(j = 0; j < graph->vertices; j++){
			
			graph->adjMat[i][j] = 0;
			
		}
	}
	
}

void addEdge(Graph* graph, int source, int destination, int weight){
	
	if(source >= 0 && source < graph->vertices && destination >= 0 && destination < graph->vertices){
		
		graph->adjMat[source][destination] = weight;
		
	}else{
		
		printf("Invalid edge!");
		
	}
	
}

int minDistance(Graph* graph, int dist[], bool sptSet[]){
	
	int min = INF, min_index, v;
	
	for(v = 0; v < graph->vertices; v++){
		
		if(sptSet[v] == false && dist[v] <= min){
			
			min = dist[v];
			min_index = v;
			
		}
		
	}
	
	return min_index;
	
}

void printSolution(Graph* graph, int dist[], int src){
	
	printf("Vertex \t Distance from source %d :\n",src);
	
	int v;
	for(v = 0; v < graph->vertices; v++){
		
		printf("  %d \t\t   %d\n",v,dist[v]);
		
	}
	
}

void Dijkstra(Graph* graph, int src){
	
	int dist[graph->vertices];
	bool sptSet[graph->vertices];
	
	int v;
	for(v = 0; v < graph->vertices; v++){
		
		dist[v] = INF;
		sptSet[v] = false;
		
	}
	
	dist[src] = 0;
	
	int count;
	for(count = 0; count < graph->vertices; count++){
		
		int u = minDistance(graph, dist, sptSet);
		sptSet[u] = true;
		
		for(v = 0; v < graph->vertices; v++){
			
			if(!sptSet[v] && graph->adjMat[u][v] && dist[u] != INF && dist[u] + graph->adjMat[u][v] < dist[v]){
				
				dist[v] = dist[u] + graph->adjMat[u][v];
				
			}
			
		}
		
	}
	
	printSolution(graph, dist, src);
	
}

int main(){
	
	Graph graph;
	int vertices, edges, source, destination, weight, i, src;
	
	printf("Enter the number of vertices = ");
	scanf("%d",&vertices);
	
	Initialize(&graph, vertices);
	
	printf("Enter the number of edges = ");
	scanf("%d",&edges);
	
	printf("Enter the edges:\n");
	for(i = 0; i < edges; i++){
		
		printf("Edge %d : ",i+1);
		scanf("%d %d %d",&source,&destination,&weight);
		addEdge(&graph, source, destination, weight);
		
	}
	
	printf("Enter the source vertex = ");
	scanf("%d",&src);
	
	Dijkstra(&graph, src);
	
	return 0;
	
}
