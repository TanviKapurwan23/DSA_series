#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "Hello, World!";
    
    // Extract substring starting from index 7 to the end of the string
    string sub = s.substr(7);
    
    cout << sub; // Output: World!
    
    return 0;
}
