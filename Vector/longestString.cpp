#include<vector>
#include<iostream>

using namespace std;

string findLongestString(vector<string>& stringList){
    if(stringList.empty()){
        return "";
    }

    string longestString = stringList[0];

    for(int i=1; i<stringList.size(); ++i){
        if(stringList[i].length() > longestString.length()){
            longestString = stringList[i];
        }
    }

    return longestString;

}


int main(){

   vector<string> stringList = {"apple", "mango", "banana"};
   string longest = findLongestString(stringList);

   cout<<longest<<endl; 

    return 0;
}