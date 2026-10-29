
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX / 2;   
void printPath(int u, int v, const vector<vector<int>>& nxt) {
    if (nxt[u][v] == -1) { cout << "No path"; return; }
    cout << u;
    while (u != v) {
        u = nxt[u][v];
        cout << " -> " << u;
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> dist(V, vector<int>(V, INF));
    vector<vector<int>> nxt(V, vector<int>(V, -1));

    for (int i = 0; i < V; i++) {
        dist[i][i] = 0;
        nxt[i][i] = i;
    }

    cout << "Enter edges as: u v weight (0-indexed, directed)\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
        nxt[u][v] = v;
    }


    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    nxt[i][j] = nxt[i][k];
                }

    // Negative cycle check: a vertex with negative distance to itself
    for (int i = 0; i < V; i++)
        if (dist[i][i] < 0) {
            cout << "\nGraph contains a negative weight cycle!\n";
            return 0;
        }

    cout << "\nShortest distance matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] >= INF) cout << "INF\t";
            else cout << dist[i][j] << "\t";
        }
        cout << "\n";
    }

    cout << "\nPaths:\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            if (i != j) {
                cout << i << " to " << j << ": ";
                printPath(i, j, nxt);
                if (dist[i][j] < INF) cout << "  (cost " << dist[i][j] << ")";
                cout << "\n";
            }
    return 0;
}

