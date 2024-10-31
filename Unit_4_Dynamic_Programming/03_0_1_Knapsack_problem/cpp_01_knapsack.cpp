#include <iostream>
#include <vector>
using namespace std;

// Function to solve 0/1 Knapsack Problem
int knapsack(int W, const vector<int>& weights, const vector<int>& values, int n) {
    // Create a 2D array to store the maximum value for each weight limit
    vector<vector<int>> K(n + 1, vector<int>(W + 1, 0));

    // Build the K table in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
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
    vector<int> values = {60, 100, 120}; // Values of items
    vector<int> weights = {10, 20, 30};   // Weights of items
    int W = 50;                           // Maximum weight capacity
    int n = values.size();                // Number of items

    int max_value = knapsack(W, weights, values, n);
    cout << "Maximum value in Knapsack = " << max_value << endl;

    return 0;
}
