
#include <stdio.h>

#define INF 99999

int main() {
    int V;
    int graph[100][100];
    int visited[100] = {0};
    int i, j, edges = 0;
    int min, u = -1, v = -1;
    int totalCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);

            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INF;
        }
    }
    visited[0] = 1;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while (edges < V - 1) {
        min = INF;
        u = -1;
        v = -1;

        for (i = 0; i < V; i++) {
            if (visited[i]) {
                for (j = 0; j < V; j++) {
                    if (!visited[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u == -1) {
            printf("MST does not exist (graph is disconnected).\n");
            return 0;
        }

        printf("%d -- %d = %d\n", u, v, min);

        totalCost += min;
        visited[v] = 1;
        edges++;
    }

    printf("Minimum Cost = %d\n", totalCost);

    return 0;
}