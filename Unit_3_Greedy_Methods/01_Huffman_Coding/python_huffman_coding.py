import heapq

# Node class for the Huffman Tree
class Node:
    def __init__(self, char, freq):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None

    # Overriding __lt__ to compare nodes based on frequency
    def __lt__(self, other):
        return self.freq < other.freq

# Function to print the Huffman codes by traversing the Huffman Tree
def print_codes(root, code=""):
    if root is None:
        return

    # If it's a leaf node, print the character and its code
    if root.char is not None:
        print(f"{root.char}: {code}")

    # Traverse the left and right children
    print_codes(root.left, code + "0")
    print_codes(root.right, code + "1")

# Function to build the Huffman Tree and print codes
def huffman_codes(characters, frequencies):
    # Create a priority queue (min-heap) and insert all characters with frequencies
    heap = [Node(characters[i], frequencies[i]) for i in range(len(characters))]
    heapq.heapify(heap)

    # Iterate until only one node remains in the heap (root of Huffman Tree)
    while len(heap) > 1:
        # Remove the two nodes with the lowest frequency
        left = heapq.heappop(heap)
        right = heapq.heappop(heap)

        # Create a new internal node with these two nodes as children and their sum as the frequency
        merged = Node(None, left.freq + right.freq)
        merged.left = left
        merged.right = right

        # Insert the new node back into the heap
        heapq.heappush(heap, merged)

    # The remaining node is the root of the Huffman Tree
    root = heapq.heappop(heap)
    
    # Print Huffman codes by traversing the tree
    print_codes(root)

# Test data
characters = ['a', 'b', 'c', 'd', 'e', 'f']
frequencies = [5, 9, 12, 13, 16, 45]

# Generate Huffman Codes
huffman_codes(characters, frequencies)



'''
Explanation
Node Class: The Node class represents a node in the Huffman Tree. It contains the character, frequency, and pointers to left and right children.

print_codes Function: This function recursively traverses the Huffman Tree to print the codes for each character.

huffman_codes Function: This function builds the Huffman Tree by:
    Creating nodes for each character and frequency.
    Using a min-heap (priority queue) to always merge the two nodes with the lowest frequency.
    Merging nodes until only the root node remains.

Example Output:
When you run the code with the provided test data, it should output something like this (note: the exact codes may vary based on frequency and tree structure):

f: 0
c: 100
d: 101
a: 1100
b: 1101
e: 111

Each character is mapped to a binary code based on its position in the Huffman Tree. Characters with higher frequencies tend to have shorter codes.
'''