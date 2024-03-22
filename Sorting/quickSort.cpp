#include <iostream>
using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int partition(int arr[], int l, int r)
{
    int pivot = arr[r]; // pivot element
    int i = l - 1;

    for (int j = 1; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, r);
    return i + 1;
}

void quickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int pi = partition(arr, l, r); // pivot element index
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, r);
    }
}

int main()
{
    int arr[5] = {5, 4, 3, 2, 1};
    quickSort(arr, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

/*

Quick Sort complexity

depends on pivot:
1. in Best case, pivot would be median element
2. in Worst case, pivot could be end element

T(n) = 2T(n/2) + n
T(n) = 2T(n/2) + n
T(n/2) = 2T(n/4) + n/2
T(n/4) = 2T(n/8) + n/4
:
:
:
T(1) = 1


T(n) = n + n + n + .... Log n terms
     = O(n log n) in best case


in worst case,
T(n) = T(n-1) + n

in this case,
time complexity would be O(N^2)

*/