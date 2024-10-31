fn knapsack(w: usize, weights: &[usize], values: &[usize], n: usize) -> usize {
    // Create a 2D vector to store the maximum value for each weight limit
    let mut k = vec![vec![0; w + 1]; n + 1];

    // Build the k table in bottom-up manner
    for i in 0..=n {
        for j in 0..=w {
            if i == 0 || j == 0 {
                k[i][j] = 0; // Base case: no items or weight
            } else if weights[i - 1] <= j {
                k[i][j] = k[i - 1][j].max(values[i - 1] + k[i - 1][j - weights[i - 1]]);
            } else {
                k[i][j] = k[i - 1][j];
            }
        }
    }

    k[n][w] // Return the maximum value that can be obtained
}

fn main() {
    let values = vec![60, 100, 120]; // Values of items
    let weights = vec![10, 20, 30];   // Weights of items
    let w = 50;                       // Maximum weight capacity
    let n = values.len();             // Number of items

    let max_value = knapsack(w, &weights, &values, n);
    println!("Maximum value in Knapsack = {}", max_value);
}
