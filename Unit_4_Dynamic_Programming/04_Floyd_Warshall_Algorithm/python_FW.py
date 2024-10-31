# Define a large constant for infinity
INF = float('inf')

def floyd_warshall(graph):
    # Number of vertices in the graph
    V = len(graph)

    # Initialize the distance matrix
    dist = [[graph[i][j] for j in range(V)] for i in range(V)]

    # Update the distances using the Floyd-Warshall algorithm
    for k in range(V):
        for i in range(V):
            for j in range(V):
                if dist[i][k] + dist[k][j] < dist[i][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]

    # Print the resulting shortest path matrix
    print_solution(dist)

def print_solution(dist):
    print("The following matrix shows the shortest distances between every pair of vertices:")
    for i in range(len(dist)):
        for j in range(len(dist)):
            if dist[i][j] == INF:
                print("INF", end="\t")
            else:
                print(dist[i][j], end="\t")
        print()

# Input graph represented as an adjacency matrix
graph = [
    [0, 3, INF, 7],
    [8, 0, 2, INF],
    [5, INF, 0, 1],
    [2, INF, INF, 0]
]

floyd_warshall(graph)
