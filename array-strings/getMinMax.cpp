#include <iostream>
#include <utility>
using namespace std;

pair<long long, long long> getMinMax(long long a[], int n) {
    if (n == 0) {
        return make_pair(LLONG_MIN, LLONG_MAX); // Return min and max as per long long limits if array is empty
    }

    long long minVal = a[0];
    long long maxVal = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] < minVal) {
            minVal = a[i]; // Update minVal if current element is smaller
        }
        if (a[i] > maxVal) {
            maxVal = a[i]; // Update maxVal if current element is larger
        }
    }

    return make_pair(minVal, maxVal);
}

int main() {
    long long A[] = {3, 2, 1, 56, 10000, 167};
    int N = sizeof(A) / sizeof(A[0]);

    pair<long long, long long> minMax = getMinMax(A, N);
    cout << "Minimum: " << minMax.first << ", Maximum: " << minMax.second << endl;

    return 0;
}
