#include <iostream>
#include <vector>

using namespace std;

vector<int> findMaxMin(vector<int>& myList) {
    if (myList.empty()) {
        return {};
    }

    int maximum = myList[0];
    int minimum = myList[0];

    // Start the loop from the second element (index 1)
    for (int i = 1; i < myList.size(); ++i) {
        if (myList[i] > maximum) {
            maximum = myList[i];
        }
        if (myList[i] < minimum) {
            minimum = myList[i];
        }
    }

    return {maximum, minimum};
}

int main() {
    vector<int> myList = {3, 5, 7, 2, 8, -1, 4, 10, 12};
    vector<int> result = findMaxMin(myList);

    if (!result.empty()) {
        cout << "Maximum: " << result[0] << endl;
        cout << "Minimum: " << result[1] << endl;
    }

    return 0;
}
