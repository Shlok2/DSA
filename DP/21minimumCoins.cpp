#include <iostream>
#include <string.h>
#include <vector>
#include <climits>
using namespace std;

int f(int ind, int T, int *nums, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (T % nums[0] == 0)
        {
            return T / nums[0];
        }
        else
        {
            return 1e9;
        }
    }

    if (dp[ind][T] != -1)
    {
        return dp[ind][T];
    }

    int notTake = 0 + f(ind - 1, T, nums, dp);
    int take = INT_MAX;
    if (nums[ind] <= T)
    {
        take = 1 + f(ind, T - nums[ind], nums, dp);
    }

    return dp[ind][T] = min(take, notTake);
}

// coins is denomation array.
// M is no. of elements in coins array.
// V is Target to be Reached.
int minCoins(int coins[], int M, int V)
{
    vector<vector<int>> dp(M, vector<int>(V + 1, -1));
    int ans = f(M - 1, V, coins, dp);

    if (ans >= 1e9)
    {
        return -1;
    }
    else
    {
        return ans;
    }
}

int minCoins2(int coins[], int M, int V)
{
    vector<vector<int>> dp(M, vector<int>(V + 1, 0));
    for (int T = 0; T <= V; T++)
    {
        if (T % coins[0] == 0)
        {
            dp[0][T] = T / coins[0];
        }
        else
        {
            dp[0][T] = 1e9;
        }
    }

    for (int ind = 1; ind < M; ind++)
    {
        for (int T = 0; T <= V; T++)
        {
            int notTake = 0 + dp[ind - 1][T];
            int take = INT_MAX;
            if (coins[ind] <= T)
            {
                take = 1 + dp[ind][T - coins[ind]];
            }
            dp[ind][T] = min(take, notTake);
        }
    }

    int ans = dp[M - 1][V];
    if (ans >= 1e9)
    {
        return -1;
    }
    else
    {
        return ans;
    }
}

int main(int argc, char const *argv[])
{

    return 0;
}
