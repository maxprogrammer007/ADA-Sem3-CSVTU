def print_optimal_parenthesis(s, i, j):
    if i == j:
        print(f"A{i}", end="")
    else:
        print("(", end="")
        print_optimal_parenthesis(s, i, s[i][j])
        print_optimal_parenthesis(s, s[i][j] + 1, j)
        print(")", end="")

def matrix_chain_order(p):
    n = len(p) - 1  # Number of matrices
    m = [[0] * n for _ in range(n)]  # m[i][j] = minimum number of multiplications needed
    s = [[0] * n for _ in range(n)]  # s[i][j] = index of the matrix after which the product is split

    # L is chain length
    for L in range(2, n + 1):  # L = 2 to n
        for i in range(n - L + 1):
            j = i + L - 1
            m[i][j] = float('inf')  # Set to infinity

            # Try all possible splits
            for k in range(i, j):
                q = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1]
                if q < m[i][j]:
                    m[i][j] = q
                    s[i][j] = k  # Store the split point

    print("Minimum number of multiplications:", m[0][n - 1])
    print("Optimal Parenthesization:", end=" ")
    print_optimal_parenthesis(s, 0, n - 1)
    print()  # For a new line

# Example usage
if __name__ == "__main__":
    # Dimensions of matrices
    # For example: A1 (10x30), A2 (30x5), A3 (5x60)
    arr = [10, 30, 5, 60]  # p = [10, 30, 5, 60]
    matrix_chain_order(arr)
