#[derive(Debug)]
struct Item {
    value: i32,
    weight: i32,
}

// Function to calculate value-to-weight ratio
fn get_ratio(item: &Item) -> f64 {
    item.value as f64 / item.weight as f64
}

// Function to calculate the maximum value in the knapsack
fn fractional_knapsack(capacity: i32, items: &mut Vec<Item>) -> f64 {
    // Sort items by value-to-weight ratio in descending order
    items.sort_by(|a, b| get_ratio(b).partial_cmp(&get_ratio(a)).unwrap());

    let mut max_value = 0.0; // Maximum value in knapsack
    let mut current_weight = 0; // Current weight in knapsack

    // Loop through sorted items
    for item in items {
        if current_weight + item.weight <= capacity {
            // If the item can fit, take it entirely
            current_weight += item.weight;
            max_value += item.value as f64;
        } else {
            // If the item can't fit, take the fractional part
            let remaining_weight = capacity - current_weight;
            max_value += item.value as f64 * (remaining_weight as f64 / item.weight as f64);
            break;
        }
    }

    max_value
}

fn main() {
    let capacity = 50; // Maximum weight capacity of knapsack
    let mut items = vec![
        Item { value: 60, weight: 10 },
        Item { value: 100, weight: 20 },
        Item { value: 120, weight: 30 },
    ];

    let max_value = fractional_knapsack(capacity, &mut items);
    println!("Maximum value in Knapsack = {:.2}", max_value);
}
