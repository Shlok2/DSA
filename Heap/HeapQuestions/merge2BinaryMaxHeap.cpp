#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[largest] < arr[l])
    {
        largest = l;
    }
    if (r < n && arr[largest] < arr[r])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void mergeHeap(int a[], int b[], int res[], int n1, int n2) // Merge two arrays in unsorted manner
{
    // Concat both arrays a and b to res arr.
    for (int i = 0; i < n1; i++)
        res[i] = a[i];
    for (int i = 0; i < n2; i++)
        res[n1 + i] = b[i];

    buildHeap(res, n1 + n2);
}

int main(int argc, char const *argv[])
{
    int a[] = {10, 5, 6, 2};
    int b[] = {12, 7, 9};
    int n1 = sizeof(a) / sizeof(a[0]);
    int n2 = sizeof(b) / sizeof(b[0]);
    int n = n1 + n2;
    int res[n1 + n2];
    mergeHeap(a, b, res, n1, n2);

    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}
