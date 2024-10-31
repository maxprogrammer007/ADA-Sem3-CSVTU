#include <stdio.h>
#include <string.h>

// Function to preprocess the pattern and create the LPS array
void computeLPSArray(char* pattern, int* lps, int patternLength) {
    int length = 0; // Length of the previous longest prefix suffix
    lps[0] = 0; // LPS[0] is always 0
    int i = 1;

    // Build the LPS array
    while (i < patternLength) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            // Mismatch after length matches
            if (length != 0) {
                length = lps[length - 1]; // Use the previous lps value
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP algorithm to search for a pattern in a text
void KMP(char* text, char* pattern) {
    int textLength = strlen(text);
    int patternLength = strlen(pattern);
    int lps[patternLength]; // Longest Prefix Suffix array

    // Preprocess the pattern to create the LPS array
    computeLPSArray(pattern, lps, patternLength);

    int i = 0; // Index for text
    int j = 0; // Index for pattern

    while (i < textLength) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == patternLength) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1]; // Reset j using lps
        } else if (i < textLength && pattern[j] != text[i]) {
            // Mismatch after j matches
            if (j != 0) {
                j = lps[j - 1]; // Use the previous lps value
            } else {
                i++;
            }
        }
    }
}

// Example usage
int main() {
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABABCABAB";
    
    KMP(text, pattern);

    return 0;
}
