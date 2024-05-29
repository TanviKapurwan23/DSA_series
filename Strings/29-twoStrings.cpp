#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

string twoStrings(string s1, string s2) {
    unordered_set<char> charsInS1;

    // Add all characters from the first string to the set
    for (char c : s1) {
        charsInS1.insert(c);
    }

    // Check if any character in the second string exists in the set
    for (char c : s2) {
        if (charsInS1.find(c) != charsInS1.end()) {
            return "YES";
        }
    }

    return "NO";
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        string s1, s2;
        cin >> s1 >> s2;
        cout << twoStrings(s1, s2) << endl;
    }

    return 0;
}
