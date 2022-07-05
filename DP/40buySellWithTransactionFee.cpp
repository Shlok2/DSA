#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

// Only difference from buy and Sell stocks 2 is on line 33.
int f(int ind, int buy, vector<int> &prices, int n, vector<vector<int>> &dp, int fee)
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
        profit = max(-prices[ind] + f(ind + 1, 0, prices, n, dp, fee),
                     0 + f(ind + 1, 1, prices, n, dp, fee));
    }

    // Only difference is we will pay fee -> Hence we reduce fee from profit ->
    // prices[ind] - fee.
    else
    {
        profit = max(prices[ind] - fee + f(ind + 1, 1, prices, n, dp, fee),
                     0 + f(ind + 1, 0, prices, n, dp, fee));
    }
    return dp[ind][buy] = profit;
}

int maxProfit(vector<int> &prices, int fee)
{

    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return f(0, 1, prices, n, dp, fee);
}

int main(int argc, char const *argv[])
{

    return 0;
}
