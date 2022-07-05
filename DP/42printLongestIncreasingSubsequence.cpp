#include <iostream>
#include <string.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// ORIGINAL Tabulation
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev = ind - 1; prev >= -1; prev--)
        {
            int len = 0 + dp[ind + 1][prev + 1];
            if (prev == -1 || arr[ind] > arr[prev])
            {
                len = max(len, 1 + dp[ind + 1][ind + 1]);
            }
            dp[ind][prev] = len;
        }
    }
    return dp[0][-1 + 1];
}

// BETTER Tabulation
// To understand this concept better -> 1) Watch DP42 Printing LIS (by takeUForward).
//                                      2) See copy (Lec 42).
int longestIncreasingSubsequence2(int arr[], int n)
{
    // Initiallise dp arr with 1.
    vector<int> dp(n, 1);
    vector<int> hash(n);
    int maxi = 1;
    int lastIndex = 0;
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        // For a particular index(i) we made pointer prev to check all previous
        // elements of index i.
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[prev] < arr[i] && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            lastIndex = i;
        }
    }
    vector<int> temp;
    temp.push_back(arr[lastIndex]);
    while (hash[lastIndex] != lastIndex)
    {
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }
    reverse(temp.begin(), temp.end());
    for (auto it : temp)
    {
        cout << it << " ";
    }
    cout << endl;
    return maxi;
}

int main(int argc, char const *argv[])
{

    return 0;
}
