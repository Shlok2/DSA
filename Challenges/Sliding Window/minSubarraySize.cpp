#include <iostream>
#include <string.h>
using namespace std;

int minSubarraySize(int arr[], int n, int x)
{
    // minlegth is n+1,but the max length possible in array is
    //  n. Hence n+1 is not possible, So it acts as INT_MAX for
    //  size of array.Start/end act as Sliding Window.
    int sum = 0, minlength = n + 1, start = 0, end = 0;
    while (end < n)
    {
        // If sum <= x ->add arr[i] ki value to sum.
        while (sum <= x && end < n)
        {
            sum += arr[end++];
        }

        // If sum>x ->substract start pointer element from sum,
        //  also if at any point legth of start-end is less than
        // minlength-> replace minlength with end-start.
        // (Like min(minlength,end-start))

        while (sum > x && end < n)
        {
            if (end - start < minlength)
            {
                minlength = end - start;
            }
            sum -= arr[start++];
        }
    }
    return minlength;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 4, 45, 6, 10, 19};
    int x = 51;
    int n = 6;
    int answer = minSubarraySize(arr, n, x);

    // If ans = n+1 -> that means minlength remained same for entire
    //  function.
    if (answer == n + 1)
    {
        cout << "No such subarray exists" << endl;
    }
    else
    {
        cout << "Smallest length subarray is:" << answer << endl;
    }
    return 0;
}
