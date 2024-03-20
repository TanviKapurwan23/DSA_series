#include <iostream>
#include <string>
#include<algorithm>  //to use sort

using namespace std;

// BIT MANIPULATION

// SET BIT

/*

n = 0101
suppose we need to set bit at position, i=1
1<<i = 0010
0101 | 0010 = 0111


*/

int setBit(int n, int pos){
    return (n | (1<<pos));
}
int main()
{
   cout<<setBit(5, 1)<<endl;
   
    
   return 0;
}