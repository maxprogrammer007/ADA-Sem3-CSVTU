def computeLPSArray(pattern):
    pattern_length = len(pattern)
    lps = [0] * pattern_length  # Longest Prefix Suffix array
    length = 0  # Length of the previous longest prefix suffix
    i = 1

    # Build the LPS array
    while i < pattern_length:
        if pattern[i] == pattern[length]:
            length += 1
            lps[i] = length
            i += 1
        else:
            # Mismatch after length matches
            if length != 0:
                length = lps[length - 1]  # Use the previous lps value
            else:
                lps[i] = 0
                i += 1

    return lps


def KMP(text, pattern):
    text_length = len(text)
    pattern_length = len(pattern)
    lps = computeLPSArray(pattern)  # Preprocess the pattern to create the LPS array

    i = 0  # Index for text
    j = 0  # Index for pattern

    while i < text_length:
        if pattern[j] == text[i]:
            i += 1
            j += 1

        if j == pattern_length:
            print(f"Pattern found at index {i - j}")
            j = lps[j - 1]  # Reset j using lps
        elif i < text_length and pattern[j] != text[i]:
            # Mismatch after j matches
            if j != 0:
                j = lps[j - 1]  # Use the previous lps value
            else:
                i += 1


# Example usage
if __name__ == "__main__":
    text = "ABABDABACDABABCABAB"
    pattern = "ABABCABAB"

    KMP(text, pattern)
