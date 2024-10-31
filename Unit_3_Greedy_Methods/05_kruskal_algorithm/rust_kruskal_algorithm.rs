use std::cmp::Ordering;
use std::collections::BinaryHeap;

#[derive(Debug, Clone)]
struct Edge {
    u: usize,
    v: usize,
    weight: usize,
}

// Implement Ord and PartialOrd for Edge to allow sorting by weight
impl Ord for Edge {
    fn cmp(&self, other: &Self) -> Ordering {
        other.weight.cmp(&self.weight) // Reverse order for max heap
    }
}

impl PartialOrd for Edge {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

impl PartialEq for Edge {
    fn eq(&self, other: &Self) -> bool {
        self.weight == other.weight
    }
}

impl Eq for Edge {}

fn find(parent: &mut Vec<usize>, i: usize) -> usize {
    if parent[i] != i {
        parent[i] = find(parent, parent[i]); // Path compression
    }
    parent[i]
}

fn union(parent: &mut Vec<usize>, rank: &mut Vec<usize>, x: usize, y: usize) {
    let root_x = find(parent, x);
    let root_y = find(parent, y);

    if root_x != root_y {
        if rank[root_x] < rank[root_y] {
            parent[root_x] = root_y;
        } else if rank[root_x] > rank[root_y] {
            parent[root_y] = root_x;
        } else {
            parent[root_y] = root_x;
            rank[root_x] += 1;
        }
    }
}

fn kruskal(vertices: usize, edges: Vec<Edge>) {
    let mut parent: Vec<usize> = (0..vertices).collect();
    let mut rank: Vec<usize> = vec![0; vertices];
    
    let mut sorted_edges = edges.clone();
    sorted_edges.sort_unstable();

    println!("Edges in the Minimum Spanning Tree:");

    for edge in sorted_edges {
        if find(&mut parent, edge.u) != find(&mut parent, edge.v) {
            println!("{} -- {} == {}", edge.u, edge.v, edge.weight);
            union(&mut parent, &mut rank, edge.u, edge.v);
        }
    }
}

fn main() {
    let mut vertices = String::new();
    let mut edges_input = String::new();

    println!("Enter the number of vertices: ");
    std::io::stdin().read_line(&mut vertices).unwrap();
    let vertices: usize = vertices.trim().parse().unwrap();

    println!("Enter the number of edges: ");
    std::io::stdin().read_line(&mut edges_input).unwrap();
    let num_edges: usize = edges_input.trim().parse().unwrap();

    let mut edges: Vec<Edge> = Vec::new();

    println!("Enter the edges (u v weight):");
    for _ in 0..num_edges {
        let mut edge_input = String::new();
        std::io::stdin().read_line(&mut edge_input).unwrap();
        let parts: Vec<usize> = edge_input.trim().split_whitespace()
            .map(|s| s.parse().unwrap()).collect();
        edges.push(Edge {
            u: parts[0],
            v: parts[1],
            weight: parts[2],
        });
    }

    kruskal(vertices, edges);
}
