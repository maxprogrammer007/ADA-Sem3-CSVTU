#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve 0/1 Knapsack Problem
int knapsack(int W, int weights[], int values[], int n) {
    int i, w;
    int K[n + 1][W + 1];

    // Build the K table in bottom-up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                K[i][w] = 0; // Base case: no items or weight
            } else if (weights[i - 1] <= w) {
                K[i][w] = max(values[i - 1] + K[i - 1][w - weights[i - 1]], K[i - 1][w]);
            } else {
                K[i][w] = K[i - 1][w];
            }
        }
    }

    return K[n][W]; // Return the maximum value that can be obtained
}

int main() {
    int values[] = {60, 100, 120}; // Values of items
    int weights[] = {10, 20, 30};   // Weights of items
    int W = 50;                     // Maximum weight capacity
    int n = sizeof(values) / sizeof(values[0]); // Number of items

    int max_value = knapsack(W, weights, values, n);
    printf("Maximum value in Knapsack = %d\n", max_value);

    return 0;
}
