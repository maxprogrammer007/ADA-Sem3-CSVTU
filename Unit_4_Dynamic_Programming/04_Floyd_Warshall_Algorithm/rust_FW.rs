const INF: i32 = i32::MAX; // Define a constant for infinity

fn floyd_warshall(graph: &mut Vec<Vec<i32>>) {
    let v = graph.len();

    // Update the distances using the Floyd-Warshall algorithm
    for k in 0..v {
        for i in 0..v {
            for j in 0..v {
                if graph[i][k] != INF && graph[k][j] != INF {
                    if graph[i][k] + graph[k][j] < graph[i][j] {
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                }
            }
        }
    }
}

fn print_solution(graph: &Vec<Vec<i32>>) {
    println!("The following matrix shows the shortest distances between every pair of vertices:");
    for i in 0..graph.len() {
        for j in 0..graph.len() {
            if graph[i][j] == INF {
                print!("INF\t");
            } else {
                print!("{}\t", graph[i][j]);
            }
        }
        println!();
    }
}

fn main() {
    // Input graph represented as an adjacency matrix
    let mut graph = vec![
        vec![0, 3, INF, 7],
        vec![8, 0, 2, INF],
        vec![5, INF, 0, 1],
        vec![2, INF, INF, 0],
    ];

    floyd_warshall(&mut graph);
    print_solution(&graph);
}
