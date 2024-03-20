#include<iostream>
using namespace std;

void reverse(string s){
    if(s.length() == 0){  // base case
        return;
    }

    string ros = s.substr(1); // ros: rest of the string
    reverse(ros);
    cout<<s[0];
}
int main(){

    reverse("binod");

    return 0;
}