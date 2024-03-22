/*
A permutation is a arrnagement of members of a sequence
into a new sequence.
*/

/*
Given an array nums of distinct integers return
all the possible permutations.
you can return the answer in any order.
*/

/*
input: num = [1,2,3]
output: [[1,2,3][1,3,2][2,1,3][2,3,1][3,1,2][3,2,1]]

input: num = [0,1]
output: [[0,1] [1,0]]

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> ans; // global vector

int main()
{
    int n;
    cin >> n;

    vector<int> a(n); // vector
    for (auto &i : a)
        cin >> i;

    sort(a.begin(), a.end());
    do
    {
        ans.push_back(a);
    } while (next_permutation(a.begin(), a.end()));

    for (auto v : ans)
    {
        for (auto i : v)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}

// INPUT
// 3
// 1 2 3

// OUTPUT
// 1 2 3
// 1 3 2
// 2 1 3
// 2 3 1
// 3 2 1
// 3 1 2