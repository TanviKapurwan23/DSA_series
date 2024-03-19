#include <iostream>
#include <string>
#include <algorithm> //to use sort

using namespace std;

int main()
{

    string s = "456789029";

    sort(s.begin(), s.end(), greater<int>());

    cout << s << endl;

    return 0;
}