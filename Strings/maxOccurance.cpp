#include <iostream>
#include <string>
#include <algorithm> //to use sort

using namespace std;

// output max times occuring character

int main()
{

    string s = "jkhkjhkjhkhjk";

    int freq[26];

    for (int i = 0; i < 26; i++)
    {
        freq[i] = 0;
    }
    for (int i = 0; i < s.size(); i++)
    {
        freq[s[i] - 'a']++;
    }

    char ans = 'a';
    int maxF = 0;

    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > maxF)
        {
            maxF = freq[i];
            ans = i + 'a';
        }
    }

    cout << maxF << " " << ans << endl;

    return 0;
}