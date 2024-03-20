// aaaabbbeeecdddd
// abecd
#include <iostream>
using namespace std;

string removeDup(string s)
{
    if (s.length() == 0)
    {
        return "";
    }

    char ch = s[0]; // store first character
    string ans = removeDup(s.substr(1));

    if (ch == ans[0])    // if same / duplicate
    {
        return ans;
    }
    return (ch + ans);   // no duplicate
}

int main()
{

    cout << removeDup("aaaabbbeeecdddd") << endl;

    return 0;
}