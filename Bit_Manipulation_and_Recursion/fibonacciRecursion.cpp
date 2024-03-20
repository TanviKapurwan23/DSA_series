#include <iostream>
using namespace std;

// 0 1 1 2 3 5 8 13 ....
/*
Fib(n) = Fib(n-1) + Fib(n-2)
*/

int fib(int n){
    if(n == 0 || n == 1){    // base case
        return n;
    }

    return fib(n-1) + fib(n-2);
}

int main()
{
    int n;
    cin>>n;

    cout<<fib(n)<<endl;
    return 0;
}