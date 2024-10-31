#[derive(Debug)]
struct Node {
    key: i32,
    left: Option<Box<Node>>,
    right: Option<Box<Node>>,
}

#[derive(Debug)]
struct BST {
    root: Option<Box<Node>>,
}

impl BST {
    fn new() -> Self {
        BST { root: None }
    }

    fn insert(&mut self, key: i32) {
        self.root = Self::insert_node(self.root.take(), key);
    }

    fn insert_node(node: Option<Box<Node>>, key: i32) -> Option<Box<Node>> {
        if let Some(mut n) = node {
            if key < n.key {
                n.left = Self::insert_node(n.left, key);
            } else if key > n.key {
                n.right = Self::insert_node(n.right, key);
            }
            Some(n)
        } else {
            Some(Box::new(Node {
                key,
                left: None,
                right: None,
            }))
        }
    }

    fn inorder(&self) -> Vec<i32> {
        let mut result = Vec::new();
        Self::inorder_helper(&self.root, &mut result);
        result
    }

    fn inorder_helper(node: &Option<Box<Node>>, result: &mut Vec<i32>) {
        if let Some(n) = node {
            Self::inorder_helper(&n.left, result);
            result.push(n.key);
            Self::inorder_helper(&n.right, result);
        }
    }

    fn search(&self, key: i32) -> bool {
        Self::search_node(&self.root, key)
    }

    fn search_node(node: &Option<Box<Node>>, key: i32) -> bool {
        match node {
            Some(n) if n.key == key => true,
            Some(n) if key < n.key => Self::search_node(&n.left, key),
            Some(n) => Self::search_node(&n.right, key),
            None => false,
        }
    }
}

// Example usage of BST
fn main() {
    let mut bst = BST::new();
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    println!("In-order traversal of the BST: {:?}", bst.inorder());

    let key = 40;
    if bst.search(key) {
        println!("{} found in the BST.", key);
    } else {
        println!("{} not found in the BST.", key);
    }
}
