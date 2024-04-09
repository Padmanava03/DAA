#include <stdio.h>
#include <stdlib.h>

struct Item{
	int value;
	int weight;
};

int compare(const void* a, const void* b){
	double r1 = ((struct Item*)a)->value/(double)((struct Item*)a)->weight;
	double r2 = ((struct Item*)b)->value/(double)((struct Item*)b)->weight;
	return (r1<r2)?1:((r1>r2)?-1:0);
}

double fractionalKnapSack(int capacity, struct Item items[], int n){
	qsort(items, n, sizeof(items[0]), compare);
	double total =0.0;
	int i;
	for(i=0;i<n;i++){
		if(items[i].weight<=capacity){
			total+=items[i].value;
			capacity-=items[i].weight;
		}else{
			total+=items[i].value*((double)capacity/(items[i].weight));
			break;
		}
	}
	return total;
}

int main(){
	int capacity, n, i;
	printf("Enter the capacity of sack = ");
	scanf("%d",&capacity);
	printf("Enter the number of items = ");
	scanf("%d",&n);
	struct Item items[n];
	printf("Enter the items :\n");
	for(i=0;i<n;i++){
		printf("Item %d : ",i+1);
		scanf("%d %d",&items[i].value,&items[i].weight);
	}
	printf("Profit is : %.2lf",fractionalKnapSack(capacity, items, n));
	return 0;
}
