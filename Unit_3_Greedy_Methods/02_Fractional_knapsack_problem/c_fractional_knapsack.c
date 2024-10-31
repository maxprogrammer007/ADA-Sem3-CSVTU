#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
struct Item {
    int value;
    int weight;
};

// Comparison function for sorting items based on value-to-weight ratio
int compare(const void* a, const void* b) {
    double r1 = (double)((struct Item*)a)->value / ((struct Item*)a)->weight;
    double r2 = (double)((struct Item*)b)->value / ((struct Item*)b)->weight;
    return (r1 < r2) ? 1 : -1; // Sort in descending order
}

// Function to calculate the maximum value in the knapsack
double fractionalKnapsack(int capacity, struct Item* items, int n) {
    // Sort items by value-to-weight ratio
    qsort(items, n, sizeof(struct Item), compare);

    double maxValue = 0.0; // Maximum value in knapsack
    int currentWeight = 0; // Current weight in knapsack

    // Loop through sorted items
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            // If the item can fit, take it entirely
            currentWeight += items[i].weight;
            maxValue += items[i].value;
        } else {
            // If the item can't fit, take the fractional part
            int remainingWeight = capacity - currentWeight;
            maxValue += items[i].value * ((double)remainingWeight / items[i].weight);
            break;
        }
    }

    return maxValue;
}

int main() {
    int capacity = 50; // Maximum weight capacity of knapsack
    struct Item items[] = { {60, 10}, {100, 20}, {120, 30} };
    int n = sizeof(items) / sizeof(items[0]); // Number of items

    printf("Maximum value in Knapsack = %.2f\n", fractionalKnapsack(capacity, items, n));
    return 0;
}
