#include <iostream>
#include <string>
#include <algorithm> //to use sort

using namespace std;

// BIT MANIPULATION

// UPDATE BIT

/*

n = 0101
suppose we need to update bit at position, i = 1 to 1

1<<i = 0010
~0010 = 1101
0101 & 1101 = 0101
1<< i = 0010
0101 | 0010 = 0111

*/

int updateBit(int n, int pos, int value)
{
    int mask = ~(1 << pos);
    n = n & mask;
    return (n | (value << pos));
}

int main()
{
    cout << updateBit(5, 1, 1) << endl;

    return 0;
}