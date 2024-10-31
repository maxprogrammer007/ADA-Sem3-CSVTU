use std::collections::BinaryHeap;

fn optimal_merge(sizes: &mut Vec<i32>) -> i32 {
    // Create a max-heap using BinaryHeap and invert the values to use as a min-heap
    let mut min_heap: BinaryHeap<i32> = BinaryHeap::new();

    // Push all file sizes into the min-heap
    for &size in sizes {
        min_heap.push(-size); // Invert to simulate min-heap behavior
    }

    let mut total_cost = 0; // Total cost of merging

    // Merge files until one file remains
    while min_heap.len() > 1 {
        // Take the two smallest files (inverted back to positive)
        let first = -min_heap.pop().unwrap();
        let second = -min_heap.pop().unwrap();

        // Merge the two files
        let merged_size = first + second;
        total_cost += merged_size;

        // Push the merged size back into the min-heap (inverted)
        min_heap.push(-merged_size);
    }

    total_cost
}

fn main() {
    let mut sizes = vec![8, 4, 6, 12];

    let min_cost = optimal_merge(&mut sizes);
    println!("Minimum cost to merge files: {}", min_cost);
}
