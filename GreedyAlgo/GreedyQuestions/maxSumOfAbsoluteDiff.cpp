#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int MaxSumDifference(int a[], int n)
{
    // array -> {1,2,3,8}.
    sort(a, a + n);
    int i = 0;
    int j = n - 1;
    vector<int> v;

    for (int i = 0; i < n / 2; i++)
    {
        v.push_back(a[i]);
        v.push_back(a[n - i - 1]);
    }
    // Final array -> {1,8,2,4}.

    // If there are odd elements, push the
    // middle element at the end.
    if (n % 2 == 1)
    {
        v.push_back(a[n / 2]);
    }

    int maxSum = 0;
    // To add (absolute)diff of v[i+1] - v[i].
    // abs(8-1) + abs(2-8) + abs(4-2) = 15.
    for (int i = 0; i < n - 1; i++)
    {
        maxSum += abs(v[i + 1] - v[i]);
    }

    // To add diff of first and last element.
    // 15 + abs(1-4) = 18.
    maxSum += abs(v[0] - v[n - 1]);
    return maxSum;
}

int main(int argc, char const *argv[])
{
    int a[] = {1, 4, 2, 8};
    int n = sizeof(a) / sizeof(a[0]);

    cout << MaxSumDifference(a, n) << endl;
    return 0;
}

// Question Explanation.

// Maximum sum of absolute difference of an array
// Input : { 1, 2, 4, 8 }
// Output : 18
// Explanation : For the given array there are
// several sequence possible
// like : {2, 1, 4, 8}
//        {4, 2, 1, 8} and some more.
// Now, the absolute difference of an array sequence will be
// like for this array sequence {1, 2, 4, 8}, the absolute
// difference sum is
// = |1-2| + |2-4| + |4-8| + |8-1|
// = 14
// For the given array, we get the maximum value for
// the sequence {1, 8, 2, 4}
// = |1-8| + |8-2| + |2-4| + |4-1|
// = 18
