#include <iostream>
#include <limits>
#include <vector>

using namespace std;

void printOptimalParenthesis(const vector<vector<int>>& s, int i, int j) {
    if (i == j) {
        cout << "A" << i;
    } else {
        cout << "(";
        printOptimalParenthesis(s, i, s[i][j]);
        printOptimalParenthesis(s, s[i][j] + 1, j);
        cout << ")";
    }
}

void matrixChainOrder(const vector<int>& p) {
    int n = p.size() - 1; // Number of matrices
    vector<vector<int>> m(n, vector<int>(n, 0)); // m[i][j] = minimum number of multiplications needed
    vector<vector<int>> s(n, vector<int>(n, 0)); // s[i][j] = index of the matrix after which the product is split

    // L is chain length
    for (int L = 2; L <= n; ++L) { // L = 2 to n
        for (int i = 0; i < n - L + 1; ++i) {
            int j = i + L - 1;
            m[i][j] = numeric_limits<int>::max(); // Set to maximum value

            // Try all possible splits
            for (int k = i; k < j; ++k) {
                int q = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k; // Store the split point
                }
            }
        }
    }

    cout << "Minimum number of multiplications: " << m[0][n - 1] << endl;
    cout << "Optimal Parenthesization: ";
    printOptimalParenthesis(s, 0, n - 1);
    cout << endl;
}

int main() {
    // Dimensions of matrices
    // For example: A1 (10x30), A2 (30x5), A3 (5x60)
    vector<int> arr = {10, 30, 5, 60}; // p = {10, 30, 5, 60}
    matrixChainOrder(arr);
    
    return 0;
}
