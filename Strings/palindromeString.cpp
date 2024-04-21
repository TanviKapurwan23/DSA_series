#include<iostream>
#include<string>
using namespace std;

class Solution{
public:	
	 int isPalindrome(string S) {
        int left = 0;
        int right = S.size() - 1;
        
        while(left < right){
            if(S[left] != S[right]){
                return 0; // not a plaindrome
            }
            left++;
            right--;
        }
        return 1; // Palindrome
    }

};

int main() {
    Solution solution;

    string str1 = "abba";
    cout << solution.isPalindrome(str1) << endl; // Output: 1

    string str2 = "abc";
    cout << solution.isPalindrome(str2) << endl; // Output: 0

    return 0;
}