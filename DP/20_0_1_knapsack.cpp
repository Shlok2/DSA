#include <iostream>
#include <string.h>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int f(int ind, int w, int *wt, int *val, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (wt[0] <= w)
        {
            return val[0];
        }
        else
        {
            return 0;
        }
    }

    if (dp[ind][w] != -1)
    {
        return dp[ind][w];
    }
    int notTake = 0 + f(ind - 1, w, wt, val, dp);
    int take = INT_MIN;
    if (wt[ind] <= w)
    {
        take = val[ind] + f(ind - 1, w - wt[ind], wt, val, dp);
    }
    return dp[ind][w] = max(take, notTake);
}

int knapSack(int W, int wt[], int val[], int n)
{

    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return f(n - 1, W, wt, val, dp);
}

// tabulation
int knapSack2(int W, int wt[], int val[], int n)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));
    // Base case -> When index is 0 and if wt[0] <= W -> then we return
    // value of val[0].
    for (int i = wt[0]; i <= W; i++)
    {
        // index 0 and i can be from wt[0] -> to W.
        dp[0][i] = val[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int weight = 0; weight <= W; weight++)
        {
            int notTake = 0 + dp[ind - 1][weight];
            int take = INT_MIN;
            if (wt[ind] <= weight)
            {
                take = val[ind] + dp[ind - 1][weight - wt[ind]];
            }
            dp[ind][weight] = max(take, notTake);
        }
    }
    return dp[n - 1][W];
}

int main(int argc, char const *argv[])
{

    return 0;
}
