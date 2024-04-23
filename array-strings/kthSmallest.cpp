#include <iostream>
#include <algorithm>
using namespace std;

int partition(int arr[], int l, int r) {
    int pivot = arr[r];
    int i = l - 1;

    for (int j = l; j < r; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[r]);
    return i + 1;
}

int kthSmallest(int arr[], int l, int r, int k) {
    if (k > 0 && k <= r - l + 1) {
        int pos = partition(arr, l, r);

        if (pos - l == k - 1) {
            return arr[pos];
        }
        if (pos - l > k - 1) {
            return kthSmallest(arr, l, pos - 1, k);
        }

        return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
    }

    return -1; // Return -1 if k is out of bounds
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    int l = 0;
    int r = n - 1;

    int kthSmallestElement = kthSmallest(arr, l, r, k);
    cout << "The " << k << "th smallest element is: " << kthSmallestElement << endl;

    return 0;
}
