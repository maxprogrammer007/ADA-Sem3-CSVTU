use std::cmp::std::i32;

fn print_optimal_parenthesis(s: &Vec<Vec<usize>>, i: usize, j: usize) {
    if i == j {
        print!("A{}", i);
    } else {
        print!("(");
        print_optimal_parenthesis(s, i, s[i][j]);
        print_optimal_parenthesis(s, s[i][j] + 1, j);
        print!(")");
    }
}

fn matrix_chain_order(p: Vec<i32>) {
    let n = p.len() - 1; // Number of matrices
    let mut m = vec![vec![0; n]; n]; // m[i][j] = minimum number of multiplications needed
    let mut s = vec![vec![0; n]; n]; // s[i][j] = index of the matrix after which the product is split

    // L is chain length
    for L in 2..=n { // L = 2 to n
        for i in 0..=n - L {
            let j = i + L - 1;
            m[i][j] = i32::MAX; // Set to maximum value

            // Try all possible splits
            for k in i..j {
                let q = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                if q < m[i][j] {
                    m[i][j] = q;
                    s[i][j] = k; // Store the split point
                }
            }
        }
    }

    println!("Minimum number of multiplications: {}", m[0][n - 1]);
    print!("Optimal Parenthesization: ");
    print_optimal_parenthesis(&s, 0, n - 1);
    println!(); // New line
}

fn main() {
    // Dimensions of matrices
    // For example: A1 (10x30), A2 (30x5), A3 (5x60)
    let arr = vec![10, 30, 5, 60]; // p = [10, 30, 5, 60]
    matrix_chain_order(arr);
}
