#include <string>

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        int carry = 0; // Variable to store the carry during addition
        std::string result; // String to store the result
        
        // Start from the least significant digit and move towards the most significant digit
        int i = a.size() - 1;
        int j = b.size() - 1;
        
        // Loop until both strings are exhausted and there's no carry left
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry; // Initialize sum with the carry
            
            // Add the corresponding digits from 'a' and 'b' if they exist
            if (i >= 0) {
                sum += a[i--] - '0'; // Convert char to int by subtracting '0'
            }
            if (j >= 0) {
                sum += b[j--] - '0'; // Convert char to int by subtracting '0'
            }
            
            // Append the least significant digit of the sum to the result string
            result += (sum % 2) + '0'; // Convert int to char by adding '0'
            
            // Calculate the carry for the next iteration
            carry = sum / 2;
        }
        
        // Reverse the result string to get the correct binary sum
        std::reverse(result.begin(), result.end());
        
        return result;
    }
};
