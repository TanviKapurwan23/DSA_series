#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int migratoryBirds(std::vector<int> arr) {
    // Map to store frequency of each bird type
    std::unordered_map<int, int> birdCount;
    
    // Count the frequency of each bird type
    for (int bird : arr) {
        birdCount[bird]++;
    }
    
    // Find the bird type with the highest frequency
    int maxCount = 0;
    int minBirdType = INT_MAX;
    for (const auto& pair : birdCount) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            minBirdType = pair.first;
        } else if (pair.second == maxCount && pair.first < minBirdType) {
            minBirdType = pair.first;
        }
    }
    
    return minBirdType;
}

int main() {
    // Sample input
    std::vector<int> arr = {1, 1, 2, 2, 3, 3, 3, 4, 4, 5};
    
    // Find the most frequent bird type
    int result = migratoryBirds(arr);
    
    // Print the result
    std::cout << "Most frequent bird type: " << result << std::endl;
    
    return 0;
}
