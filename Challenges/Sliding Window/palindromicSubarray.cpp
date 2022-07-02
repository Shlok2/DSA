#include <iostream>
#include <string.h>
#include <vector>
#include <cmath>
using namespace std;

bool isPalindrome(int n)
{
    int temp = n, num = 0;
    // reverse n -> if n = 123 ->then num = 321.
    while (temp > 0)
    {
        num = num * 10 + temp % 10;
        temp = temp / 10;
    }

    // if original num(n) = reverse num(num)->
    // Yes, It is a parindrome.
    if (num == n)
    {
        return true;
    }
    return false;
}

int findPalindromicSubarray(vector<int> arr, int k)
{
    int num = 0;

    // This loop is to concatenate initial k numbers.
    // eg -> if first k(let say 3) numbers are 1,2,3->
    // then 0*10 + 1 = 1 -> 1*10 + arr[1] = 10 + 2 = 12 ->
    // then 12 * 10 + arr[2] = 120 + 3 = 123
    // hence 1,2,3 concatenated to 123.
    for (int i = 0; i < k; i++)
    {
        num = num * 10 + arr[i];
    }

    if (isPalindrome(num))
    {
        return 0;
    }

    for (int j = k; j < arr.size(); j++)
    {
        // this mathematical function removes first digit from num
        // and add one digit in back.
        // eg - (123 % 10^(3-1)) = 123 % 10^2 = 23
        // -> now 23 * 10 = 230 -> 230 + arr[3] = 230 + 4 = 234.
        // Hence, 123 converted to 234.
        num = (num % (int)pow(10, k - 1)) * 10 + arr[j];

        if (isPalindrome(num))
        {
            // Starting point of this subarray(sliding window).
            return j - k + 1;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {2, 3, 5, 1, 1, 5};
    int k = 4;
    int ans = findPalindromicSubarray(arr, k);
    if (ans == -1)
    {
        cout << "Palindromic Subarray doesn't exist." << endl;
    }
    else
    {
        for (int i = ans; i < ans + k; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
