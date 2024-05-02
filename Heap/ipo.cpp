#include <vector>
#include <queue>
#include <utility>

class Solution {
public:
    int findMaximizedCapital(int k, int w, std::vector<int>& profits, std::vector<int>& capital) {
        int n = profits.size();

        // Create a vector of pairs (profit, capital) for each project
        std::vector<std::pair<int, int>> projects;
        for (int i = 0; i < n; ++i) {
            projects.push_back({profits[i], capital[i]});
        }

        // Sort the projects based on their capital requirements (ascending order)
        std::sort(projects.begin(), projects.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;
        });

        // Create a max heap to store projects based on their profits
        std::priority_queue<int> maxHeap;

        int currentCapital = w;
        int idx = 0;

        // Process k distinct projects or until no projects left
        while (k-- > 0) {
            // Add projects whose capital requirements are within current capital
            while (idx < n && projects[idx].second <= currentCapital) {
                maxHeap.push(projects[idx].first);
                ++idx;
            }

            // If no projects available, break
            if (maxHeap.empty()) break;

            // Select the project with the highest profit from the max heap
            currentCapital += maxHeap.top();
            maxHeap.pop();
        }

        return currentCapital;
    }
};
