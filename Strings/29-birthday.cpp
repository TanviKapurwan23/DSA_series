#include <iostream>
#include <vector>

int birthday(std::vector<int> s, int d, int m) {
    int count = 0;
    
    for (int i = 0; i <= s.size() - m; ++i) {
        int sum = 0;
        for (int j = 0; j < m; ++j) {
            sum += s[i + j];
        }
        if (sum == d) {
            count++;
        }
    }
    
    return count;
}

int main() {
    // Sample input
    std::vector<int> s = {1, 2, 1, 3, 2};
    int d = 3; // Sum to match
    int m = 2; // Number of consecutive elements

    // Find number of ways to divide the chocolate
    int result = birthday(s, d, m);

    // Print the result
    std::cout << "Number of ways: " << result << std::endl;

    return 0;
}
