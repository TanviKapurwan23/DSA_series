#include <iostream>
using namespace std;

int utopianTree(int n) {
    int height = 1; // Initial height of the tree

    for (int cycle = 1; cycle <= n; ++cycle) {
        if (cycle % 2 == 1) {
            // Spring: the tree doubles in height
            height *= 2;
        } else {
            // Summer: the tree grows by 1 meter
            height += 1;
        }
    }

    return height;
}

int main() {
    int n = 5;
    cout << "Height of the tree after " << n << " cycles: " << utopianTree(n) << endl; // Output should be 14

    return 0;
}
