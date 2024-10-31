#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// Node of Huffman Tree
struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// Compare class for priority queue to sort nodes by frequency
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Function to generate Huffman codes by traversing the Huffman Tree
void generateCodes(Node* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (!root) return;

    // If it's a leaf node, store the character and its code
    if (!root->left && !root->right) {
        huffmanCodes[root->ch] = code;
    }

    // Traverse the left and right children
    generateCodes(root->left, code + "0", huffmanCodes);
    generateCodes(root->right, code + "1", huffmanCodes);
}

// Function to build the Huffman Tree and return the root
Node* buildHuffmanTree(const vector<char>& characters, const vector<int>& frequencies) {
    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    // Create a leaf node for each character and add it to the min heap
    for (size_t i = 0; i < characters.size(); ++i) {
        minHeap.push(new Node(characters[i], frequencies[i]));
    }

    // Build the Huffman Tree
    while (minHeap.size() > 1) {
        // Remove the two nodes with the lowest frequency
        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();

        // Create a new internal node with combined frequency
        Node* merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;

        // Add the new node back to the heap
        minHeap.push(merged);
    }

    // The remaining node is the root of the Huffman Tree
    return minHeap.top();
}

int main() {
    vector<char> characters = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<int> frequencies = {5, 9, 12, 13, 16, 45};

    // Build Huffman Tree
    Node* root = buildHuffmanTree(characters, frequencies);

    // Generate Huffman Codes
    unordered_map<char, string> huffmanCodes;
    generateCodes(root, "", huffmanCodes);

    // Print Huffman Codes
    for (auto& pair : huffmanCodes) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
