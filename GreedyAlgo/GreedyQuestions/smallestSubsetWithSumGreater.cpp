#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int minElements(int arr[], int n)
{
    sort(arr, arr + n);
    int s = 0;

    // initially s store sum of all digits.
    for (int i = 0; i < n; i++)
    {
        s += arr[i];
    }
    int ans = 0;
    int s2 = 0;
    int j = n - 1;

    // run loop till s2 > s.
    // substract arr[j] from s and
    // add it in s2.
    while (true)
    {
        s2 += arr[j];
        s -= arr[j];
        j--;
        ans++;
        if (s2 > s)
        {
            break;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 3, 1, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minElements(arr, n) << endl;
    return 0;
}

// Smallest subset with sum greater than all other elements
// Our task is to find minimum number of elements such that
// their sum should be greater than the sum of rest of the elements
// of the array.
// Input : arr[] = {3, 1, 7, 1}
// Output : 1
