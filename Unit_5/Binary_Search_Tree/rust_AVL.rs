#[derive(Debug)]
struct AVLNode {
    key: i32,
    left: Option<Box<AVLNode>>,
    right: Option<Box<AVLNode>>,
    height: i32,
}

#[derive(Debug)]
struct AVLTree {
    root: Option<Box<AVLNode>>,
}

impl AVLTree {
    fn new() -> Self {
        AVLTree { root: None }
    }

    fn insert(&mut self, key: i32) {
        self.root = Self::insert_node(self.root.take(), key);
    }

    fn insert_node(node: Option<Box<AVLNode>>, key: i32) -> Option<Box<AVLNode>> {
        let mut node = match node {
            Some(n) => n,
            None => {
                return Some(Box::new(AVLNode {
                    key,
                    left: None,
                    right: None,
                    height: 1,
                }))
            }
        };

        if key < node.key {
            node.left = Self::insert_node(node.left, key);
        } else {
            node.right = Self::insert_node(node.right, key);
        }

        node.height = 1 + Self::max(Self::get_height(&node.left), Self::get_height(&node.right));

        let balance = Self::get_balance(&node);

        // Left Left Case
        if balance > 1 && key < node.left.as_ref().unwrap().key {
            return Self::right_rotate(node);
        }

        // Right Right Case
        if balance < -1 && key > node.right.as_ref().unwrap().key {
            return Self::left_rotate(node);
        }

        // Left Right Case
        if balance > 1 && key > node.left.as_ref().unwrap().key {
            node.left = Some(Self::left_rotate(node.left.take().unwrap()));
            return Self::right_rotate(node);
        }

        // Right Left Case
        if balance < -1 && key < node.right.as_ref().unwrap().key {
            node.right = Some(Self::right_rotate(node.right.take().unwrap()));
            return Self::left_rotate(node);
        }

        Some(Box::new(node))
    }

    fn left_rotate(node: Box<AVLNode>) -> Option<Box<AVLNode>> {
        let mut y = node.right.unwrap();
        let T2 = y.left.take();

        y.left = Some(node);
        y.left.as_mut().unwrap().right = T2;

        y.left.as_mut().unwrap().height = 1 + Self::max(
            Self::get_height(&y.left.as_ref().unwrap().left),
            Self::get_height(&y.left.as_ref().unwrap().right),
        );
        y.height = 1 + Self::max(Self::get_height(&y.left), Self::get_height(&y.right));

        Some(y)
    }

    fn right_rotate(node: Box<AVLNode>) -> Option<Box<AVLNode>> {
        let mut y = node.left.unwrap();
        let T3 = y.right.take();

        y.right = Some(node);
        y.right.as_mut().unwrap().left = T3;

        y.right.as_mut().unwrap().height = 1 + Self::max(
            Self::get_height(&y.right.as_ref().unwrap().left),
            Self::get_height(&y.right.as_ref().unwrap().right),
        );
        y.height = 1 + Self::max(Self::get_height(&y.left), Self::get_height(&y.right));

        Some(y)
    }

    fn get_height(node: &Option<Box<AVLNode>>) -> i32 {
        node.as_ref().map_or(0, |n| n.height)
    }

    fn get_balance(node: &AVLNode) -> i32 {
        Self::get_height(&node.left) - Self::get_height(&node.right)
    }

    fn max(a: i32, b: i32) -> i32 {
        if a > b { a } else { b }
    }

    fn inorder(&self) -> Vec<i32> {
        let mut result = Vec::new();
        Self::inorder_helper(&self.root, &mut result);
        result
    }

    fn inorder_helper(node: &Option<Box<AVLNode>>, result: &mut Vec<i32>) {
        if let Some(n) = node {
            Self::inorder_helper(&n.left, result);
            result.push(n.key);
            Self::inorder_helper(&n.right, result);
        }
    }
}

// Example usage of AVL Tree
fn main() {
    let mut avl_tree = AVLTree::new();
    let keys = vec![30, 20, 40, 10, 5, 3, 35];

    for &key in &keys {
        avl_tree.insert(key);
    }

    println!("In-order traversal of the AVL tree: {:?}", avl_tree.inorder());
}
