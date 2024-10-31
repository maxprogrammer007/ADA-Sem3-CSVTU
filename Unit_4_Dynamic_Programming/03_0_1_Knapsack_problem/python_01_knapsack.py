def knapsack(W, weights, values, n):
    # Create a 2D array to store the maximum value for each weight limit
    K = [[0 for _ in range(W + 1)] for _ in range(n + 1)]

    # Build the K table in bottom-up manner
    for i in range(n + 1):
        for w in range(W + 1):
            if i == 0 or w == 0:
                K[i][w] = 0  # Base case: no items or weight
            elif weights[i - 1] <= w:
                K[i][w] = max(values[i - 1] + K[i - 1][w - weights[i - 1]], K[i - 1][w])
            else:
                K[i][w] = K[i - 1][w]

    return K[n][W]  # Return the maximum value that can be obtained

if __name__ == "__main__":
    values = [60, 100, 120]  # Values of items
    weights = [10, 20, 30]    # Weights of items
    W = 50                    # Maximum weight capacity
    n = len(values)          # Number of items

    max_value = knapsack(W, weights, values, n)
    print(f"Maximum value in Knapsack = {max_value}")
