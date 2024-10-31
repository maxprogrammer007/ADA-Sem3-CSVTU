#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void lcs(const char *X, const char *Y) {
    int m = strlen(X);
    int n = strlen(Y);
    int L[m + 1][n + 1]; // LCS table

    // Building the LCS table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0; // Base case
            } else if (X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1; // Characters match
            } else {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]); // Take the maximum
            }
        }
    }

    // Length of LCS is in L[m][n]
    printf("Length of Longest Common Subsequence: %d\n", L[m][n]);

    // Printing the LCS
    int index = L[m][n];
    char lcs_str[index + 1];
    lcs_str[index] = '\0'; // Null-terminate the LCS string

    // Backtrack to find the LCS string
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs_str[index - 1] = X[i - 1]; // Store the character
            i--;
            j--;
            index--;
        } else if (L[i - 1][j] > L[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("Longest Common Subsequence: %s\n", lcs_str);
}

int main() {
    const char *X = "AGGTAB";
    const char *Y = "GXTXAYB";
    lcs(X, Y);
    return 0;
}
