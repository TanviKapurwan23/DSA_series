#include<iostream>
#include <vector>

class Solution
{
public:
    int maxProfit(std::vector<int> &prices)
    {
        int n = prices.size();
        if (n <= 1)
            return 0; // If there are less than 2 days, no profit can be made

        int maxProfit = 0;
        int minPrice = prices[0]; // Initialize the minimum price as the price on day 1

        for (int i = 1; i < n; ++i)
        {
            // Calculate the profit if we sell on the current day
            int currentProfit = prices[i] - minPrice;
            // Update the maximum profit if the current profit is higher
            maxProfit = std::max(maxProfit, currentProfit);
            // Update the minimum price if the current price is lower
            minPrice = std::min(minPrice, prices[i]);
        }

        return maxProfit;
    }
};

int main() {
    std::vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    Solution sol;
    int maxProfit1 = sol.maxProfit(prices1);
    std::cout << "Max Profit 1: " << maxProfit1 << std::endl;

    std::vector<int> prices2 = {7, 6, 4, 3, 1};
    int maxProfit2 = sol.maxProfit(prices2);
    std::cout << "Max Profit 2: " << maxProfit2 << std::endl;

    return 0;
}
