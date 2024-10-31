#include <iostream>
using namespace std;

struct AVLNode {
    int key;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int value) : key(value), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
public:
    AVLNode* root;

    AVLTree() : root(nullptr) {}

    void insert(int key) {
        root = insertNode(root, key);
    }

    AVLNode* insertNode(AVLNode* node, int key) {
        if (!node) return new AVLNode(key);
        if (key < node->key) {
            node->left = insertNode(node->left, key);
        } else {
            node->right = insertNode(node->right, key);
        }

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && key < node->left->key) {
            return rightRotate(node);
        }

        // Right Right Case
        if (balance < -1 && key > node->right->key) {
            return leftRotate(node);
        }

        // Left Right Case
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    AVLNode* leftRotate(AVLNode* node) {
        AVLNode* y = node->right;
        AVLNode* T2 = y->left;

        y->left = node;
        node->right = T2;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        return y;
    }

    AVLNode* rightRotate(AVLNode* node) {
        AVLNode* y = node->left;
        AVLNode* T3 = y->right;

        y->right = node;
        node->left = T3;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        return y;
    }

    int getHeight(AVLNode* node) {
        return node ? node->height : 0;
    }

    int getBalance(AVLNode* node) {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    void inorder() {
        inorderHelper(root);
        cout << endl;
    }

    void inorderHelper(AVLNode* node) {
        if (node) {
            inorderHelper(node->left);
            cout << node->key << " ";
            inorderHelper(node->right);
        }
    }
};

// Example usage of AVL Tree
int main() {
    AVLTree avlTree;
    int keys[] = {30, 20, 40, 10, 5, 3, 35};

    for (int key : keys) {
        avlTree.insert(key);
    }

    cout << "In-order traversal of the AVL tree: ";
    avlTree.inorder();

    return 0;
}
