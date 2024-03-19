#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1 = "nincompoop";
    s1.erase(3, 2);   // 2 character delete
    cout<<s1<<endl;

    return 0;
}