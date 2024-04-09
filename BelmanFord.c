#include <stdio.h>
#include <stdlib.h>

#define INF 9999
#define V 100

typedef struct graph{
	
	int vertices;
	int adjMat[V][V];
	
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

void printSolution(Graph* graph, int dist[], int src){
	
	printf("Vetrex \t Distance from source vertex %d :\n",src);
	
	int i;
	for(i = 0; i < graph->vertices; i++){
		
		printf("  %d \t   %d\n",i,dist[i]);
		
	}
	
}

void BellmanFord(Graph* graph, int src){
	
	int dist[graph->vertices];
	int i, u, v;
	
	for(i = 0; i < graph->vertices; i++){
		
		dist[i] = INF;
		
	}
	
	dist[src] = 0;
	
	for( i = 1; i <= graph->vertices-1; i++ ){
		for( u = 0; u < graph->vertices; u++){
			for( v = 0; v < graph->vertices; v++){
				
				if(graph->adjMat[u][v] != 0 && dist[u] != INF && dist[u] + graph->adjMat[u][v] < dist[v]){
					
					dist[v] = dist[u] + graph->adjMat[u][v];
					
				}
				
			}
		}
	}
	
	for( u = 0; u < graph->vertices; u++){
		for( v = 0; v < graph->vertices; v++){
			
			if(graph->adjMat[u][v] !=0 && dist[u] != INF && dist[u] + graph->adjMat[u][v] < dist[v]){
					
				printf("Graph contains negative weight cycle!!");
				return;
					
			}
			
		}
	}
	
	printSolution(graph, dist, src);
	
}

int main(){
	
	int vertices, edges, source, destination, weight, src, i;
	Graph graph;
	
	printf("Enter the number of vertices = ");
	scanf("%d",&vertices);
	
	Initialize(&graph, vertices);
	
	printf("Enter the number of edges = ");
	scanf("%d",&edges);
	
	printf("Enter the edges :\n");
	for(i = 0; i < edges; i++){
		
		printf("Edge %d : ",i+1);
		scanf("%d %d %d",&source,&destination,&weight);
		addEdge(&graph, source, destination, weight);
		
	}
	
	printf("Enter the source vertex = ");
	scanf("%d",&src);
	
	BellmanFord(&graph, src);
	
	return 0;
	
}
