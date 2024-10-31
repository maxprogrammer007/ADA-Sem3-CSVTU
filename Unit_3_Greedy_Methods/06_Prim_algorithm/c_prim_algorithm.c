#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 5 // Number of vertices in the graph

// Function to find the vertex with the minimum key value
int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;
    
    for (int v = 0; v < V; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    
    return min_index;
}

// Function to implement Prim's algorithm
void primMST(int graph[V][V]) {
    int parent[V]; // Array to store constructed MST
    int key[V];    // Key values used to pick the minimum weight edge
    bool mstSet[V]; // To represent the set of vertices included in MST

    // Initialize all keys as infinite and mstSet as false
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Always include the first vertex in MST
    key[0] = 0;     // Make key 0 so that this vertex is picked as the first vertex
    parent[0] = -1; // First node is always the root of the MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet);
        
        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices
        for (int v = 0; v < V; v++) {
            // Update key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d -- %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

int main() {
    // Adjacency matrix representation of the graph
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);

    return 0;
}

/*

Explanation
Graph Representation: The graph is represented using an adjacency matrix graph[V][V], where V is the number of vertices.

Key and MST Set:

key[] array holds the minimum weight edge for each vertex.
mstSet[] array keeps track of vertices included in the MST.
minKey Function: This function finds the vertex with the minimum key value that hasn’t been included in the MST yet.

Prim's Algorithm Implementation:

The first vertex is initialized with a key value of 0 to start the MST.
The algorithm iteratively picks the minimum key vertex, adds it to the MST, and updates the key values for its adjacent vertices.
Output: The edges included in the MST along with their weights are printed.

Example Output
When you run this program, the output will display the edges included in the Minimum Spanning Tree along with their weights:

Edge     Weight
0 -- 1   2
1 -- 2   3
0 -- 3   6
1 -- 4   5


*/