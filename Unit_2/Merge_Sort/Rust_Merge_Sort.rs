fn merge(arr: &mut [i32], left: usize, mid: usize, right: usize) {
    // Left aur right subarrays ka size nikalenge
    let n1 = mid - left + 1;
    let n2 = right - mid;

    // Temporary arrays banayenge
    let mut L = vec![0; n1];
    let mut R = vec![0; n2];

    // Data ko temporary arrays mein copy karenge
    for i in 0..n1 {
        L[i] = arr[left + i];
    }
    for j in 0..n2 {
        R[j] = arr[mid + 1 + j];
    }

    // Dono subarrays ko merge karenge
    let mut i = 0;
    let mut j = 0;
    let mut k = left;

    while i < n1 && j < n2 {
        if L[i] <= R[j] {
            arr[k] = L[i];
            i += 1;
        } else {
            arr[k] = R[j];
            j += 1;
        }
        k += 1;
    }

    // Agar L[] mein kuch elements bache hain to unhe copy karenge
    while i < n1 {
        arr[k] = L[i];
        i += 1;
        k += 1;
    }

    // Agar R[] mein kuch elements bache hain to unhe copy karenge
    while j < n2 {
        arr[k] = R[j];
        j += 1;
        k += 1;
    }
}

// Merge Sort ko implement karenge
fn merge_sort(arr: &mut [i32], left: usize, right: usize) {
    if left < right {
        let mid = left + (right - left) / 2;

        // Pehla aur doosra half ko sort karenge
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        // Sorted halves ko merge karenge
        merge(arr, left, mid, right);
    }
}

// Array ko print karne ki utility function
fn print_array(arr: &[i32]) {
    for &i in arr {
        print!("{} ", i);
    }
    println!();
}

fn main() {
    let mut arr = [12, 11, 13, 5, 6, 7];

    println!("Given array hai:");
    print_array(&arr);

    merge_sort(&mut arr, 0, arr.len() - 1);

    println!("\nSorted array hai:");
    print_array(&arr);
}
