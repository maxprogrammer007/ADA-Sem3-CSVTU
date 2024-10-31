#include <iostream>
#include <vector>
#include <limits>

#define INF std::numeric_limits<int>::max() // Define a constant for infinity

void floydWarshall(std::vector<std::vector<int>>& graph) {
    int V = graph.size(); // Number of vertices

    // Update the distances using the Floyd-Warshall algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (graph[i][k] != INF && graph[k][j] != INF) {
                    if (graph[i][k] + graph[k][j] < graph[i][j]) {
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                }
            }
        }
    }
}

void printSolution(const std::vector<std::vector<int>>& graph) {
    std::cout << "The following matrix shows the shortest distances between every pair of vertices:\n";
    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph.size(); j++) {
            if (graph[i][j] == INF) {
                std::cout << "INF\t";
            } else {
                std::cout << graph[i][j] << "\t";
            }
        }
        std::cout << "\n";
    }
}

int main() {
    // Input graph represented as an adjacency matrix
    std::vector<std::vector<int>> graph = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}
    };

    floydWarshall(graph);
    printSolution(graph);

    return 0;
}
