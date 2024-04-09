#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 100
#define INF 9999

typedef struct graph{
	int vertices;
	int adjMat[V][V];
}Graph;

void Initialize(Graph* graph, int vertices){
	graph->vertices = vertices;
	int i,j;
	for(i=0;i<graph->vertices;i++){
		for(j=0;j<graph->vertices;j++){
			graph->adjMat[i][j]=0;
		}
	}
}

void addEdge(Graph* graph, int source, int destination, int weight){
	if(source>=0 && source<graph->vertices && destination>=0 && destination<graph->vertices){
		graph->adjMat[source][destination]=weight;
		graph->adjMat[destination][source]=weight;
	}else{
		printf("Invalid edge!\n");
	}
}

int minKey(Graph* graph, int key[], bool mstSet[]){
	int min = INF, min_index;
	int v;
	for(v=0;v<graph->vertices;v++){
		if(mstSet[v]==false && key[v]<min){
			min=key[v];
			min_index=v;
		}
	}
	return min_index;
}

void printMST(Graph* graph, int parent[]){
	printf("Edge \t Distance\n");
	int v;
	for(v=1;v<graph->vertices;v++){
		printf(" %d-%d \t    %d\n",parent[v],v,graph->adjMat[v][parent[v]]);
	}
}

void primMST(Graph* graph){
	int parent[graph->vertices];
	int key[graph->vertices];
	bool mstSet[graph->vertices];
	int v;
	for(v=0;v<graph->vertices;v++){
		key[v]=INF, mstSet[v]=false;
	}
	key[0]=0;
	parent[0]=-1;
	int count;
	for(count=0;count<graph->vertices;count++){
		int u=minKey(graph,key,mstSet);
		mstSet[u]=true;
		for(v=0;v<graph->vertices;v++){
			if(graph->adjMat[u][v] && mstSet[v]==false && graph->adjMat[u][v]<key[v]){
				parent[v]=u, key[v]=graph->adjMat[u][v];
			}
		}
	}
	printMST(graph, parent);
}

int main(){
	int vertices, edges, source, destination, weight, i;
	Graph graph;
	printf("Enter the number of vertices = ");
	scanf("%d",&vertices);
	Initialize(&graph, vertices);
	printf("Enter the number of edges = ");
	scanf("%d",&edges);
	printf("Enter the edges :\n");
	for(i=0;i<edges;i++){
		printf("Edges %d : ",i+1);
		scanf("%d %d %d",&source,&destination,&weight);
		addEdge(&graph, source, destination, weight);
	}
	primMST(&graph);
	return 0;
}
