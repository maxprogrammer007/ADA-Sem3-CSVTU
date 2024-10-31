fn counting_sort(arr: &mut [usize], max_value: usize) {
    let mut count = vec![0; max_value + 1];
    let mut output = vec![0; arr.len()];

    for &num in arr.iter() {
        count[num] += 1;
    }

    for i in 1..=max_value {
        count[i] += count[i - 1];
    }

    for &num in arr.iter().rev() {
        output[count[num] - 1] = num;
        count[num] -= 1;
    }

    arr.copy_from_slice(&output);
}

fn main() {
    let mut arr = [4, 2, 2, 8, 3, 3, 1];
    let max_value = *arr.iter().max().unwrap();
    counting_sort(&mut arr, max_value);
    println!("Sorted array: {:?}", arr);
}
