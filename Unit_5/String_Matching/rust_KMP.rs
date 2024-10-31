fn compute_lps_array(pattern: &str) -> Vec<usize> {
    let pattern_length = pattern.len();
    let mut lps = vec![0; pattern_length]; // Longest Prefix Suffix array
    let mut length = 0; // Length of the previous longest prefix suffix
    let mut i = 1;

    // Build the LPS array
    while i < pattern_length {
        if pattern.as_bytes()[i] == pattern.as_bytes()[length] {
            length += 1;
            lps[i] = length;
            i += 1;
        } else {
            // Mismatch after length matches
            if length != 0 {
                length = lps[length - 1]; // Use the previous lps value
            } else {
                lps[i] = 0;
                i += 1;
            }
        }
    }

    lps
}

fn kmp(text: &str, pattern: &str) {
    let text_length = text.len();
    let pattern_length = pattern.len();
    let lps = compute_lps_array(pattern); // Preprocess the pattern to create the LPS array

    let mut i = 0; // Index for text
    let mut j = 0; // Index for pattern

    while i < text_length {
        if pattern.as_bytes()[j] == text.as_bytes()[i] {
            i += 1;
            j += 1;
        }

        if j == pattern_length {
            println!("Pattern found at index {}", i - j);
            j = lps[j - 1]; // Reset j using lps
        } else if i < text_length && pattern.as_bytes()[j] != text.as_bytes()[i] {
            // Mismatch after j matches
            if j != 0 {
                j = lps[j - 1]; // Use the previous lps value
            } else {
                i += 1;
            }
        }
    }
}

fn main() {
    let text = "ABABDABACDABABCABAB";
    let pattern = "ABABCABAB";

    kmp(text, pattern);
}
