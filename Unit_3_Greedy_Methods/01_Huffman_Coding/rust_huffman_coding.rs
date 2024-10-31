use std::collections::{BinaryHeap, HashMap};
use std::cmp::Ordering;
use std::rc::Rc;
use std::cell::RefCell;

// Define the Huffman Tree Node
#[derive(Debug, Clone)]
struct Node {
    character: Option<char>,
    frequency: u32,
    left: Option<Rc<RefCell<Node>>>,
    right: Option<Rc<RefCell<Node>>>,
}

// Implement PartialEq and Eq for Node to make it usable in BinaryHeap
impl PartialEq for Node {
    fn eq(&self, other: &Self) -> bool {
        self.frequency == other.frequency
    }
}

impl Eq for Node {}

// Implement Ord and PartialOrd for Node to allow min-heap behavior in BinaryHeap
impl Ord for Node {
    fn cmp(&self, other: &Self) -> Ordering {
        other.frequency.cmp(&self.frequency)
    }
}

impl PartialOrd for Node {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

// Function to build the Huffman Tree
fn build_huffman_tree(characters: &[char], frequencies: &[u32]) -> Rc<RefCell<Node>> {
    let mut heap = BinaryHeap::new();

    // Insert all characters into the heap as individual nodes
    for i in 0..characters.len() {
        let node = Node {
            character: Some(characters[i]),
            frequency: frequencies[i],
            left: None,
            right: None,
        };
        heap.push(Rc::new(RefCell::new(node)));
    }

    // Build the Huffman Tree
    while heap.len() > 1 {
        // Extract two nodes with the lowest frequency
        let left = heap.pop().unwrap();
        let right = heap.pop().unwrap();

        // Create a new internal node with the combined frequency
        let merged = Node {
            character: None,
            frequency: left.borrow().frequency + right.borrow().frequency,
            left: Some(left),
            right: Some(right),
        };

        // Insert the new node back into the heap
        heap.push(Rc::new(RefCell::new(merged)));
    }

    // The remaining node is the root of the Huffman Tree
    heap.pop().unwrap()
}

// Function to generate Huffman Codes by traversing the Huffman Tree
fn generate_codes(node: &Option<Rc<RefCell<Node>>>, code: String, codes: &mut HashMap<char, String>) {
    if let Some(n) = node {
        let node_ref = n.borrow();

        // If it’s a leaf node, store the character and its code
        if let Some(character) = node_ref.character {
            codes.insert(character, code);
        } else {
            // Traverse left with code "0"
            generate_codes(&node_ref.left, format!("{}0", code), codes);
            // Traverse right with code "1"
            generate_codes(&node_ref.right, format!("{}1", code), codes);
        }
    }
}

fn main() {
    let characters = vec!['a', 'b', 'c', 'd', 'e', 'f'];
    let frequencies = vec![5, 9, 12, 13, 16, 45];

    // Build the Huffman Tree
    let root = build_huffman_tree(&characters, &frequencies);

    // Generate the Huffman Codes
    let mut codes = HashMap::new();
    generate_codes(&Some(root), String::new(), &mut codes);

    // Print the Huffman Codes
    for (character, code) in &codes {
        println!("{}: {}", character, code);
    }
}

 