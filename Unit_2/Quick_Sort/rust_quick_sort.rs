fn quick_sort(arr: &mut [i32]) {
    if arr.len() <= 1 {
        return;
    }
    let pivot = partition(arr);
    quick_sort(&mut arr[0..pivot]);
    quick_sort(&mut arr[pivot + 1..]);
}

fn partition(arr: &mut [i32]) -> usize {
    let pivot_index = arr.len() - 1;
    let mut i = 0;
    for j in 0..pivot_index {
        if arr[j] < arr[pivot_index] {
            arr.swap(i, j);
            i += 1;
        }
    }
    arr.swap(i, pivot_index);
    i
}

fn main() {
    let mut arr = [10, 7, 8, 9, 1, 5];
    quick_sort(&mut arr);
    println!("Sorted array: {:?}", arr);
}
