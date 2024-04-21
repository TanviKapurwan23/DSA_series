#include <iostream>
#include <sstream>
#include <unordered_set>
using namespace std;

string findFirstRepeatedWord(const string& input) {
    istringstream iss(input);
    string word;
    unordered_set<string> seenWords;

    while (iss >> word) {
        // Convert the word to lowercase
        for (char& c : word) {
            c = tolower(c);
        }

        if (seenWords.count(word)) {
            return word;
        } else {
            seenWords.insert(word);
        }
    }

    return "No Repetition";
}

int main() {
    string input1 = "Ravi had been saying that he had been there";
    cout << findFirstRepeatedWord(input1) << endl; // Output: had

    string input2 = "Ravi had been saying that";
    cout << findFirstRepeatedWord(input2) << endl; // Output: No Repetition

    return 0;
}
