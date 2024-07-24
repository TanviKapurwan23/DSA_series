#include <vector>
#include <iostream>

using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0) return; // Handle empty array

    k %= n; // Normalize k to prevent unnecessary rotations

    vector<int> temp(n);

    // Copy elements to the temporary array
    for (int i = 0; i < n; ++i) {
        temp[(i + k) % n] = nums[i];
    }

    // Copy elements back to the original array
    for (int i = 0; i < n; ++i) {
        nums[i] = temp[i];
    }
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    rotate(nums, k);

    cout << "Array after rotation: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
