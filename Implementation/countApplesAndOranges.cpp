#include <iostream>
#include <vector>
using namespace std;

void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {
    int applesOnHouse = 0;
    int orangesOnHouse = 0;

    // Calculate the landing points of apples and count how many fall on the house
    for (int i = 0; i < apples.size(); ++i) {
        int landingPoint = a + apples[i];
        if (landingPoint >= s && landingPoint <= t) {
            applesOnHouse++;
        }
    }

    // Calculate the landing points of oranges and count how many fall on the house
    for (int i = 0; i < oranges.size(); ++i) {
        int landingPoint = b + oranges[i];
        if (landingPoint >= s && landingPoint <= t) {
            orangesOnHouse++;
        }
    }

    // Output the results
    cout << applesOnHouse << endl;
    cout << orangesOnHouse << endl;
}

int main() {
    // Example usage
    int s = 7;
    int t = 10;
    int a = 4;
    int b = 12;
    vector<int> apples = {2, 3, -4};
    vector<int> oranges = {3, -2, -4};

    countApplesAndOranges(s, t, a, b, apples, oranges);

    return 0;
}
