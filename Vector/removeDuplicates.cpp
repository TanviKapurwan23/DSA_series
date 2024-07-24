#include<iostream>
#include<vector>

using namespace std;

int removeDuplicates(vector<int>& nums){
    if(nums.empty()){
        return 0;
    }

    int write = 1;

    for(int read=1; read<nums.size() ; read++){
        if(nums[read] != nums[read - 1]){
            nums[write] = nums[read];
            write++;
        }
    }

    return write;


}

int main(){
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5};
    int length = removeDuplicates(nums);

    cout<<length<<endl;

    cout<<"Array after removing duplicates"<<endl;

    for(int i=0; i<length; i++){
        cout<<nums[i]<<endl;
    }

    return 0;
}