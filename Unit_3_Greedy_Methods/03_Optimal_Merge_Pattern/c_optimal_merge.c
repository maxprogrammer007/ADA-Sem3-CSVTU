#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers (used for sorting)
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b;
}

// Function to calculate the optimal merge cost
int optimal_merge(int sizes[], int n) {
    // Sort the array of sizes
    qsort(sizes, n, sizeof(int), compare);
    
    int total_cost = 0; // Total cost of merging
    int i;

    // Merge files until one file remains
    while (n > 1) {
        // Take the two smallest files
        int merged_size = sizes[0] + sizes[1];
        
        // Update total cost
        total_cost += merged_size;

        // Shift sizes down and insert the merged file
        for (i = 2; i < n; i++) {
            sizes[i - 1] = sizes[i];
        }
        sizes[n - 2] = merged_size; // Insert the merged size
        n--; // Decrease the number of files
        // Sort the array again
        qsort(sizes, n, sizeof(int), compare);
    }

    return total_cost;
}

int main() {
    int sizes[] = {8, 4, 6, 12};
    int n = sizeof(sizes) / sizeof(sizes[0]);
    
    int min_cost = optimal_merge(sizes, n);
    printf("Minimum cost to merge files: %d\n", min_cost);
    return 0;
}
