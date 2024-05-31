#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> cutTheSticks(vector<int> arr) {
    vector<int> result;

    while (!arr.empty()) {
        // Record the current number of sticks
        result.push_back(arr.size());

        // Find the minimum non-zero stick length
        int min_length = *min_element(arr.begin(), arr.end());

        // Cut each stick by this minimum length and remove zero-length sticks
        vector<int> new_arr;
        for (int stick : arr) {
            stick -= min_length;
            if (stick > 0) {
                new_arr.push_back(stick);
            }
        }

        // Update arr with the new lengths after cutting
        arr = new_arr;
    }

    return result;
}

int main() {
    vector<int> sticks = {5, 4, 4, 2, 2, 8};
    vector<int> result = cutTheSticks(sticks);

    for (int length : result) {
        cout << length << " ";
    }
    cout << endl; // Expected output: 6 4 2 1

    return 0;
}
