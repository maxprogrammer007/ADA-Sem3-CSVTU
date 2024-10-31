fn lcs(x: &str, y: &str) {
    let m = x.len();
    let n = y.len();
    
    // Create a 2D vector to store lengths of longest common subsequence
    let mut l: Vec<Vec<usize>> = vec![vec![0; n + 1]; m + 1];

    // Build the LCS table
    for i in 0..=m {
        for j in 0..=n {
            if i == 0 || j == 0 {
                l[i][j] = 0; // Base case
            } else if x.as_bytes()[i - 1] == y.as_bytes()[j - 1] {
                l[i][j] = l[i - 1][j - 1] + 1; // Characters match
            } else {
                l[i][j] = std::cmp::max(l[i - 1][j], l[i][j - 1]); // Take the maximum
            }
        }
    }

    // Length of LCS is in l[m][n]
    println!("Length of Longest Common Subsequence: {}", l[m][n]);

    // Backtrack to find the LCS string
    let mut index = l[m][n];
    let mut lcs_str = vec!['\0'; index]; // Create a vector to store the LCS string

    // Start from the bottom-right corner of the LCS table
    let mut i = m;
    let mut j = n;

    while i > 0 && j > 0 {
        if x.as_bytes()[i - 1] == y.as_bytes()[j - 1] {
            lcs_str[index - 1] = x.as_bytes()[i - 1] as char; // Store the character
            i -= 1;
            j -= 1;
            index -= 1;
        } else if l[i - 1][j] > l[i][j - 1] {
            i -= 1;
        } else {
            j -= 1;
        }
    }

    // Print the LCS string
    println!("Longest Common Subsequence: {}", lcs_str.iter().collect::<String>());
}

fn main() {
    let x = "AGGTAB";
    let y = "GXTXAYB";
    lcs(x, y);
}
