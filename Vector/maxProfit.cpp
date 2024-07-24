#include <vector>
#include <iostream>
#include <algorithm> // For min and max functions

using namespace std;

int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0; // Handle empty array case

    int minPrice = INT_MAX; // Initialize minPrice to a very large value
    int maxProfit = 0; // Initialize maxProfit to 0

    for (int price : prices) {
        minPrice = min(minPrice, price); // Update minPrice
        maxProfit = max(maxProfit, price - minPrice); // Update maxProfit
    }

    return maxProfit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int profit = maxProfit(prices);

    cout << "Maximum profit: " << profit << endl;

    return 0;
}
