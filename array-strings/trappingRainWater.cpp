#include "bits/stdc++.h"
using namespace std;

int rain_water(vector<int> a)
{
    stack<int> st;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() and a[st.top()] < a[i])
        {
            int cur = st.top();
            st.pop();
            if (st.empty())
            {
                break;
            }
            int diff = i - st.top() - 1;
            ans += (min(a[st.top()], a[i]) - a[cur]) * diff;
        }
        st.push(i);
    }
    return ans;
}

int main()
{
    vector<int> a = {0, 1, 0, 2, 1 , 0, 1 , 3, 2, 1 ,2 , 1};
    cout<<rain_water(a);

    return 0;
}

/*
long long trappingWater(int arr[], int n) {
    if (n <= 2) return 0; // No trapping possible with less than 3 blocks

    // Initialize leftMax and rightMax arrays
    int leftMax[n], rightMax[n];
    leftMax[0] = arr[0];
    for (int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i - 1], arr[i]);
    }
    rightMax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i + 1], arr[i]);
    }

    long long water = 0; // Total trapped water

    // Calculate trapped water for each block
    for (int i = 0; i < n; i++) {
        water += min(leftMax[i], rightMax[i]) - arr[i];
    }

    return water;
}
*/