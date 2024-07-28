/*

Radix Sort is a non-comparative integer sorting algorithm. It sorts numbers by processing individual digits. It works by sorting the numbers on each digit, starting from the least significant digit to the most significant digit, using a stable sorting algorithm like Counting Sort.


Steps for Radix Sort
Find the Maximum Number:

Determine the maximum number in the array to know the number of digits.
Initialize the Counting Sort for Each Digit:

Perform Counting Sort for each digit, starting from the least significant digit to the most significant digit.
Sorting by Each Digit:

Use Counting Sort to sort the array based on the current digit.

*/

#include <iostream>
#include <vector>
#include <algorithm>

// A utility function to get the maximum value in an array
int getMax(const std::vector<int>& arr) {
    return *max_element(arr.begin(), arr.end());
}

// A function to do counting sort of arr[] according to the digit represented by exp.
void countingSort(std::vector<int>& arr, int exp) {
    int n = arr.size();
    std::vector<int> output(n); // output array
    int count[10] = {0};

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains the actual
    // position of this digit in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to the current digit
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using Radix Sort
void radixSort(std::vector<int>& arr) {
    // Find the maximum number to know the number of digits
    int m = getMax(arr);

    // Do counting sort for every digit. Note that instead of passing digit
    // number, exp is passed. exp is 10^i where i is the current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countingSort(arr, exp);
}

// A utility function to print an array
void printArray(const std::vector<int>& arr) {
    for (int num : arr)
        std::cout << num << " ";
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    std::cout << "Original array: ";
    printArray(arr);

    radixSort(arr);

    std::cout << "Sorted array: ";
    printArray(arr);
    return 0;
}
