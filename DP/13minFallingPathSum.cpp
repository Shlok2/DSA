#include <iostream>
#include <string.h>
#include <cmath>
#include <vector>
using namespace std;

int f(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    // If we return INT_MAX then it will go out of bound for limit of int
    // Hence we return nearly max value which int can take.
    if (j < 0 || j >= matrix[0].size())
    {
        return 1e8;
    }
    if (i == 0)
    {
        return matrix[0][j];
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int u = matrix[i][j] + f(i - 1, j, matrix, dp);
    int ld = matrix[i][j] + f(i - 1, j - 1, matrix, dp);
    int rd = matrix[i][j] + f(i - 1, j + 1, matrix, dp);

    return dp[i][j] = min(u, min(ld, rd));
}

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int mini = 1e8;
    vector<vector<int>> dp(n, vector<int>(m, -1));

    // mini is to return min of all values obtained on different values
    // output of last row.
    for (int j = 0; j < m; j++)
    {
        mini = min(mini, f(n - 1, j, matrix, dp));
    }
    return mini;
}

// Memoization -> TC -> O(N*M) + O(M).
//                SC -> O(N*M).
int minFallingPathSum2(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    for (int j = 0; j < m; j++)
    {
        dp[0][j] = matrix[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = matrix[i][j] + dp[i - 1][j];

            int ld = matrix[i][j];
            if (j - 1 >= 0)
            {
                ld += dp[i - 1][j - 1];
            }
            else
            {
                ld += 1e8;
            }

            int rd = matrix[i][j];
            if (j + 1 < m)
            {
                rd += dp[i - 1][j + 1];
            }
            else
            {
                rd += 1e8;
            }

            dp[i][j] = min(u, min(ld, rd));
        }
    }
    int mini = 1e8;
    for (int j = 0; j < m; j++)
    {
        mini = min(mini, dp[n - 1][j]);
    }
    return mini;
}

int main(int argc, char const *argv[])
{

    return 0;
}
