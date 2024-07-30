#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
    public:
    int mostWordsFound(vector<string>& sentences){
        int maxWord = 0;

        for(const string& sentence : sentences){
            int wordCount = 1;
            for(char c : sentence){
                if(c == ' '){
                    wordCount++;
                }
            }
            maxWord = max(maxWord, wordCount);
        }
        return maxWord;
    }
};
int main(){
   Solution sol;
   vector<string> sentence = {
        "Alice and Bob love LeetCode",
        "I think so too",
        "This is great thanks very much"
   };
   int result = sol.mostWordsFound(sentence);
   cout<<result;



    return 0;
}