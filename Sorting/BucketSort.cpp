// Steps for Bucket Sort Algorithm

// Initialization:

// Create an array of empty buckets.
// Scatter:

// Go through the original array and put each element in its appropriate bucket.
// Sort Individual Buckets:

// Sort each bucket using a different sorting algorithm (often Insertion Sort is used for simplicity and efficiency with small data sets).
// Gather:

// Concatenate all the sorted buckets back into the original array.


#include <iostream>
#include <vector>
#include <algorithm>

// A utility function to print an array
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Bucket Sort function for integer input
void bucketSort(std::vector<int>& arr) {
    int n = arr.size();
    if (n <= 0) return;

    // Step 1: Find the maximum element to determine the range
    int maxVal = *std::max_element(arr.begin(), arr.end());

    // Step 2: Create empty buckets
    std::vector<std::vector<int>> buckets(n);

    // Step 3: Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (arr[i] * n) / (maxVal + 1); // Adjusting index to range [0, n-1]
        buckets[bucketIndex].push_back(arr[i]);
    }

    // Step 4: Sort individual buckets
    for (int i = 0; i < n; i++) {
        std::sort(buckets[i].begin(), buckets[i].end());
    }

    // Step 5: Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    std::vector<int> arr = {54, 46, 83, 66, 95, 92, 43};
    std::cout << "Original array: ";
    printArray(arr);

    bucketSort(arr);

    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
