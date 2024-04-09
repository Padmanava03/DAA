#include <stdio.h>
#include <stdlib.h>

struct Item
{
    float weight;
    int value;
};

struct Node
{
    int level;
    float profit, bound, weight;
};

int cmp(const void *a, const void *b)
{
    double r1 = (double)((struct Item *)a)->value / ((struct Item *)a)->weight;
    double r2 = (double)((struct Item *)b)->value / ((struct Item *)a)->weight;
    return (r1<r2)?1:((r1>r2)?-1:0);
}

float bound(struct Node u, int n, int W, struct Item arr[])
{
    if (u.weight >= W)
        return 0;

    float profit_bound = u.profit;

    int j = u.level + 1;
    float totweight = u.weight;

    while ((j < n) && (totweight + arr[j].weight <= W))
    {
        totweight += arr[j].weight;
        profit_bound += arr[j].value;
        j++;
    }

    if (j < n)
        profit_bound += (W - totweight) * ((double)arr[j].value / arr[j].weight);
    return profit_bound;
}

int knapsack(int W, struct Item arr[], int n)
{
    qsort(arr, n, sizeof(struct Item), cmp);

    struct Node Q[n + 1];
    struct Node u, v;

    u.level = -1;
    u.profit = u.weight = 0;
    Q[0] = u;

    float maxProfit = 0;
    int front = 0, rear = 0;
    while (front <= rear)
    {
        u = Q[front++];
        v.level = u.level + 1;

        v.weight = u.weight + arr[v.level].weight;
        v.profit = u.profit + arr[v.level].value;

        if (v.weight <= W && v.profit > maxProfit)
            maxProfit = v.profit;

        v.bound = bound(v, n, W, arr);

        if (v.bound > maxProfit)
        {
            if (rear < n)
                Q[++rear] = v;
        }

        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = bound(v, n, W, arr);
        if (v.bound > maxProfit)
        {
            if (rear < n)
                Q[++rear] = v;
        }
    }

    return (int)maxProfit;
}


int main()
{
    int W = 10;
    struct Item arr[] = {{2, 40}, {3.14, 50}, {1.98, 100},
                         {5, 95}, {3, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Maximum possible profit = %d\n", knapsack(W, arr, n));
    return 0;
}

