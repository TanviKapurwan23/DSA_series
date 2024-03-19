#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1 = "nincompoop";

    cout << s1.find("com") << endl;
    cout << s1.find("mpoop") << endl;

    return 0;
}