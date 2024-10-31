import sys

def min_key(key, mst_set):
    """Utility function to find the vertex with the minimum key value."""
    min_value = sys.maxsize
    min_index = -1

    for v in range(len(key)):
        if key[v] < min_value and not mst_set[v]:
            min_value = key[v]
            min_index = v

    return min_index

def prim_mst(graph):
    """Function to implement Prim's algorithm to find the Minimum Spanning Tree."""
    num_vertices = len(graph)
    parent = [-1] * num_vertices  # Array to store constructed MST
    key = [sys.maxsize] * num_vertices  # Key values used to pick the minimum weight edge
    mst_set = [False] * num_vertices  # To represent the set of vertices included in MST

    # Start from the first vertex
    key[0] = 0  # Make key 0 so that this vertex is picked as the first vertex

    for _ in range(num_vertices - 1):
        # Pick the minimum key vertex from the set of vertices not yet included in MST
        u = min_key(key, mst_set)
        mst_set[u] = True  # Add the picked vertex to the MST Set

        # Update key value and parent index of the adjacent vertices
        for v in range(num_vertices):
            # Update key only if graph[u][v] is smaller than key[v]
            if graph[u][v] > 0 and not mst_set[v] and graph[u][v] < key[v]:
                parent[v] = u
                key[v] = graph[u][v]

    # Print the constructed MST
    print("Edge \tWeight")
    for i in range(1, num_vertices):
        print(f"{parent[i]} -- {i} \t{graph[i][parent[i]]}")

if __name__ == "__main__":
    # Adjacency matrix representation of the graph
    graph = [
        [0, 2, 0, 6, 0],
        [2, 0, 3, 8, 5],
        [0, 3, 0, 0, 7],
        [6, 8, 0, 0, 9],
        [0, 5, 7, 9, 0]
    ]

    prim_mst(graph)
