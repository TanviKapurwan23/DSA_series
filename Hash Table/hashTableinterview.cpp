#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

bool ItemInCommon(vector<int> vect1, vector<int> vect2){
    unordered_map<int, bool> myMap;

    for(auto i : vect1 ){
        myMap.insert({i, true});
    }

    for(auto j : vect2){
        if(myMap[j]) return true;
    }
    return false;
    
}

int main(){

    vector<int> vect1 {1, 2, 5};
    vector<int> vect2 {3, 4, 5};
    cout<<ItemInCommon(vect1, vect2);


    return 0;
}

