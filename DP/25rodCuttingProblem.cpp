#include <iostream>
#include <string.h>
#include <vector>
#include <climits>
using namespace std;

int f(int ind, int N, vector<int> &price, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        return N * price[0];
    }

    if (dp[ind][N] != -1)
    {
        return dp[ind][N];
    }

    int notTake = 0 + f(ind - 1, N, price, dp);
    int take = INT_MIN;
    int rodLength = ind + 1;
    if (rodLength <= N)
    {
        take = price[ind] + f(ind, N - rodLength, price, dp);
    }
    return dp[ind][N] = max(take, notTake);
}

int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f(n - 1, n, price, dp);
}

// Tabulation
int cutRod2(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    for (int N = 0; N <= n; N++)
    {
        dp[0][N] = N * price[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int N = 0; N <= n; N++)
        {
            int notTake = 0 + dp[ind - 1][N];
            int take = INT_MIN;
            int rodLength = ind + 1;
            if (rodLength <= N)
            {
                take = price[ind] + dp[ind][N - rodLength];
            }
            dp[ind][N] = max(take, notTake);
        }
    }
    return dp[n - 1][n];
}

int main(int argc, char const *argv[])
{

    return 0;
}
