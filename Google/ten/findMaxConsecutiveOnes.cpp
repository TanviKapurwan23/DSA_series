#include<iostream>
#include<vector>

using namespace std;


class Solution{
    public:
    int findMaxConsecutiveOnes(vector<int>& nums){
       int maxCount = 0;
       int current  = 0;

       for(int i=0; i<nums.size(); i++){
        if(nums[i] == 1){
            current += 1;
            maxCount = max(maxCount, current);
        } else{
           current = 0;
        }
       }
       return maxCount;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    int result = sol.findMaxConsecutiveOnes(nums);

    cout<<result;

    return 0;
}