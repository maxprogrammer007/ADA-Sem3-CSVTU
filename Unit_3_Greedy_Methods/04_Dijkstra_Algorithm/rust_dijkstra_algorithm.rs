use std::cmp::Ordering;
use std::collections::BinaryHeap;
use std::usize;

const V: usize = 9; // Number of vertices in the graph

#[derive(Debug, Eq, PartialEq)]
struct Node {
    vertex: usize,
    distance: usize,
}

// Implementing Ord trait for Node to make it usable in BinaryHeap
impl Ord for Node {
    fn cmp(&self, other: &Self) -> Ordering {
        other.distance.cmp(&self.distance) // Reverse order for min-heap
    }
}

// Implementing PartialOrd trait for Node
impl PartialOrd for Node {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

// Function to implement Dijkstra's algorithm
fn dijkstra(graph: &Vec<Vec<usize>>, src: usize) {
    let mut dist = vec![usize::MAX; V]; // Initialize distances to infinity
    let mut spt_set = vec![false; V];    // Shortest Path Tree set

    dist[src] = 0; // Distance from source to itself is always 0

    let mut heap = BinaryHeap::new();
    heap.push(Node {
        vertex: src,
        distance: 0,
    });

    while let Some(Node { vertex: u, distance: d }) = heap.pop() {
        // If this distance is not the shortest recorded distance, skip
        if d > dist[u] {
            continue;
        }

        spt_set[u] = true; // Mark the picked vertex as processed

        for v in 0..V {
            if graph[u][v] != 0 && !spt_set[v] { // Check if there is an edge
                let new_distance = dist[u].saturating_add(graph[u][v]);

                // Only consider this new path if it's better
                if new_distance < dist[v] {
                    dist[v] = new_distance;
                    heap.push(Node {
                        vertex: v,
                        distance: new_distance,
                    });
                }
            }
        }
    }

    // Print the constructed distance array
    println!("Vertex\tDistance from Source");
    for i in 0..V {
        println!("{}\t\t{}", i, dist[i]);
    }
}

fn main() {
    // Adjacency matrix representation of the graph
    let graph: Vec<Vec<usize>> = vec![
        vec![0, 4, 0, 0, 0, 0, 0, 8, 0],
        vec![4, 0, 8, 0, 0, 0, 0, 0, 10],
        vec![0, 8, 0, 7, 0, 4, 0, 0, 2],
        vec![0, 0, 7, 0, 9, 14, 0, 0, 0],
        vec![0, 0, 0, 9, 0, 10, 0, 0, 0],
        vec![0, 0, 4, 14, 10, 0, 2, 0, 0],
        vec![0, 0, 0, 0, 0, 2, 0, 1, 6],
        vec![8, 0, 0, 0, 0, 0, 1, 0, 7],
        vec![0, 10, 2, 0, 0, 0, 6, 7, 0],
    ];

    let source = 0; // Starting node
    dijkstra(&graph, source);
}
