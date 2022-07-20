// Minimum sum of two numbers formed from digits of an array.
// Input: [6, 8, 4, 5, 2, 3]
// Output: 604
// The minimum sum is formed by numbers
// 358 and 246

#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

// Function for finding sum of larger numbers
string findSum(string str1, string str2)
{
    // Before proceeding further, make sure length
    // of str2 is larger.
    if (str1.length() > str2.length())
        swap(str1, str2);

    // Take an empty string for storing result
    string str = "";

    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();
    int diff = n2 - n1;

    // Initially take carry zero
    int carry = 0;

    // Traverse from end of both strings
    // eg -> if no. are n1=123 and n2=45678. ->
    // Then this loop will add 123 and  678.
    for (int i = n1 - 1; i >= 0; i--)
    {
        // Do school mathematics, compute sum of
        // current digits and carry
        int sum = ((str1[i] - '0') +
                   (str2[i + diff] - '0') +
                   carry);
        // if sum is 12 -> then carry will be 1 and
        // will push 2 to ans(str).
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    // Add remaining digits of str2[].
    // eg - for above eg -> it will be for
    // 45 of n2.
    for (int i = n2 - n1 - 1; i >= 0; i--)
    {
        int sum = ((str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    // Add remaining carry
    if (carry)
        str.push_back(carry + '0');

    // above function will return reverse form of our ans.
    // Hence, reverse resultant string
    reverse(str.begin(), str.end());

    return str;
}

string solve(int arr[], int n)
{
    sort(arr, arr + n);
    string s1 = "", s2 = "";
    for (int i = 0; i < n; i++)
    {
        // For odd places in arr ->
        // eg -> arr = [1,2,3,4,5] ->
        // then it will consider 1,3,5.
        if (i % 2 == 0)
        {
            // If first value of s1 is zero then
            // just ignore -> eg - 014 = 14.
            if (arr[i] == 0 && s1.empty())
            {
                continue;
            }
            s1 += to_string(arr[i]);
        }

        // it will consider for 2,4.
        else
        {
            if (arr[i] == 0 && s1.empty())
            {
                continue;
            }
            s2 += to_string(arr[i]);
        }
    }
    string s = findSum(s1, s2);
    return s;
}

int main(int argc, char const *argv[])
{
    int arr[] = {6, 8, 4, 5, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Sum is " << solve(arr, n);
    return 0;
}
