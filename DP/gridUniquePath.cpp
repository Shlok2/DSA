#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int f(int i, int j, vector<vector<int>> &dp)
{
    // if it reaches its destination -> return 1.
    if (i == 0 && j == 0)
    {
        return 1;
    }

    // if it gets out of grid -> return 0.
    if (i < 0 || j < 0)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    // up -> do i-1 ; left -> do j-1.
    // return total of up and left as we have to calculate total.
    int up = f(i - 1, j, dp);
    int left = f(i, j - 1, dp);
    return dp[i][j] = up + left;
}

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return f(m - 1, n - 1, dp);
}

// tabulation

int uniquePaths2(int m, int n)
{
    int dp[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                int up = 0;
                int left = 0;
                if (i > 0)
                {
                    up = dp[i - 1][j];
                }
                if (j > 0)
                {
                    left = dp[i][j - 1];
                }
                dp[i][j] = up + left;
            }
        }
    }
    return dp[m - 1][n - 1];
}

int main(int argc, char const *argv[])
{

    return 0;
}
