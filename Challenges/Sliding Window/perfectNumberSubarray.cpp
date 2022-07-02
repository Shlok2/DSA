
// Answer is coming wrong in this question.
// There might be a small mistake in code.

#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

bool isPerfectNumber(int n)
{
    int sum = 1;
    for (int i = 2; i < sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (i == n / i)
            {
                sum += i;
            }
            else
            {
                sum += i + n / i;
            }
        }
    }
    if (sum == n && n != 1)
    {
        return true;
    }
    return false;
}

int maxSum(int arr[], int n, int k)
{

    // No subarray size can be greater than array itself.
    if (k > n)
    {
        cout << "Invalid values" << endl;
        return -1;
    }
    int res = 0;
    for (int i = 0; i < k; i++)
    {
        res += arr[i];
    }
    int sum = res;
    for (int i = k; i < n; i++)
    {
        sum += arr[i] - arr[i - k];
        res = max(sum, res);
    }
    return res;
}

// to convert array to binary array.
int maxnumberofPerfects(int arr[], int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (isPerfectNumber(arr[i]))
        {
            arr[i] = 1;
        }
        else
        {
            arr[i] = 0;
        }
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {28, 2, 3, 6, 496, 99, 8128, 24};
    int k = 4;
    int n = 8;
    cout << maxnumberofPerfects(arr, n, k);
    return 0;
}
