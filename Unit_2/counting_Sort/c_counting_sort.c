#include <stdio.h>
#include <string.h>

void countingSort(int arr[], int n, int max) {
    int count[max + 1];
    int output[n];
    
    memset(count, 0, sizeof(count));
    
    for (int i = 0; i < n; i++)
        count[arr[i]]++;
    
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];
    
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = 8;  // Assumes the maximum value in the array is known
    countingSort(arr, n, max);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}
