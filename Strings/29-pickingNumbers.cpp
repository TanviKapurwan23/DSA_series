#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

int pickingNumbers(std::vector<int> a) {
    // Array to count frequency of each number (assuming numbers are between 0 and 99)
    std::array<int, 100> frequency = {0};
    
    // Count the frequency of each number in the input vector
    for (int num : a) {
        frequency[num]++;
    }
    
    int maxLength = 0;
    
    // Calculate the maximum length of subarray where the absolute difference between
    // any two elements is at most 1
    for (int i = 0; i < 99; ++i) {
        int length = frequency[i] + frequency[i + 1];
        if (length > maxLength) {
            maxLength = length;
        }
    }
    
    return maxLength;
}

int main() {
    // Sample input
    std::vector<int> a = {4, 6, 5, 3, 3, 1};
    
    // Find the length of the longest subarray
    int result = pickingNumbers(a);
    
    // Print the result
    std::cout << "Longest subarray length: " << result << std::endl;
    
    return 0;
}
