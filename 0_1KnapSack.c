#include <stdio.h>
#include <stdlib.h>

struct Item{
	int value;
	int weight;
};

int max(int a, int b){
	return (a>b)?a:b;
}

int Knapsack(int W, struct Item items[], int n){
	int i,w;
	int K[n+1][W+1];
	for(i=0;i<=n;i++){
		for(w=0;w<=W;w++){
			if(i==0||w==0)
				K[i][w]=0;
			else if(items[i-1].weight<=w)
				K[i][w]=max(K[i-1][w],K[i-1][w-items[i-1].weight]+items[i-1].value);
			else
				K[i][w]=K[i-1][w];
		}
	}
	return K[n][W];
}

int main(){
	int n, capacity, i;
	printf("Enter the capacity of the sack = ");
	scanf("%d",&capacity);
	printf("Enter the number of items = ");
	scanf("%d",&n);
	struct Item items[n];
	printf("Enter the items :\n");
	for(i=0;i<n;i++){
		printf("Item %d : ",i+1);
		scanf("%d %d",&items[i].value,&items[i].weight);
	}
	printf("Profit is : %d",Knapsack(capacity, items, n));
	return 0;
}
