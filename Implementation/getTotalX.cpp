#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to compute the GCD of two numbers
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute the LCM of two numbers
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

// Function to compute the LCM of an array of numbers
int lcmArray(const vector<int>& arr) {
    int result = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        result = lcm(result, arr[i]);
    }
    return result;
}

// Function to compute the GCD of an array of numbers
int gcdArray(const vector<int>& arr) {
    int result = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        result = gcd(result, arr[i]);
    }
    return result;
}

int getTotalX(vector<int> a, vector<int> b) {
    // Find the LCM of array a
    int lcmA = lcmArray(a);

    // Find the GCD of array b
    int gcdB = gcdArray(b);

    // Count the number of multiples of lcmA that evenly divide gcdB
    int count = 0;
    for (int i = lcmA; i <= gcdB; i += lcmA) {
        if (gcdB % i == 0) {
            count++;
        }
    }

    return count;
}

int main() {
    vector<int> a = {2, 4};
    vector<int> b = {16, 32, 96};

    cout << getTotalX(a, b) << endl;  // Output: 3

    return 0;
}
