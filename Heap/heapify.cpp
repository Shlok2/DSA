#include <iostream>
#include <string.h>

using namespace std;

// i is index of root.
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i;
    int r = 2 * i + 1;

    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }

    // if largest position is changed from i ->
    // then we swap element at i with current element at largest.
    // and heapify with new largest.
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

int main(int argc, char const *argv[])
{

    return 0;
}
