#include<iostream>
#include <vector>

class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int n = gas.size();

        int totalGas = 0, totalCost = 0;
        int startIdx = 0, tank = 0;

        for (int i = 0; i < n; i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            tank += gas[i] - cost[i];

            if (tank < 0) {  // If the tank becomes negative, reset startIdx and tank
                startIdx = i + 1;
                tank = 0;
            }
        }

        // If totalGas is less than totalCost, there's no solution
        if (totalGas < totalCost) {
            return -1;
        }

        return startIdx;
    }
};
int main() {
    std::vector<int> gas = {1, 2, 3, 4, 5};
    std::vector<int> cost = {3, 4, 5, 1, 2};
    Solution sol;
    int result = sol.canCompleteCircuit(gas, cost);
    std::cout << result << std::endl;  // Output: 3
    return 0;
}
