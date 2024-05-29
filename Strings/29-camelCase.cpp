#include<iostream>
using namespace std;


int camelCase(string s){
    int wordCount = 1;
    for(char c : s){
        if(isupper(c)){
            wordCount++;
        }
    }
    return wordCount;
}


int main(){
    string testString = "saveChangesInTheWorld";
    int wordCount = camelCase(testString);

    cout<<"The Number of words in camelCase string:"<<wordCount<<endl;
    
    return 0;
}