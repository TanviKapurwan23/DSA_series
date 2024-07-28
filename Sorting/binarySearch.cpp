/*
Binary Search
Algorithm Steps:

Compare x with the middle element.
If x matches the middle element, return the index.
If x is less than the middle element, repeat the search on the left half.
If x is greater than the middle element, repeat the search on the right half.
If the element is not found, return -1.
*/


#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& arr, int x) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    std::vector<int> arr = {2, 3, 4, 10, 40};
    int x = 10;
    int result = binarySearch(arr, x);
    if (result != -1)
        std::cout << "Element is present at index " << result;
    else
        std::cout << "Element is not present in array";
    return 0;
}
