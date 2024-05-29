#include<iostream>
#include<vector>
using namespace std;

long aVeryBigSum(vector<long> ar){
    long sum  = 0;
    for(long num : ar){
        sum += num;
    }
    return sum;
}

int main(){
    int n;
    cout<<"Enter the number of elements"<<endl;
    cin>>n;

    vector<long> ar(n);

    cout<<"Enter the elements"<<endl;
    for(int i=0; i<n; i++){
        cin>>ar[i];
    }

    long result = aVeryBigSum(ar);
    cout<<"The sum of array is "<<result<<endl;

    return 0;
}