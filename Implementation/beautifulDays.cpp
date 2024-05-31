#include <iostream>
#include <cmath>
using namespace std;

int reverseNumber(int num) {
    int reversed = 0;
    while (num > 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    return reversed;
}

int beautifulDays(int i, int j, int k) {
    int beautifulCount = 0;

    for (int day = i; day <= j; day++) {
        int reverse = reverseNumber(day);
        int absoluteDiff = abs(day - reverse);
        if (absoluteDiff % k == 0) {
            beautifulCount++;
        }
    }

    return beautifulCount;
}

int main() {
    int i = 20;
    int j = 23;
    int k = 6;

    cout << beautifulDays(i, j, k) << endl; // Output should be 2

    return 0;
}
