class Edge:
    def __init__(self, u, v, weight):
        self.u = u
        self.v = v
        self.weight = weight

def find(parent, i):
    if parent[i] != i:
        parent[i] = find(parent, parent[i])  # Path compression
    return parent[i]

def union(parent, rank, x, y):
    rootX = find(parent, x)
    rootY = find(parent, y)

    if rootX != rootY:
        if rank[rootX] < rank[rootY]:
            parent[rootX] = rootY
        elif rank[rootX] > rank[rootY]:
            parent[rootY] = rootX
        else:
            parent[rootY] = rootX
            rank[rootX] += 1

def kruskal(vertices, edges):
    edges.sort(key=lambda edge: edge.weight)  # Sort edges by weight

    parent = [i for i in range(vertices)]
    rank = [0] * vertices

    print("Edges in the Minimum Spanning Tree:")
    mst_weight = 0

    for edge in edges:
        if find(parent, edge.u) != find(parent, edge.v):
            print(f"{edge.u} -- {edge.v} == {edge.weight}")
            union(parent, rank, edge.u, edge.v)
            mst_weight += edge.weight

    return mst_weight

def main():
    vertices = int(input("Enter the number of vertices: "))
    edges = []

    num_edges = int(input("Enter the number of edges: "))
    print("Enter the edges (u v weight):")
    for _ in range(num_edges):
        u, v, weight = map(int, input().split())
        edges.append(Edge(u, v, weight))

    kruskal(vertices, edges)

if __name__ == "__main__":
    main()
