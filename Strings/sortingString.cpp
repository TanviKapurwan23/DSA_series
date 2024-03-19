#include <iostream>
#include <string>
#include <algorithm> //to use sort

using namespace std;

int main()
{
    string s1 = "poiuytrew";
    sort(s1.begin(), s1.end());
    cout << s1 << endl;
    return 0;
}