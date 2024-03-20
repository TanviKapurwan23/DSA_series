#include <iostream>
#include <string>

using namespace std;

// BIT MANIPULATION

// clear BIT

/*

n = 0101
suppose we need to clear bit at position, i=2
1<<i = 0100
~0100 = 1011
0101 & 1011 = 0001

*/

int clearBit(int n, int pos)
{
    int mask = ~(1 << pos);
    return (n & mask);
}

int main()
{
    cout << clearBit(5, 2) << endl;

    return 0;
}