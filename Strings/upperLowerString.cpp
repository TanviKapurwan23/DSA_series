#include <iostream>
#include <string>
#include <algorithm> //to use sort

using namespace std;

int main()
{

    string str = "sjndfjsnfsd";

    cout << 'a' - 'A' << endl;

    // convert into upper case

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
    }
    cout << str << endl;
    ;

    // Convert into lower case

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
    }

    cout << str;

    return 0;
}