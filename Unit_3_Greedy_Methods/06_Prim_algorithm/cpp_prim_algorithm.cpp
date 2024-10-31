#include <iostream>
#include <vector>
#include <limits>
#include <utility>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
    int vertex;
    int weight;
};

// Class to represent the graph
class Graph {
private:
    int numVertices; // Number of vertices
    vector<vector<Edge>> adjList; // Adjacency list

public:
    Graph(int vertices);
    void addEdge(int src, int dest, int weight);
    void primMST();
};

// Constructor to initialize the graph
Graph::Graph(int vertices) {
    numVertices = vertices;
    adjList.resize(vertices);
}

// Function to add an edge to the graph
void Graph::addEdge(int src, int dest, int weight) {
    adjList[src].push_back({dest, weight});
    adjList[dest].push_back({src, weight}); // Since the graph is undirected
}

// Function to find the vertex with the minimum key value
int minKey(const vector<int>& key, const vector<bool>& mstSet) {
    int minValue = numeric_limits<int>::max();
    int minIndex = -1;

    for (int v = 0; v < key.size(); v++) {
        if (!mstSet[v] && key[v] < minValue) {
            minValue = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

// Function to implement Prim's algorithm
void Graph::primMST() {
    vector<int> parent(numVertices, -1); // Array to store constructed MST
    vector<int> key(numVertices, numeric_limits<int>::max()); // Key values to pick the minimum weight edge
    vector<bool> mstSet(numVertices, false); // To represent the set of vertices included in MST

    key[0] = 0; // Start from the first vertex

    for (int count = 0; count < numVertices - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet);
        mstSet[u] = true; // Add the picked vertex to the MST Set

        // Update key value and parent index of the adjacent vertices
        for (const Edge& edge : adjList[u]) {
            int v = edge.vertex;
            int weight = edge.weight;

            // Update key only if weight is smaller than current key[v]
            if (!mstSet[v] && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
            }
        }
    }

    // Print the constructed MST
    cout << "Edge \tWeight\n";
    for (int i = 1; i < numVertices; i++) {
        cout << parent[i] << " -- " << i << "\t" << key[i] << endl;
    }
}

int main() {
    // Create a graph given in the example
    Graph graph(5);
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 3, 6);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 8);
    graph.addEdge(1, 4, 5);
    graph.addEdge(2, 4, 7);
    graph.addEdge(3, 4, 9);

    // Find the Minimum Spanning Tree
    graph.primMST();

    return 0;
}
