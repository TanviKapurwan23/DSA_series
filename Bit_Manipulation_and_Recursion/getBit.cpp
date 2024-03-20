#include <iostream>
#include <string>
#include<algorithm>  //to use sort

using namespace std;

// BIT MANIPULATION

// Get Bit

int getBit(int n, int pos){
    return (n & (1<<pos)!=0);
}

int main()
{
    
    cout<<getBit(5, 2)<<endl;
    
   
   return 0;
}