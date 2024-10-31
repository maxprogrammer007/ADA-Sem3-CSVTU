#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Function to calculate the optimal merge cost
int optimalMerge(vector<int>& sizes) {
    // Min-heap to store file sizes
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Push all file sizes into the min-heap
    for (int size : sizes) {
        minHeap.push(size);
    }

    int totalCost = 0; // Total cost of merging

    // Merge files until one file remains
    while (minHeap.size() > 1) {
        // Take the two smallest files
        int first = minHeap.top(); minHeap.pop();
        int second = minHeap.top(); minHeap.pop();

        // Merge the two files
        int mergedSize = first + second;
        totalCost += mergedSize;

        // Push the merged size back into the min-heap
        minHeap.push(mergedSize);
    }

    return totalCost;
}

int main() {
    vector<int> sizes = {8, 4, 6, 12};

    int minCost = optimalMerge(sizes);
    cout << "Minimum cost to merge files: " << minCost << endl;

    return 0;
}
