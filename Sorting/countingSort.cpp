/*

Counting Sort is an integer sorting algorithm that works by counting the number of occurrences of each unique element in the array. It is efficient for sorting arrays with a small range of integer values.

Steps for Counting Sort
Find the Maximum and Minimum Element:

Determine the maximum and minimum values in the array to know the range of the count array.
Initialize the Count Array:

Create a count array of size (maximum value - minimum value + 1), initialized to 0. This array will store the count of each element in the input array.
Store the Count of Each Element:

Iterate through the input array and for each element, increment its corresponding index in the count array.
Accumulate the Counts:

Modify the count array such that each element at each index stores the sum of previous counts. This will help in placing the elements in the correct position in the output array.
Build the Output Array:

Iterate through the input array in reverse order to maintain stability, place each element in its correct position in the output array based on the count array, and decrement the count.
Copy the Output Array to the Input Array:

Copy the sorted elements from the output array back to the input array.

*/

#include <iostream>
#include <vector>
#include <algorithm>

// A utility function to get the maximum value in the array
int getMax(const std::vector<int>& arr) {
    return *max_element(arr.begin(), arr.end());
}

// The main function that implements Counting Sort
void countingSort(std::vector<int>& arr) {
    int n = arr.size();

    // Step 1: Find the maximum element
    int maxVal = getMax(arr);

    // Step 2: Initialize the count array
    std::vector<int> count(maxVal + 1, 0);

    // Step 3: Store the count of each element
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Step 4: Accumulate the counts
    for (int i = 1; i <= maxVal; i++) {
        count[i] += count[i - 1];
    }

    // Step 5: Build the output array
    std::vector<int> output(n);
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Step 6: Copy the output array to the input array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// A utility function to print an array
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    std::cout << "Original array: ";
    printArray(arr);

    countingSort(arr);

    std::cout << "Sorted array: ";
    printArray(arr);
    return 0;
}
