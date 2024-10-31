import sys

V = 9  # Number of vertices in the graph

def min_distance(dist, spt_set):
    """Find the vertex with the minimum distance value."""
    min_dist = sys.maxsize  # Infinite distance
    min_index = -1

    for v in range(V):
        if not spt_set[v] and dist[v] < min_dist:
            min_dist = dist[v]
            min_index = v

    return min_index

def dijkstra(graph, src):
    """Implement Dijkstra's algorithm to find the shortest path."""
    dist = [sys.maxsize] * V  # Initialize distances to infinity
    spt_set = [False] * V      # Shortest Path Tree set

    dist[src] = 0  # Distance from source to itself is always 0

    for _ in range(V - 1):
        u = min_distance(dist, spt_set)  # Pick the minimum distance vertex
        spt_set[u] = True  # Mark the picked vertex as processed

        for v in range(V):
            # Update dist[v] if and only if it is not in spt_set,
            # there is an edge from u to v, and the total weight of
            # the path from src to v through u is smaller than
            # the current value of dist[v]
            if (not spt_set[v] and graph[u][v] and
                    dist[u] != sys.maxsize and
                    dist[u] + graph[u][v] < dist[v]):
                dist[v] = dist[u] + graph[u][v]

    # Print the constructed distance array
    print("Vertex\tDistance from Source")
    for i in range(V):
        print(f"{i}\t\t{dist[i]}")

if __name__ == "__main__":
    # Adjacency matrix representation of the graph
    graph = [
        [0, 4, 0, 0, 0, 0, 0, 8, 0],
        [4, 0, 8, 0, 0, 0, 0, 0, 10],
        [0, 8, 0, 7, 0, 4, 0, 0, 2],
        [0, 0, 7, 0, 9, 14, 0, 0, 0],
        [0, 0, 0, 9, 0, 10, 0, 0, 0],
        [0, 0, 4, 14, 10, 0, 2, 0, 0],
        [0, 0, 0, 0, 0, 2, 0, 1, 6],
        [8, 0, 0, 0, 0, 0, 1, 0, 7],
        [0, 10, 2, 0, 0, 0, 6, 7, 0]
    ]

    source = 0  # Starting node
    dijkstra(graph, source)
