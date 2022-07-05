#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
    {
        return 1;
    }
    if (ind == 0)
    {
        return (arr[0] == target);
    }
    if (dp[ind][target] != -1)
    {
        return dp[ind][target];
    }

    int notPick = f(ind - 1, target, arr, dp);
    int pick = 0;
    if (arr[ind] <= target)
    {
        pick = f(ind - 1, target - arr[ind], arr, dp);
    }
    return dp[ind][target] = pick + notPick;
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    return f(n - 1, tar, num, dp);
}

// Memoization

int findWays2(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

    // Base cases.
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    if (num[0] <= tar)
    {
        dp[0][num[0]] = 1;
    }

    // i=0 is already covered in base case.
    for (int ind = 1; ind < n; ind++)
    {
        for (int sum = 0; sum <= tar; sum++)
        {
            int notTake = dp[ind - 1][sum];
            int take = 0;
            if (num[ind] <= sum)
            {
                take = dp[ind - 1][sum - num[ind]];
            }
            dp[ind][sum] = notTake + take;
        }
    }
    return dp[n - 1][tar];
}

int main(int argc, char const *argv[])
{

    return 0;
}
