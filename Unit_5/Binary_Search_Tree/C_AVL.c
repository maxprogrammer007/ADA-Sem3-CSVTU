#include <stdio.h>
#include <stdlib.h>

// Node structure for AVL Tree
struct AVLNode {
    int key;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
};

// Function to create a new AVL node
struct AVLNode* createAVLNode(int key) {
    struct AVLNode* newNode = (struct AVLNode*)malloc(sizeof(struct AVLNode));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    newNode->height = 1; // New node is initially added at leaf
    return newNode;
}

// Function to get the height of the tree
int height(struct AVLNode* N) {
    if (N == NULL) return 0;
    return N->height;
}

// Function to get the balance factor of the node
int getBalance(struct AVLNode* N) {
    if (N == NULL) return 0;
    return height(N->left) - height(N->right);
}

// Right rotate subtree rooted with y
struct AVLNode* rightRotate(struct AVLNode* y) {
    struct AVLNode* x = y->left;
    struct AVLNode* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));

    // Return new root
    return x;
}

// Left rotate subtree rooted with x
struct AVLNode* leftRotate(struct AVLNode* x) {
    struct AVLNode* y = x->right;
    struct AVLNode* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));

    // Return new root
    return y;
}

// Function to insert a key in the AVL tree
struct AVLNode* insertAVL(struct AVLNode* node, int key) {
    // Normal BST insertion
    if (node == NULL) return createAVLNode(key);
    if (key < node->key) {
        node->left = insertAVL(node->left, key);
    } else if (key > node->key) {
        node->right = insertAVL(node->right, key);
    } else { // Duplicate keys are not allowed
        return node;
    }

    // Update height of this ancestor node
    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));

    // Get the balance factor of this ancestor node to check whether this node became unbalanced
    int balance = getBalance(node);

    // If this node becomes unbalanced, then there are 4 cases

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

    // Return the (unchanged) node pointer
    return node;
}

// Function to perform in-order traversal of AVL tree
void inorderAVL(struct AVLNode* root) {
    if (root != NULL) {
        inorderAVL(root->left);
        printf("%d ", root->key);
        inorderAVL(root->right);
    }
}

// Main function to demonstrate AVL Tree operations
int main() {
    struct AVLNode* root = NULL;
    root = insertAVL(root, 30);
    root = insertAVL(root, 20);
    root = insertAVL(root, 40);
    root = insertAVL(root, 10);
    root = insertAVL(root, 5);
    root = insertAVL(root, 3);
    root = insertAVL(root, 35);

    printf("In-order traversal of the AVL tree: ");
    inorderAVL(root);
    printf("\n");

    return 0;
}
