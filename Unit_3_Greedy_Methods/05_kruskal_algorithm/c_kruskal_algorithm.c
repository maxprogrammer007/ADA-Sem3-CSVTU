#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INF 999999

// Structure to represent an edge in the graph
typedef struct {
    int u, v, weight;
} Edge;

// Structure to represent a subset for union-find
typedef struct {
    int parent;
    int rank;
} Subset;

// Function to compare two edges (used for sorting)
int compare(const void *a, const void *b) {
    Edge *edge1 = (Edge *)a;
    Edge *edge2 = (Edge *)b;
    return edge1->weight - edge2->weight;
}

// Function to find the subset of an element
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// Function to perform union of two subsets
void union_sets(Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (rootX != rootY) {
        if (subsets[rootX].rank < subsets[rootY].rank) {
            subsets[rootX].parent = rootY;
        } else if (subsets[rootX].rank > subsets[rootY].rank) {
            subsets[rootY].parent = rootX;
        } else {
            subsets[rootY].parent = rootX;
            subsets[rootX].rank++;
        }
    }
}

// Function to implement Kruskal's Algorithm
void kruskal(Edge edges[], int numEdges, int numVertices) {
    // Sort edges based on their weight
    qsort(edges, numEdges, sizeof(edges[0]), compare);

    // Create subsets for union-find
    Subset *subsets = (Subset *)malloc(numVertices * sizeof(Subset));
    for (int v = 0; v < numVertices; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    printf("Edges in the Minimum Spanning Tree:\n");

    for (int i = 0; i < numEdges; ++i) {
        Edge currentEdge = edges[i];
        int setU = find(subsets, currentEdge.u);
        int setV = find(subsets, currentEdge.v);

        // If including this edge does not cause a cycle
        if (setU != setV) {
            printf("%d -- %d == %d\n", currentEdge.u, currentEdge.v, currentEdge.weight);
            union_sets(subsets, setU, setV);
        }
    }

    free(subsets);
}

int main() {
    int numVertices, numEdges;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    Edge *edges = (Edge *)malloc(numEdges * sizeof(Edge));

    printf("Enter the edges (u v weight):\n");
    for (int i = 0; i < numEdges; ++i) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    kruskal(edges, numEdges, numVertices);

    free(edges);
    return 0;
}

/*

Explanation
Graph Representation: The graph is represented as a list of edges, where each edge is represented by its two endpoints (u, v) and its weight.

Edge Structure: An Edge structure is defined to hold the endpoints and the weight of each edge.

Subset Structure: A Subset structure is used for the union-find algorithm, containing a parent and a rank for each vertex.

Comparison Function: The compare function is used to sort the edges based on their weights using qsort.

Find Function: The find function implements the path compression technique to find the root of the subset containing a particular vertex.

Union Function: The union_sets function merges two subsets, ensuring that the smaller tree is added under the larger tree to keep the structure balanced.

Kruskal's Algorithm:

The edges are sorted by weight.
For each edge, it checks whether including that edge would form a cycle using the union-find data structure.
If it does not form a cycle, the edge is included in the MST.
Main Function: The user inputs the number of vertices and edges, followed by the edges themselves, and the kruskal function is called to compute the MST.

When you run this program, it prompts for the number of vertices and edges, as well as the edges themselves:

Enter the number of vertices: 4
Enter the number of edges: 5
Enter the edges (u v weight):
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4


The output will display the edges included in the Minimum Spanning Tree:

Edges in the Minimum Spanning Tree:
2 -- 3 == 4
0 -- 3 == 5
0 -- 1 == 10


*/