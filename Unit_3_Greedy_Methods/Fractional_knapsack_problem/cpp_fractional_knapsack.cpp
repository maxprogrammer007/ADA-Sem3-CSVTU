#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure for items
struct Item {
    int value, weight;

    // Constructor
    Item(int v, int w) : value(v), weight(w) {}
};

// Comparison function to sort items by value-to-weight ratio
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Function to calculate the maximum value in the knapsack
double fractionalKnapsack(int W, vector<Item>& items) {
    // Sort items by value-to-weight ratio
    sort(items.begin(), items.end(), compare);

    double maxValue = 0.0;  // Maximum value in knapsack
    int currentWeight = 0;  // Current weight in knapsack

    // Loop through the sorted items
    for (auto& item : items) {
        if (currentWeight + item.weight <= W) {
            // If the item can fit in the knapsack, take it all
            currentWeight += item.weight;
            maxValue += item.value;
        } else {
            // If the item can't fit, take the fractional part
            int remainingWeight = W - currentWeight;
            maxValue += item.value * ((double)remainingWeight / item.weight);
            break;
        }
    }

    return maxValue;
}

int main() {
    int W = 50;  // Maximum weight capacity of knapsack
    vector<Item> items = { {60, 10}, {100, 20}, {120, 30} };

    cout << "Maximum value in Knapsack = " << fractionalKnapsack(W, items) << endl;
    return 0;
}
