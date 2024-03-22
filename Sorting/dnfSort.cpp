#include <iostream>
using namespace std;

/*
0 0   1 1 1   ? ? ?   2 2

check value of arr[mid]
if 0, swap arr[low] and arr[mid], low++, mid++
if 1, mid++
if 2, swap arr[mid] and arr[high], high--

  1  1  2  0  0  1  2  2  1  0
low         mid            high

*/

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void dnfSort(int arr[], int n)
{
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr, low, mid);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr, mid, high);
            high--;
        }
    }
}

int main()

{
    int arr[] = {1, 0, 2, 1, 0, 1, 2, 1, 2};
    dnfSort(arr, 9);

    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

/*
OUTPUT:

0 0 1 1 1 1 2 2 2

time complexity: O(N)

In each operation, either mid gets incremented or
high gets decremented.

*/
