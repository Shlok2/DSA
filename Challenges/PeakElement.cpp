#include <iostream>
#include <string.h>
using namespace std;

// n stores size of array.
int findPeakElement(int arr[], int low, int high, int n)
{
    // another way to find mid instead of
    // mid = high + low / 2
    int mid = low + (high - low) / 2;
    if ((arr[mid + 1] <= arr[mid] || mid == n - 1) && (arr[mid - 1] <= arr[mid] || mid == 0))
    {
        return mid;
    }

    else if (arr[mid - 1] > arr[mid] && mid > 0)
    {
        return findPeakElement(arr, low, mid - 1, n);
    }

    // arr[mid + 1] > arr[mid]
    else
    {
        return findPeakElement(arr, mid + 1, high, n);
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {0, 6, 8, 5, 7, 9};
    int n = 6;
    cout << findPeakElement(arr, 0, n - 1, n);
    return 0;
}
