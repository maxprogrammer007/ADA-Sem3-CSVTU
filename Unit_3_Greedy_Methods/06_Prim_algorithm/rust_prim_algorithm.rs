use std::collections::BinaryHeap;
use std::cmp::Ordering;

#[derive(Debug)]
struct Edge {
    vertex: usize,
    weight: usize,
}

// Implementing Ord trait for Edge to use it in the priority queue
impl Ord for Edge {
    fn cmp(&self, other: &Self) -> Ordering {
        other.weight.cmp(&self.weight) // Reverse ordering for min-heap
    }
}

// Implementing PartialOrd trait for Edge
impl PartialOrd for Edge {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

// Implementing PartialEq trait for Edge
impl PartialEq for Edge {
    fn eq(&self, other: &Self) -> bool {
        self.weight == other.weight
    }
}

// Implementing Eq trait for Edge
impl Eq for Edge {}

struct Graph {
    num_vertices: usize,
    adj_list: Vec<Vec<Edge>>,
}

impl Graph {
    // Create a new graph
    fn new(vertices: usize) -> Self {
        Graph {
            num_vertices: vertices,
            adj_list: vec![Vec::new(); vertices],
        }
    }

    // Add an edge to the graph
    fn add_edge(&mut self, src: usize, dest: usize, weight: usize) {
        self.adj_list[src].push(Edge { vertex: dest, weight });
        self.adj_list[dest].push(Edge { vertex: src, weight }); // Undirected graph
    }

    // Function to implement Prim's algorithm
    fn prim_mst(&self) {
        let mut key = vec![usize::MAX; self.num_vertices]; // Key values to pick minimum weight edge
        let mut parent = vec![None; self.num_vertices]; // Array to store constructed MST
        let mut mst_set = vec![false; self.num_vertices]; // Track vertices included in MST
        let mut min_heap = BinaryHeap::new(); // Min-heap to pick the minimum weight edge

        key[0] = 0; // Start from the first vertex
        min_heap.push(Edge { vertex: 0, weight: 0 });

        while let Some(Edge { vertex: u, weight: _ }) = min_heap.pop() {
            if mst_set[u] {
                continue; // Skip if already in MST
            }
            mst_set[u] = true; // Add vertex to MST

            for edge in &self.adj_list[u] {
                let v = edge.vertex;
                let weight = edge.weight;

                // Update key and parent if weight is smaller
                if !mst_set[v] && weight < key[v] {
                    key[v] = weight;
                    parent[v] = Some(u);
                    min_heap.push(Edge { vertex: v, weight });
                }
            }
        }

        // Print the constructed MST
        println!("Edge \tWeight");
        for i in 1..self.num_vertices {
            if let Some(p) = parent[i] {
                println!("{} -- {} \t{}", p, i, key[i]);
            }
        }
    }
}

fn main() {
    // Create a graph given in the example
    let mut graph = Graph::new(5);
    graph.add_edge(0, 1, 2);
    graph.add_edge(0, 3, 6);
    graph.add_edge(1, 2, 3);
    graph.add_edge(1, 3, 8);
    graph.add_edge(1, 4, 5);
    graph.add_edge(2, 4, 7);
    graph.add_edge(3, 4, 9);

    // Find the Minimum Spanning Tree
    graph.prim_mst();
}
