#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int value) : key(value), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node* root;

    BST() : root(nullptr) {}

    void insert(int key) {
        root = insertNode(root, key);
    }

    Node* insertNode(Node* node, int key) {
        if (!node) return new Node(key);
        if (key < node->key) {
            node->left = insertNode(node->left, key);
        } else if (key > node->key) {
            node->right = insertNode(node->right, key);
        }
        return node;
    }

    void inorder() {
        inorderHelper(root);
        cout << endl;
    }

    void inorderHelper(Node* node) {
        if (node) {
            inorderHelper(node->left);
            cout << node->key << " ";
            inorderHelper(node->right);
        }
    }

    bool search(int key) {
        return searchNode(root, key);
    }

    bool searchNode(Node* node, int key) {
        if (!node) return false;
        if (node->key == key) return true;
        if (key < node->key) return searchNode(node->left, key);
        return searchNode(node->right, key);
    }
};

// Example usage of BST
int main() {
    BST bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    cout << "In-order traversal of the BST: ";
    bst.inorder();

    int key = 40;
    if (bst.search(key)) {
        cout << key << " found in the BST." << endl;
    } else {
        cout << key << " not found in the BST." << endl;
    }

    return 0;
}
