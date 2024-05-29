#include <iostream>

int pageCount(int n, int p) {
    // Calculate the number of turns from the front
    int frontTurns = p / 2;
    
    // Calculate the number of turns from the back
    int backTurns = (n / 2) - (p / 2);
    
    // Return the minimum of the two
    return std::min(frontTurns, backTurns);
}

int main() {
    // Sample input
    int n = 6; // Total number of pages in the book
    int p = 2; // Target page number
    
    // Find the minimum number of page turns
    int result = pageCount(n, p);
    
    // Print the result
    std::cout << "Minimum number of page turns: " << result << std::endl;
    
    return 0;
}
