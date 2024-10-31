def lcs(X, Y):
    m = len(X)
    n = len(Y)

    # Create a 2D array to store lengths of longest common subsequence
    L = [[0] * (n + 1) for _ in range(m + 1)]

    # Build the LCS table
    for i in range(m + 1):
        for j in range(n + 1):
            if i == 0 or j == 0:
                L[i][j] = 0  # Base case
            elif X[i - 1] == Y[j - 1]:
                L[i][j] = L[i - 1][j - 1] + 1  # Characters match
            else:
                L[i][j] = max(L[i - 1][j], L[i][j - 1])  # Take the maximum

    # Length of LCS is in L[m][n]
    print(f"Length of Longest Common Subsequence: {L[m][n]}")

    # Backtrack to find the LCS string
    index = L[m][n]
    lcs_str = [''] * index  # Create a list to store the LCS string
    lcs_str[index] = ''

    # Start from the bottom-right corner of the LCS table
    i, j = m, n
    while i > 0 and j > 0:
        if X[i - 1] == Y[j - 1]:
            lcs_str[index - 1] = X[i - 1]  # Store the character
            i -= 1
            j -= 1
            index -= 1
        elif L[i - 1][j] > L[i][j - 1]:
            i -= 1
        else:
            j -= 1

    print("Longest Common Subsequence:", ''.join(lcs_str))


if __name__ == "__main__":
    X = "AGGTAB"
    Y = "GXTXAYB"
    lcs(X, Y)
