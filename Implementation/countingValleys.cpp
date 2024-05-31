#include <iostream>
#include <string>
using namespace std;

int countingValleys(int steps, string path) {
    int altitude = 0; // Starting at sea level
    int valleyCount = 0;
    bool inValley = false;

    for (int i = 0; i < steps; ++i) {
        if (path[i] == 'U') {
            altitude++;
        } else if (path[i] == 'D') {
            altitude--;
        }

        // Check if we have just started a valley
        if (altitude < 0 && !inValley) {
            inValley = true;
        }

        // Check if we have just come out of a valley
        if (altitude == 0 && inValley) {
            valleyCount++;
            inValley = false;
        }
    }

    return valleyCount;
}

int main() {
    string path = "DDUUUUDD";
    int steps = path.length();
    cout << countingValleys(steps, path) << endl; // Output should be 1

    return 0;
}
