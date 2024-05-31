#include <iostream>
#include <vector>
using namespace std;

int getMoneySpent(vector<int> keyboards, vector<int> drives, int b) {
    int maxSpent = -1; // Initialize to -1 to handle the case where no combination is affordable

    // Iterate through each keyboard price
    for (int i = 0; i < keyboards.size(); ++i) {
        // Iterate through each drive price
        for (int j = 0; j < drives.size(); ++j) {
            int totalCost = keyboards[i] + drives[j];

            // If the total cost is within the budget and is greater than the current maxSpent
            if (totalCost <= b && totalCost > maxSpent) {
                maxSpent = totalCost;
            }
        }
    }

    return maxSpent;
}

int main() {
    vector<int> keyboards = {40, 50, 60};
    vector<int> drives = {5, 8, 12};
    int budget = 60;

    int result = getMoneySpent(keyboards, drives, budget);
    cout << result << endl; // Output should be 58

    return 0;
}
