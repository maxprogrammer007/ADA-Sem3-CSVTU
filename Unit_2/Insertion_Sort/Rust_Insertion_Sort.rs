
fn main() {
    let mut arr = [64, 88, 51, 65, 90, 75, 34, 79, 46, 36];
    println!("Unsorted array: {:?}", arr);
    
    insertion_sort(&mut arr);
    
    println!("Sorted array: {:?}", arr);
}

fn insertion_sort(arr: &mut [i32]) {
    let len = arr.len();
    for i in 1..len {
        let key = arr[i];
        let mut j = i as i32 - 1;

        while j >= 0 && arr[j as usize] > key {
            arr[(j + 1) as usize] = arr[j as usize];
            j -= 1;
        }

        arr[(j + 1) as usize] = key;
    }
}