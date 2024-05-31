#include <iostream>
using namespace std;

int saveThePrisoner(int n, int m, int s) {
    // Find the remainder of m divided by n
    int remainder = m % n;
    
    // Adjust the starting position
    int adaajustedPosition = (s + remainder - 1) % n;
    
    // Handle the case when adjusted position is 0
    if (adjustedPosition == 0) {
        return n; // Last prisoner receives the last candy
    } else {
        return adjustedPosition;
    }
}

int main() {
    int n = 5; // Number of prisoners
    int m = 7; // Number of candies
    int s = 2; // Starting position
    
    cout << "Last prisoner to receive candy: " << saveThePrisoner(n, m, s) << endl; // Expected output: 3

    return 0;
}
