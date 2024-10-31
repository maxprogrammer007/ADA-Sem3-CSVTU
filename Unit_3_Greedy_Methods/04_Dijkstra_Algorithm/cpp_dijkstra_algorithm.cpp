#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

#define V 9 // Number of vertices in the graph

// Function to find the vertex with the minimum distance value
int minDistance(const vector<int>& dist, const vector<bool>& sptSet) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to implement Dijkstra's algorithm
void dijkstra(const vector<vector<int>>& graph, int src) {
    vector<int> dist(V, INT_MAX);     // Output array to hold the shortest distance from source
    vector<bool> sptSet(V, false);    // Shortest Path Tree set

    // Distance from the source to itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            // Update dist[v] if and only if it is not in sptSet, there is an edge from u to v,
            // and the total weight of the path from src to v through u is smaller than the current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the constructed distance array
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t\t" << dist[i] << endl;
    }
}

int main() {
    // Adjacency matrix representation of the graph
    vector<vector<int>> graph = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 0, 10},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 0, 0, 0, 0, 0, 1, 0, 7},
        {0, 10, 2, 0, 0, 0, 6, 7, 0}
    };

    int source = 0; // Starting node
    dijkstra(graph, source);

    return 0;
}
