#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

bool f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    // if at any point target becomes 0.
    if (target == 0)
    {
        return true;
    }

    // if we reached first index from ind-1 -> and if arr[0] == target
    // then return true.
    if (ind == 0)
    {
        return (arr[0] == target);
    }

    if (dp[ind][target] != -1)
    {
        return dp[ind][target];
    }

    // If we dont take curr element than just reduce element and pass it
    // to reccurssion.
    bool notTake = f(ind - 1, target, arr, dp);

    // If curr element is < target and we want to take the element than
    // reduce index and also reduce value of target to target - curr
    // element value.
    bool take = false;
    if (arr[ind] <= target)
    {
        take = f(ind - 1, target - arr[ind], arr, dp);
    }

    return dp[ind][target] = take | notTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return f(n - 1, k, arr, dp);
}

// Memoization
bool subsetSumToK2(int n, int k, vector<int> &arr)
{
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));

    // Base cases
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target < k; target++)
        {
            bool notTake = dp[ind - 1][target];
            bool take = false;
            if (arr[ind] <= target)
            {
                take = dp[ind - 1][target - arr[ind]];
                dp[ind][target] = take | notTake;
            }
        }
    }
    return dp[n - 1][k];
}

int main(int argc, char const *argv[])
{

    return 0;
}
