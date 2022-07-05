#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int f(int ind, int T, vector<int> &denominations, vector<vector<int>> &dp)
{
    // if T divides first element of array completely then return 1
    // (meaning consider this case).
    // else return 0 and not consider this case.
    if (ind == 0)
    {
        return (T % denominations[0] == 0);
    }

    if (dp[ind][T] != -1)
    {
        return dp[ind][T];
    }

    int notTake = f(ind - 1, T, denominations, dp);
    int take = 0;
    if (denominations[ind] <= T)
    {
        take = f(ind, T - denominations[ind], denominations, dp);
    }
    return dp[ind][T] = take + notTake;
}

// amount is Target.
int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    return f(n - 1, amount, coins, dp);
}

// Tabulation
int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

    for (int T = 0; T <= amount; T++)
    {
        dp[0][T] = (T % coins[0] == 0);
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int T = 0; T <= amount; T++)
        {
            int notTake = dp[ind - 1][T];
            int take = 0;
            if (coins[ind] <= T)
            {
                take = dp[ind][T - coins[ind]];
            }
            dp[ind][T] = take + notTake;
        }
    }
    return dp[n - 1][amount];
}

int main(int argc, char const *argv[])
{

    return 0;
}
