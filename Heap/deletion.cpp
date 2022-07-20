#include <iostream>
#include <string.h>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void deletion(int arr[], int &n)
{

    // swap last element with root.
    int lastelement = arr[n - 1];
    arr[0] = lastelement;

    // decrease size of array(same as removing last node(which is swapped in previous step.))
    n = n - 1;

    // i is the index in heapify and hence we pass i(index) = 0.
    // to heapify the array after deletion.
    heapify(arr, n, 0);
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int arr[] = {10, 5, 3, 2, 4};

    int n = sizeof(arr) / sizeof(arr[0]);

    deletion(arr, n);

    printArray(arr, n);
    return 0;
}
