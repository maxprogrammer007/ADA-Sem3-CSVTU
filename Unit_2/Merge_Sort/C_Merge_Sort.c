#include <stdio.h>

// Do subarrays ko merge karne wali function
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary arrays banayenge
    int L[n1], R[n2];

    // Temporary arrays mein data copy karenge
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Temporary arrays ko wapas original array mein merge karenge
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Agar L[] mein kuch elements bache hain to unhe copy karenge
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Agar R[] mein kuch elements bache hain to unhe copy karenge
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort ko implement karne wali function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Pehla aur doosra half ko sort karenge
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Sorted halves ko merge karenge
        merge(arr, left, mid, right);
    }
}

// Array ko print karne ki utility function
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array hai \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array hai \n");
    printArray(arr, arr_size);
    return 0;
}
