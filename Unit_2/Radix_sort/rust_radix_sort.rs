fn counting_sort_for_radix(arr: &mut [i32], exp: i32) {
    let n = arr.len();
    let mut output = vec![0; n];
    let mut count = vec![0; 10];

    for &num in arr.iter() {
        let index = (num / exp) % 10;
        count[index as usize] += 1;
    }

    for i in 1..10 {
        count[i] += count[i - 1];
    }

    for &num in arr.iter().rev() {
        let index = (num / exp) % 10;
        output[count[index as usize] as usize - 1] = num;
        count[index as usize] -= 1;
    }

    arr.copy_from_slice(&output);
}

fn radix_sort(arr: &mut [i32]) {
    let max = *arr.iter().max().unwrap();
    let mut exp = 1;
    while max / exp > 0 {
        counting_sort_for_radix(arr, exp);
        exp *= 10;
    }
}

fn main() {
    let mut arr = [170, 45, 75, 90, 802, 24, 2, 66];
    radix_sort(&mut arr);
    println!("Sorted array: {:?}", arr);
}
