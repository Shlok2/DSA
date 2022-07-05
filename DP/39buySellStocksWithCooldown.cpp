#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

// Same code as of buy and sell stocks 2 ,only difference is at line 32.
int f(int ind, int buy, vector<int> &prices, int n, vector<vector<int>> &dp)
{
    if (ind >= n)
    {
        return 0;
    }

    if (dp[ind][buy] != -1)
    {
        return dp[ind][buy];
    }

    int profit = 0;

    if (buy)
    {
        profit = max(-prices[ind] + f(ind + 1, 0, prices, n, dp),
                     0 + f(ind + 1, 1, prices, n, dp));
    }

    // Only difference with buy and sell stocks 2 is when we sell,
    // we will not buy on ind + 1 (because of cooldown), instead we
    // will buy on ind + 2.
    else
    {
        profit = max(prices[ind] + f(ind + 2, 1, prices, n, dp),
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

int main(int argc, char const *argv[])
{

    return 0;
}
