#include <iostream>
using namespace std;

long strangeCounter(long t) {
    long cycleStart = 3;
    long timeElapsed = 0;
    
    // Find the cycle containing time t
    while (timeElapsed + cycleStart < t) {
        timeElapsed += cycleStart;
        cycleStart *= 2; // Double the cycle length
    }

    // The start time of the current cycle
    long cycleEndTime = timeElapsed + cycleStart;
    
    // Calculate the counter value at time t
    return cycleEndTime - t + 1;
}

int main() {
    long t = 17;
    cout << "Counter value at time " << t << ": " << strangeCounter(t) << endl; // Expected output should be 5

    return 0;
}
