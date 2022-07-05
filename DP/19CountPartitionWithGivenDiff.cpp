#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int mod = (int)(1e9 + 7);
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
    return dp[ind][target] = (pick + notPick) % mod;
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    return f(n - 1, tar, num, dp);
}

int countPartitions(int n, int d, vector<int> &arr)
{
    int totSum = 0;
    for (auto &it : arr)
    {
        totSum += it;
    }
    if (totSum - d < 0 || (totSum - d) % 2 == 1)
    {
        return false;
    }
    int s2 = (totSum - d) / 2;
    return findWays(arr, s2);
}

int main(int argc, char const *argv[])
{

    return 0;
}
