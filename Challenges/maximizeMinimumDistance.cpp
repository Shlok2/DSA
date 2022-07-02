

// On Logic of Binary Search

#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

bool isfeasible(int mid, int arr[], int n, int k)
{
    int pos = arr[0];
    int elements = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - pos >= mid)
        {
            pos = arr[i];
            elements++;
            if (elements == k)
            {
                return true;
            }
        }
    }
    return false;
}

// n is size of array.
int maxMinDistance(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int left = 1, right = arr[n - 1];
    int result = -1;

    while (left < right)
    {
        int mid = (left + right) / 2;

        // to check second half (from mid to end)
        if (isfeasible(mid, arr, n, k))
        {
            result = max(result, mid);
            left = mid + 1;
        }

        // to check first half (from start to mid)
        else
        {
            right = mid;
        }
    }
    return result;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 8, 4, 9};
    int n = 5;
    int k = 3;
    cout << maxMinDistance(arr, n, k);
    return 0;
}
