#include <iostream>
#include <string.h>

using namespace std;

void bottomUpHeapify(int arr[], int n, int i)
{
    int parent = (i - 1) / 2;
    if (arr[parent] > 0)
    {
        if (arr[i] > arr[parent])
        {
            swap(arr[i], arr[parent]);
            bottomUpHeapify(arr, n, parent);
        }
    }
}

void insert(int arr[], int &n, int key)
{
    // add one element in array;
    n = n + 1;

    // set last element of array as key.
    arr[n - 1] = key;

    bottomUpHeapify(arr, n, n - 1);
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    cout << endl;
}

int main(int argc, char const *argv[])
{
    int arr[5] = {10, 5, 3, 2, 4};

    int n = 5;

    int key = 15;

    insert(arr, n, key);

    printArray(arr, n);
    return 0;
}
