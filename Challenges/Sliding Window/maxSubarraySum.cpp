#include <iostream>
#include <string.h>
using namespace std;

void maxSubarraySum(int arr[], int n, int k, int x)
{
    int sum = 0, ans = 0;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }

    if (sum < x)
    {
        ans = sum;
    }

    for (int i = k; i < n; i++)
    {

        // eg if arr = [1,2,3,4,5,6,7] , k = 3 ,then
        // substracting first element of array -> substracting 1.
        sum = sum - arr[i - k];
        // adding kth element -> then adding arr[k] = arr[3] = 4.
        sum = sum + arr[i];
        if (sum < x)
        {
            ans = max(sum, ans);
        }
    }

    cout << "The maximum subarray sum is: " << ans;
}

int main(int argc, char const *argv[])
{
    int arr[] = {7, 5, 4, 6, 8, 9};
    int k = 3;
    int x = 20;
    int n = 6;
    maxSubarraySum(arr, n, k, x);
    return 0;
}
