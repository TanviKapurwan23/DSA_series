#include <iostream>
#include <vector>

int linearSearch(const std::vector<int>& arr, int x) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

int main() {
    std::vector<int> arr = {2, 3, 4, 10, 40};
    int x = 10;
    int result = linearSearch(arr, x);
    if (result != -1)
        std::cout << "Element is present at index " << result;
    else
        std::cout << "Element is not present in array";
    return 0;
}
