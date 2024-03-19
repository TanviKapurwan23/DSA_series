#include <iostream>
#include <string>
#include <algorithm> //to use sort

using namespace std;

int main()
{

    string s = "dkjsbkjdfbsk";

    transform(s.begin(), s.end(), s.begin(), ::toupper);
    cout << s << endl;

    transform(s.begin(), s.end(), s.begin(), ::tolower);
    cout << s << endl;

    return 0;
}