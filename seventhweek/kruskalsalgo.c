
#include <stdio.h>

struct Edge {
    int u, v, weight;
};

int parent[100];

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void unionSet(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    parent[rootU] = rootV;
}

int main() {
    int V, E;
    struct Edge edges[100];
    int i, j, count = 0, totalCost = 0;
    struct Edge temp;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter edges (u v weight):\n");

    for (i = 0; i < E; i++) {
        scanf("%d %d %d",
              &edges[i].u,
              &edges[i].v,
              &edges[i].weight);
    }

    for (i = 0; i < V; i++) {
        parent[i] = i;
    }

    for (i = 0; i < E - 1; i++) {
        for (j = 0; j < E - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    printf("\nEdges in Minimum Spanning Tree:\n");

    for (i = 0; i < E && count < V - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        if (find(u) != find(v)) {
            printf("%d -- %d = %d\n",
                   u, v, edges[i].weight);

            totalCost += edges[i].weight;
            unionSet(u, v);
            count++;
        }
    }

    if (count != V - 1) {
        printf("MST does not exist (graph is disconnected).\n");
    } else {
        printf("Minimum Cost = %d\n", totalCost);
    }

    return 0;
}