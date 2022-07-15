// Input : arr[] = {-2, 0, 5, -1, 2}
//         K = 4
// Output: 10
// Explanation:
// 1. Replace (-2) by -(-2), array becomes {2, 0, 5, -1, 2}
// 2. Replace (-1) by -(-1), array becomes {2, 0, 5, 1, 2}
// 3. Replace (0) by -(0), array becomes {2, 0, 5, 1, 2}
// 4. Replace (0) by -(0), array becomes {2, 0, 5, 1, 2}

#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int maximumSum(int arr[], int n, int k)
{
    // array after sorting -> 5,2,0,-1,-2 -> k = 4.
    sort(arr, arr + n, greater<int>());
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] < 0)
        {
            arr[i] = -arr[i];
            k--;
        }
    }
    // array -> 5 2 0 1 2

    sort(arr, arr + n, greater<int>());
    // array -> 5 2 2 1 0 -> k = 2.
    // This while loop will switch last element of array between negative
    // and positive till k becomes 0.
    while (k != 0)
    {
        arr[n - 1] = -arr[n - 1];
        k--;
    }

    // array -> 5 2 2 1 0
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    int arr[] = {-2, 0, 5, -1, 2};
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maximumSum(arr, n, k);
    return 0;
}
