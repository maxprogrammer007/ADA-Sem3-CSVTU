#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
};

// Comparator function to sort edges by weight
bool compareEdges(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}

class DisjointSet {
private:
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int i) {
        if (parent[i] != i)
            parent[i] = find(parent[i]); // Path compression
        return parent[i];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

void kruskal(int vertices, vector<Edge> &edges) {
    // Sort edges by weight
    sort(edges.begin(), edges.end(), compareEdges);

    DisjointSet ds(vertices);
    cout << "Edges in the Minimum Spanning Tree:\n";
    int mst_weight = 0;

    for (const auto &edge : edges) {
        if (ds.find(edge.u) != ds.find(edge.v)) {
            cout << edge.u << " -- " << edge.v << " == " << edge.weight << endl;
            ds.unionSets(edge.u, edge.v);
            mst_weight += edge.weight;
        }
    }
}

int main() {
    int vertices, num_edges;

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    cout << "Enter the number of edges: ";
    cin >> num_edges;

    vector<Edge> edges(num_edges);

    cout << "Enter the edges (u v weight):\n";
    for (int i = 0; i < num_edges; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    kruskal(vertices, edges);

    return 0;
}
