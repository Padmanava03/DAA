#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

typedef struct queue{
	
	int front;
	int rear;
	int items[MAX_NODES];
	
}Queue;

Queue* createQueue(){
	
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue->front = -1;
	queue->rear = -1;
	
	return queue;
	
}

bool isEmpty(Queue* queue){
	
	return queue->front == -1;
	
}

void enqueue(Queue* queue, int value){
	
	if(queue->rear == MAX_NODES-1){
		printf("Queue is overflown!");
	}else{
		if(queue->front == -1)
			queue->front = 0;
		queue->rear++;
		queue->items[queue->rear] = value;
	}
	
}

int dequeue(Queue* queue){
	
	int item;
	
	if(isEmpty(queue)){
		printf("Queue is underflown!");	
		item = -1;
	}else{
		item = queue->front;
		queue->front++;
		if(queue->front > queue->rear)
			queue->front = queue->rear = -1;
	}
	
	return item;
	
}

void BFS(int adjMat[][MAX_NODES], int start, int n){
	
	int i;
	
	Queue* queue = createQueue();
	
	bool visited[MAX_NODES] = {false};
	
	visited[start] = true;
	enqueue(queue, start);
	
	while(!isEmpty(queue)){
		int currentNode = dequeue(queue);
		printf("%d ",currentNode);
		
		for(i=0; i<n; i++){
			if(adjMat[currentNode][i] &&!visited[i]){
				visited[i]=true;
				enqueue(queue, i);
			}
		}
	}
	
}

int main(){
	
	int n, i, j, startingVertex;
	int adjMat[MAX_NODES][MAX_NODES];
	
	printf("Enter the number of nodes = ");
	scanf("%d",&n);
	
	printf("Enter the adjacency matrix:\n");
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			scanf("%d",&adjMat[i][j]);
		}
	}
	
	printf("Enter the starting vertex = ");
	scanf("%d",&startingVertex);
	
	printf("BFS traversal:\n");
	BFS(adjMat, startingVertex, n);
	
	return 0;
	
}
