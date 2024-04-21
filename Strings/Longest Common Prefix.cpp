#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
        {
            return ""; // If the input array is empty, return an empty string
        }

        string prefix = strs[0]; // Initialize prefix with the first string in the array

        for (int i = 1; i < strs.size(); i++)
        {
            int j = 0;
            while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j])
            {
                j++;
            }
            prefix = prefix.substr(0, j); // Update prefix to the common prefix of current string and prefix
            if (prefix.empty())
            {
                break; // If prefix becomes empty, there is no common prefix
            }
        }

        return prefix;
    }
};


int main() {
    Solution solution;

    vector<string> strs1 = {"flower", "flow", "flight"};
    cout << solution.longestCommonPrefix(strs1) << endl; // Output: "fl"

    vector<string> strs2 = {"dog", "racecar", "car"};
    cout << solution.longestCommonPrefix(strs2) << endl; // Output: ""

    return 0;
}