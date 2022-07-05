#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int f(int ind, int prev, vector<int> &nums, vector<vector<int>> &dp, int n)
{
    if (ind == n)
    {
        return 0;
    }

    if (dp[ind][prev + 1] != -1)
    {
        return dp[ind][prev + 1];
    }

    int len;

    // not take;
    len = 0 + f(ind + 1, prev, nums, dp, n);

    // take
    // if prev == -1 -> it means we are at first index.
    if (prev == -1 || nums[ind] > nums[prev])
    {
        len = max(len, 1 + f(ind + 1, ind, nums, dp, n));
    }
    return dp[ind][prev + 1] = len;
}

// initially we pass -1 as prev.
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    int ans = f(0, -1, nums, dp, n);
    return ans;
}

// Tabulation
int longestIncreasingSubsequence3(int arr[], int n)
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
    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        // For a particular index(i) we made pointer prev to check all previous
        // elements of index i.
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[prev] < arr[i])
            {
                dp[i] = max(dp[prev] + 1, dp[i]);
            }
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}

int main(int argc, char const *argv[])
{

    return 0;
}
