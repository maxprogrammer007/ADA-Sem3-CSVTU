#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to compute the Longest Prefix Suffix (LPS) array
vector<int> computeLPSArray(const string &pattern) {
    int pattern_length = pattern.length();
    vector<int> lps(pattern_length, 0);  // Longest Prefix Suffix array
    int length = 0;  // Length of the previous longest prefix suffix
    int i = 1;

    // Build the LPS array
    while (i < pattern_length) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            // Mismatch after length matches
            if (length != 0) {
                length = lps[length - 1];  // Use the previous lps value
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

// Function to implement the KMP algorithm
void KMP(const string &text, const string &pattern) {
    int text_length = text.length();
    int pattern_length = pattern.length();
    vector<int> lps = computeLPSArray(pattern);  // Preprocess the pattern to create the LPS array

    int i = 0;  // Index for text
    int j = 0;  // Index for pattern

    while (i < text_length) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == pattern_length) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];  // Reset j using lps
        } else if (i < text_length && pattern[j] != text[i]) {
            // Mismatch after j matches
            if (j != 0) {
                j = lps[j - 1];  // Use the previous lps value
            } else {
                i++;
            }
        }
    }
}

// Main function to test the KMP algorithm
int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    KMP(text, pattern);

    return 0;
}
