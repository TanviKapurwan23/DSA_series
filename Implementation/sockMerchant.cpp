#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int sockMerchant(int n, vector<int> ar) {
    unordered_map<int, int> sockCount;

    // Count the occurrences of each sock color
    for (int i = 0; i < n; ++i) {
        sockCount[ar[i]]++;
    }

    int pairs = 0;

    // Calculate the number of pairs for each color
    for (const auto& pair : sockCount) {
        pairs += pair.second / 2;
    }

    return pairs;
}

int main() {
    vector<int> socks = {10, 20, 20, 10, 10, 30, 50, 10, 20};
    int n = socks.size();
    cout << sockMerchant(n, socks) << endl;  // Output should be 3

    return 0;
}
