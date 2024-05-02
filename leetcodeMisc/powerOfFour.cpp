class Solution {
public:
    bool isPowerOfFour(int n) {
        // Check if n is positive and a power of two
        return n > 0 && (n & (n - 1)) == 0 && (n - 1) % 3 == 0;
    }
};