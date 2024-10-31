#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 9 // Number of vertices in the graph

// Function to find the vertex with the minimum distance value
int min_distance(int dist[], int spt_set[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (spt_set[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to implement Dijkstra's algorithm
void dijkstra(int graph[V][V], int src) {
    int dist[V];     // Output array to hold the shortest distance from source
    int spt_set[V];  // Shortest Path Tree set

    // Initialize all distances as INFINITE and spt_set[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        spt_set[i] = 0;
    }

    // Distance from the source to itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices
        int u = min_distance(dist, spt_set);

        // Mark the picked vertex as processed
        spt_set[u] = 1;

        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            // Update dist[v] if and only if it is not in spt_set, there is an edge from u to v,
            // and the total weight of the path from src to v through u is smaller than the current value of dist[v]
            if (!spt_set[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the constructed distance array
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t\t%d\n", i, dist[i]);
    }
}

int main() {
    // Adjacency matrix representation of the graph
    int graph[V][V] = {
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


/*

Explanation
Graph Representation: The graph is represented as an adjacency matrix. Each cell graph[i][j] holds the weight of the edge between vertex i and vertex j. A value of 0 indicates no edge exists.

min_distance Function: This function finds the vertex with the minimum distance value that has not been processed yet. It iterates through all vertices and returns the index of the vertex with the smallest distance.

dijkstra Function:

    Initializes the distance array (dist) to INT_MAX (infinity) and the shortest path tree set (spt_set) to 0 (false).
    Sets the distance from the source to itself as 0.
    For each vertex, it picks the minimum distance vertex, marks it as processed, and updates the distance values of its adjacent vertices.

Main Function: Defines the graph using an adjacency matrix and calls the dijkstra function to compute and print the shortest distances from the source vertex to all other vertices.

When you run this code, it will print the shortest distance from the source vertex (0) to all other vertices:

Vertex	Distance from Source
0		0
1		4
2		12
3		19
4		21
5		11
6		9
7		8
8		14

*/