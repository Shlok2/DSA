#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

// Memoization

int f(int ind, int buy, vector<int> &prices, int n, vector<vector<int>> &dp)
{
    if (ind == n)
    {
        return 0;
    }

    if (dp[ind][buy] != -1)
    {
        return dp[ind][buy];
    }

    int profit = 0;

    // Notice that prices are -ve when if(buy) -> as when we buy we lose money ->
    // Hence -prices[ind].
    if (buy)
    {
        profit = max(-prices[ind] + f(ind + 1, 0, prices, n, dp),
                     0 + f(ind + 1, 1, prices, n, dp));
    }
    else
    {
        profit = max(prices[ind] + f(ind + 1, 1, prices, n, dp),
                     0 + f(ind + 1, 0, prices, n, dp));
    }
    return dp[ind][buy] = profit;
}

int maxProfit(vector<int> &prices)
{

    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return f(0, 1, prices, n, dp);
}

// Tabulation

int maxProfit2(vector<int> &prices)
{

    int n = prices.size();
    vector<vector<long>> dp(n + 1, vector<long>(2, 0));

    // Base Case
    dp[n][0] = dp[n][1] = 0;

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            long profit = 0;

            if (buy)
            {
                profit = max(-prices[ind] + dp[ind + 1][0],
                             0 + dp[ind + 1][1]);
            }
            else
            {
                profit = max(prices[ind] + dp[ind + 1][1],
                             0 + dp[ind + 1][0]);
            }
            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
}

int main(int argc, char const *argv[])
{

    return 0;
}
