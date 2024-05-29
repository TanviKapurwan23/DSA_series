#include <iostream>
#include <vector>

std::vector<int> compareTriplets(std::vector<int> a, std::vector<int> b) {
    int pointsA = 0;
    int pointsB = 0;
    
    for (int i = 0; i < 3; ++i) {
        if (a[i] > b[i]) {
            pointsA++;
        } else if (a[i] < b[i]) {
            pointsB++;
        }
    }
    
    return std::vector<int>{pointsA, pointsB};
}

int main() {
    // Sample input
    std::vector<int> a = {5, 6, 7};
    std::vector<int> b = {3, 6, 10};

    // Compare triplets
    std::vector<int> result = compareTriplets(a, b);

    // Print the result
    std::cout << "Points for A: " << result[0] << std::endl;
    std::cout << "Points for B: " << result[1] << std::endl;

    return 0;
}
