#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1;    // array size n1 & n2
    int n2 = r - mid;

    int a[n1];
    int b[n2]; // temp arrays  (small)

    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];    // storing l to mid elements
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid + 1 + i];   // storing mid to r elements
    }

    int i = 0;    // pointers
    int j = 0;
    int k = l;

    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = b[j];
            k++;
            j++;
        }
    }
    while (i < n1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }

    while (j < n2)
    {
        arr[k] = b[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[], int l, int r)   // pointer l and r
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);     // first half
        mergeSort(arr, mid + 1, r); // second half

        merge(arr, l, mid, r);      // now merge first and second
    }
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    mergeSort(arr, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
Time Complexity:

T(n) = n+n+n+...Log n terms
     = n Log n


OUTPUT:

1 2 3 4 5 

*/