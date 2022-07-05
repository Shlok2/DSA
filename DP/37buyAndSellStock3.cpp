#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

// Memoization
int f(int ind, int buy, int cap, vector<int> &prices, int n, vector<vector<vector<int>>> &dp)
{
    if (ind == n || cap == 0)
    {
        return 0;
    }

    if (dp[ind][buy][cap] != -1)
    {
        return dp[ind][buy][cap];
    }

    int profit = 0;

    // Notice that prices are -ve when if(buy) -> as when we buy we lose money ->
    // Hence -prices[ind].
    if (buy)
    {
        profit = max(-prices[ind] + f(ind + 1, 0, cap, prices, n, dp),
                     0 + f(ind + 1, 1, cap, prices, n, dp));
    }
    else
    {
        profit = max(prices[ind] + f(ind + 1, 1, cap - 1, prices, n, dp),
                     0 + f(ind + 1, 0, cap, prices, n, dp));
    }
    return dp[ind][buy][cap] = profit;
}

int maxProfit(vector<int> &prices)
{

    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    return f(0, 1, 2, prices, n, dp);
}

// Tabulation

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    // Base Cases are not needed in this part because we initiallise vector with 0 only.
    // But if we even put below base case then our solution will be running fine.

    // Base Cases

    //         int ind,cap;
    //         if(cap == 0){
    //             for(int ind = 0;ind <= n-1;ind++){
    //                 for(int buy = 0;buy<=1;buy++){
    //                     dp[ind][buy][0] = 0;
    //                 }
    //             }
    //         }

    //         if(ind == n){
    //             for(int buy = 0;buy<=1;buy++){
    //                 for(int cap = 0;cap<=2;cap++){
    //                     dp[n][buy][cap] = 0;
    //                 }
    //             }
    //         }

    // We dont need for loop for cap = 0 -> As cap = 0 is base case
    // So whenever cap = 0 -> Base case will run.
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            {

                int profit = 0;
                if (buy)
                {
                    profit = max(-prices[ind] + dp[ind + 1][0][cap],
                                 0 + dp[ind + 1][1][cap]);
                }
                else
                {
                    profit = max(prices[ind] + dp[ind + 1][1][cap - 1],
                                 0 + dp[ind + 1][0][cap]);
                }
                dp[ind][buy][cap] = profit;
            }
        }
    }
    return dp[0][1][2];
}

int main(int argc, char const *argv[])
{

    return 0;
}
