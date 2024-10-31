class AVLNode:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.height = 1  # New node is initially added at leaf

class AVLTree:
    def insert(self, root, key):
        # Perform normal BST insert
        if root is None:
            return AVLNode(key)
        elif key < root.key:
            root.left = self.insert(root.left, key)
        else:
            root.right = self.insert(root.right, key)

        # Update height of this ancestor node
        root.height = 1 + max(self.getHeight(root.left), self.getHeight(root.right))

        # Get the balance factor of this ancestor node to check whether this node became unbalanced
        balance = self.getBalance(root)

        # If this node becomes unbalanced, then there are 4 cases

        # Left Left Case
        if balance > 1 and key < root.left.key:
            return self.rightRotate(root)

        # Right Right Case
        if balance < -1 and key > root.right.key:
            return self.leftRotate(root)

        # Left Right Case
        if balance > 1 and key > root.left.key:
            root.left = self.leftRotate(root.left)
            return self.rightRotate(root)

        # Right Left Case
        if balance < -1 and key < root.right.key:
            root.right = self.rightRotate(root.right)
            return self.leftRotate(root)

        # Return the (unchanged) node pointer
        return root

    def leftRotate(self, z):
        y = z.right
        T2 = y.left

        # Perform rotation
        y.left = z
        z.right = T2

        # Update heights
        z.height = 1 + max(self.getHeight(z.left), self.getHeight(z.right))
        y.height = 1 + max(self.getHeight(y.left), self.getHeight(y.right))

        # Return the new root
        return y

    def rightRotate(self, z):
        y = z.left
        T3 = y.right

        # Perform rotation
        y.right = z
        z.left = T3

        # Update heights
        z.height = 1 + max(self.getHeight(z.left), self.getHeight(z.right))
        y.height = 1 + max(self.getHeight(y.left), self.getHeight(y.right))

        # Return the new root
        return y

    def getHeight(self, node):
        if not node:
            return 0
        return node.height

    def getBalance(self, node):
        if not node:
            return 0
        return self.getHeight(node.left) - self.getHeight(node.right)

    def inorder(self, root):
        return self._inorder(root)

    def _inorder(self, node):
        return self._inorder(node.left) + [node.key] + self._inorder(node.right) if node else []

# Example usage of AVL Tree
avl_tree = AVLTree()
root = None
keys = [30, 20, 40, 10, 5, 3, 35]

for key in keys:
    root = avl_tree.insert(root, key)

print("In-order traversal of the AVL tree:", avl_tree.inorder(root))
