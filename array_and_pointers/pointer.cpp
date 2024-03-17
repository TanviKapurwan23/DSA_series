#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int *aptr;
    aptr = &a;

    cout << &a << endl;
    cout << aptr << endl;

    cout << *aptr << endl; // dereferencing 10
    *aptr = 20;
    cout << a << endl;

    cout << aptr << endl; // 0x7ffd429e05f4    2000
    aptr++;
    cout << aptr << endl; // 0x7ffd429e05f8    2004

    char ch = 'a';
    char *cptr = &ch;
    cout << cptr << endl; // 3000
    cptr++;
    cout << cptr << endl; // 3001

    return 0;
}
