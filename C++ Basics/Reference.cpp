#include<iostream>
using namespace std;

int main(){
    int a = 10;   //  a = rajendra   full name
    int &r = a;  // r = raj         nickname
    
    cout<<a<<endl;
    cout<<r<<endl;
    
    int b = 30;
    r = b;
    
    cout<<a<<endl;
    cout<<r<<endl;
    
    
    
    return 0;
}
