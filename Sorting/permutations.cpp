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

using namespace std;

vector<vector<int>> ans; // global vector

void permute(vector<int> &a, int idx)
{
    if (idx == a.size())
    {
        ans.push_back(a);
        return;
    }
    for (int i = idx; i < a.size(); i++)
    {
        swap(a[i], a[idx]);
        permute(a, idx + 1);
        swap(a[i], a[idx]);
    }
    return;
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n); // vector
    for (auto &i : a)
        cin >> i;

    permute(a, 0);
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