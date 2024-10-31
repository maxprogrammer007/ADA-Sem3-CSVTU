#include <iostream>
#include <vector>
#include <algorithm>

void countingSort(std::vector<int>& arr, int max_value) {
    std::vector<int> count(max_value + 1, 0);
    std::vector<int> output(arr.size());

    for (int num : arr)
        count[num]++;

    for (int i = 1; i <= max_value; i++)
        count[i] += count[i - 1];

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    arr = output;
}

int main() {
    std::vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    int max_value = *max_element(arr.begin(), arr.end());
    countingSort(arr, max_value);
    std::cout << "Sorted array: ";
    for (int num : arr) std::cout << num << " ";
    return 0;
}
