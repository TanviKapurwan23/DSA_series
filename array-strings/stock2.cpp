#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0; // If there are no prices or only one price, profit is 0
        
        int maxProfit = 0;
        int minPrice = prices[0]; // Initialize minimum price to first price
        
        for (int i = 1; i < n; ++i) {
            maxProfit = max(maxProfit, prices[i] - minPrice); // Update maxProfit if selling at current price is profitable
            minPrice = min(minPrice, prices[i]); // Update minPrice if current price is lower than minPrice
        }
        
        return maxProfit;
    }
};
