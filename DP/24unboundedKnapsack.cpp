#include <iostream>
#include <string.h>
#include <vector>
#include <climits>
using namespace std;

int f(int ind, int W, int *val, int *wt, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        return ((int)(W / wt[0])) * val[0];
    }

    if (dp[ind][W] != -1)
    {
        return dp[ind][W];
    }

    int notTake = 0 + f(ind - 1, W, val, wt, dp);
    int take = 0;
    if (wt[ind] <= W)
    {
        take = val[ind] + f(ind, W - wt[ind], val, wt, dp);
    }
    return dp[ind][W] = max(take, notTake);
}

int knapSack(int N, int W, int val[], int wt[])
{
    vector<vector<int>> dp(N, vector<int>(W + 1, -1));
    return f(N - 1, W, val, wt, dp);
}

int main(int argc, char const *argv[])
{

    return 0;
}
