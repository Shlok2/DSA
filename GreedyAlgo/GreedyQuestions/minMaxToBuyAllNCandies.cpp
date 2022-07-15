// price[] = {3, 2, 1, 4}
// k = 2
// Output :
// Min = 3, Max = 7
// Explanation :
// Since k is 2, if we buy one candy we can take
// atmost two more for free.
// So in the first case we buy the candy which
// costs 1 and take candies worth 3 and 4 for
// free, also you buy candy worth 2 as well.
// So min cost = 1 + 2 = 3.
// In the second case we buy the candy which
// costs 4 and take candies worth 1 and 2 for
// free, also We buy candy worth 3 as well.
// So max cost = 3 + 4 = 7.

#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int findMinimum(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += arr[i];
        n = n - k;
    }
    return res;
}

int findMaximum(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int res = 0, index = 0;
    for (int i = n - 1; i >= index; i--)
    {
        res += arr[i];
        index += k;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int arr[] = {3, 2, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    // Function call
    cout << findMinimum(arr, n, k) << " "
         << findMaximum(arr, n, k) << endl;
    return 0;
}
