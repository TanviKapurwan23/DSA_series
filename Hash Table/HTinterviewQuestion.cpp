#include<iostream>
#include<vector>

using namespace std;

bool ItemInCommon(vector<int> vect1, vector<int> vect2){
    for(auto i : vect1 ){
        for(auto j : vect2){
            if(i == j) return true;
        }
    }
    return false;

    
}

int main(){

    vector<int> vect1 {1, 2, 5};
    vector<int> vect2 {3, 4, 5};
    cout<<ItemInCommon(vect1, vect2);


    return 0;
}

