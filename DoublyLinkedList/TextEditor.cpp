#include <iostream>
#include <deque>
#include <string>
using namespace std;

class TextEditor {
private:
    deque<char> left;  // Characters to the left of the cursor
    deque<char> right; // Characters to the right of the cursor

public:
    TextEditor() {}

    void addText(string text) {
        for (char c : text) {
            left.push_back(c);
        }
    }

    int deleteText(int k) {
        int deleted = 0;
        while (k > 0 && !left.empty()) {
            left.pop_back();
            --k;
            ++deleted;
        }
        return deleted;
    }

    string cursorLeft(int k) {
        while (k > 0 && !left.empty()) {
            right.push_front(left.back());
            left.pop_back();
            --k;
        }
        return getLastCharacters(10); // Return the last 10 characters or less if not available
    }

    string cursorRight(int k) {
        while (k > 0 && !right.empty()) {
            left.push_back(right.front());
            right.pop_front();
            --k;
        }
        return getLastCharacters(10); // Return the last 10 characters or less if not available
    }

private:
    string getLastCharacters(int n) {
        string result;
        int count = 0;
        while (!left.empty() && count < n) {
            result = left.back() + result;
            left.pop_back();
            ++count;
        }
        // Restore the state of the deque
        for (char c : result) {
            left.push_back(c);
        }
        return result;
    }
};

// Helper function to demonstrate the TextEditor class
int main() {
    TextEditor editor;
    editor.addText("hello");
    cout << "Cursor left 2: " << editor.cursorLeft(2) << endl; // Output: "he"
    editor.addText("world");
    cout << "Cursor right 1: " << editor.cursorRight(1) << endl; // Output: "h"
    cout << "Delete 3 characters: " << editor.deleteText(3) << endl; // Output: 3
    cout << "Cursor left 2: " << editor.cursorLeft(2) << endl; // Output: "lo"
    
    return 0;
}
