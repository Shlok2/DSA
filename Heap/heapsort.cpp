
// 1. Build a max heap from the input data.
// 2. At this point, the largest item is stored at the root of the heap. Replace it with the last item of the heap
// followed by reducing the size of heap by 1. Finally, heapify the root of the tree.
// 3. Repeat step 2 while the size of the heap is greater than 1 (Heap is not empty(finished)).

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

void heapSort(int arr[], int n)
{
    // step 1 -> heapifing the array
    // n/2 - 1 is the last leaf node in heap.
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--)
    {
        // step2 -> Move current root to end
        // Swap last element with root.
        swap(arr[0], arr[i]);

        // step3 -> call max heapify again for new root.
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main(int argc, char const *argv[])
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    cout << "Sorted array is \n";
    printArray(arr, n);
    return 0;
}
