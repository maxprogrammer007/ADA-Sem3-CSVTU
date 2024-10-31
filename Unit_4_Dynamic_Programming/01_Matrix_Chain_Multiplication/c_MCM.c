#include <stdio.h>
#include <limits.h>

void printOptimalParenthesis(int i, int j, int n, int* s) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        printOptimalParenthesis(i, *((s + i * n) + j), n, s);
        printOptimalParenthesis(*((s + i * n) + j) + 1, j, n, s);
        printf(")");
    }
}

void matrixChainOrder(int p[], int n) {
    int m[n][n]; // m[i][j] = minimum number of multiplications needed to compute the matrix A[i]...A[j]
    int s[n][n]; // s[i][j] = index of the matrix after which the product is split

    for (int i = 1; i < n; i++) {
        m[i][i] = 0; // Cost is zero when multiplying one matrix
    }

    // L is chain length
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX; // Set to maximum value

            // Try all possible splits
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k; // Store the split point
                }
            }
        }
    }

    printf("Minimum number of multiplications: %d\n", m[1][n - 1]);
    printf("Optimal Parenthesization: ");
    printOptimalParenthesis(1, n - 1, n, (int *)s);
    printf("\n");
}

int main() {
    // Dimensions of matrices
    // For example: A1 (10x30), A2 (30x5), A3 (5x60)
    int arr[] = {10, 30, 5, 60}; // p = [10, 30, 5, 60]
    int size = sizeof(arr) / sizeof(arr[0]);

    matrixChainOrder(arr, size);

    return 0;
}

