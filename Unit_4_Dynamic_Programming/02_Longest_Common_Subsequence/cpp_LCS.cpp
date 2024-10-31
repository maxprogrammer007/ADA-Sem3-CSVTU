#include <iostream>
#include <vector>
#include <string>

using namespace std;

void lcs(const string &X, const string &Y) {
    int m = X.length();
    int n = Y.length();

    // Create a 2D array to store lengths of longest common subsequence
    vector<vector<int>> L(m + 1, vector<int>(n + 1, 0));

    // Build the LCS table
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
    cout << "Length of Longest Common Subsequence: " << L[m][n] << endl;

    // Backtrack to find the LCS string
    int index = L[m][n];
    string lcs_str(index, '\0'); // Create a string to store the LCS string

    // Start from the bottom-right corner of the LCS table
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

    // Print the LCS string
    cout << "Longest Common Subsequence: " << lcs_str << endl;
}

int main() {
    string X = "AGGTAB";
    string Y = "GXTXAYB";
    lcs(X, Y);
    return 0;
}
