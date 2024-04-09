#include <stdio.h>
#include <stdlib.h>

struct Job {
    int id;
    int deadline;
    int profit;
};

int compare(const void* a, const void* b) {
    return ((struct Job*)b)->profit - ((struct Job*)a)->profit;
}

int findMaxDeadline(struct Job arr[], int n) {
    int max_deadline = 0;
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i].deadline > max_deadline) {
            max_deadline = arr[i].deadline;
        }
    }
    return max_deadline;
}

void jobSequencing(struct Job arr[], int n) {
    qsort(arr, n, sizeof(struct Job), compare);
    int max_deadline = findMaxDeadline(arr, n);
    int* slot = (int*)malloc(max_deadline * sizeof(int));
    int i, j;
    for (i = 0; i < max_deadline; i++) {
        slot[i] = -1;
    }
    int total_profit = 0;
    for (i = 0; i < n; i++) {
        for (j = arr[i].deadline - 1; j >= 0; j--) {
            if (slot[j] == -1) {
                slot[j] = arr[i].id;
                total_profit += arr[i].profit;
                break;
            }
        }
    }
    printf("Sequence of jobs with deadlines:\n");
    printf("Job ID   Profit\n");
    for (i = 0; i < max_deadline; i++) {
        if (slot[i] != -1) {
            printf("Job %d     %d\n", slot[i], arr[slot[i] - 1].profit);
        }
    }
    printf("Total Profit: %d\n", total_profit);
    free(slot);
}

int main() {
	int n, i;
	printf("Enter the number of jobs = ");
	scanf("%d",&n);
    struct Job jobs[n];
    printf("Enter the job details :\n");
    for(i=0;i<n;i++){
    	jobs[i].id=i+1;
    	printf("Job %d : ",i+1);
    	scanf("%d %d",&jobs[i].deadline,&jobs[i].profit);
	}

    jobSequencing(jobs, n);

    return 0;
}

