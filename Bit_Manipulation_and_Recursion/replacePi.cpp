#include<iostream>
using namespace std;

void replacePi(string s){

  if(s.length() == 0){
    return;    // base case
  }

  if(s[0] == 'p' && s[1] == 'i'){
    cout<<"3.14";
    replacePi(s.substr(2));  // after pi
  }
  else{
    cout<<s[0];
    replacePi(s.substr(1));  // after 1 character
  }
}
int main(){

    replacePi("pipppiiipi");

    return 0;
}