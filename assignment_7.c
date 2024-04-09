#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int src, dest, weight;
};

struct DisjointSet {
    int *parent, *rank;
    int n;
};

struct DisjointSet* createDisjointSet(int n) {
	
    struct DisjointSet* set = (struct DisjointSet*)malloc(sizeof(struct DisjointSet));
    set->n = n;
    set->parent = (int*)malloc(n * sizeof(int));
    set->rank = (int*)malloc(n * sizeof(int));

	int i;

    for (i = 0; i < n; i++) {
        set->parent[i] = i;
        set->rank[i] = 0;
    }

    return set;
    
}

int find(struct DisjointSet* set, int i) {
	
    if (set->parent[i] != i) {
        set->parent[i] = find(set, set->parent[i]);
    }
    
    return set->parent[i];
    
}

void unionSets(struct DisjointSet* set, int x, int y) {
	
    int xset = find(set, x);
    int yset = find(set, y);

    if (set->rank[xset] < set->rank[yset]) {
        set->parent[xset] = yset;
    } else if (set->rank[xset] > set->rank[yset]) {
        set->parent[yset] = xset;
    } else {
        set->parent[yset] = xset;
        set->rank[xset]++;
    }
    
}

int compareEdges(const void* a, const void* b) {
	
    return 0;
    
}

void KruskalMST(struct Edge edges[], int n, int e) {
    struct Edge result[n - 1];
    int edgeCount = 0;
    int i;

    struct DisjointSet* set = createDisjointSet(n);

    for (i = 0; i < e; i++) {
        int x = find(set, edges[i].src);
        int y = find(set, edges[i].dest);

        if (x != y) {
            result[edgeCount++] = edges[i];
            unionSets(set, x, y);
        }

        if (edgeCount == n - 1) {
            break;
        }
    }

    printf("Following are the edges in the constructed MST\n");
    for (i = 0; i < edgeCount; ++i) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
    }
}

int main() {
    
    struct Edge edges[] = {
        {0, 1, 10},
        {0, 3, 1},
        {1, 2, 28},
        {1, 3, 16},
        {2, 3, 12},
        {3, 4, 24},
        {4, 2, 25},
        {4, 5, 5},
        {5, 2, 6}
    };

    int n = 6, e = sizeof(edges) / sizeof(edges[0]);

    KruskalMST(edges, n, e);

    return 0;
    
}
