#include <iostream>
#include <vector>
#include <algorithm> // For sort and reverse functions

using namespace std;

void printVector(const vector<int>& v) {
    for (int elem : v) {
        cout << elem << " ";
    }
    cout << endl;
}

int main() {
    // Initialize a vector
    vector<int> numbers = {4, 2, 9, 5, 1};

    // Print original vector
    cout << "Original vector: ";
    printVector(numbers);

    // Insert elements
    numbers.push_back(7); // Add to the end
    numbers.insert(numbers.begin() + 2, 8); // Insert 8 at index 2

    // Print after insertion
    cout << "After insertion: ";
    printVector(numbers);

    // Delete elements
    numbers.erase(numbers.begin() + 1); // Remove element at index 1
    numbers.pop_back(); // Remove the last element

    // Print after deletion
    cout << "After deletion: ";
    printVector(numbers);

    // Access elements
    cout << "Element at index 2: " << numbers[2] << endl;

    // Sort the vector
    sort(numbers.begin(), numbers.end());
    cout << "Sorted vector: ";
    printVector(numbers);

    // Reverse the vector
    reverse(numbers.begin(), numbers.end());
    cout << "Reversed vector: ";
    printVector(numbers);

    // Find an element
    auto it = find(numbers.begin(), numbers.end(), 5);
    if (it != numbers.end()) {
        cout << "Element 5 found at index: " << distance(numbers.begin(), it) << endl;
    } else {
        cout << "Element 5 not found." << endl;
    }

    // Size and capacity
    cout << "Size of the vector: " << numbers.size() << endl;
    cout << "Capacity of the vector: " << numbers.capacity() << endl;

    // Clear the vector
    numbers.clear();
    cout << "Vector after clearing: ";
    printVector(numbers);

    return 0;
}
