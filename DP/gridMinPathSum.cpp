#include <iostream>
#include <string.h>
#include <vector>
#include <climits>
using namespace std;

int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    // if we reach starting point then we have to add value of
    // starting point also to ans -> Hence return grid[0][0].
    if (i == 0 && j == 0)
    {
        return grid[i][j];
    }

    // If we reach out of grid then we dont want to insert that
    // value in ans -> Hence we return max value int can take
    // so not to include it in ans.
    if (i < 0 || j < 0)
    {
        return 1e9;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    // up left go to left and up in grid and add value of cell in
    // ans then check further and final ans is returned as min of
    // left and up.
    int up = grid[i][j] + f(i - 1, j, grid, dp);
    int left = grid[i][j] + f(i, j - 1, grid, dp);
    return dp[i][j] = min(up, left);
}

int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(n - 1, m - 1, grid, dp);
}

int minSumPath2(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = grid[i][j];
            }
            else
            {
                int up = grid[i][j];
                if (i > 0)
                {
                    up += dp[i - 1][j];
                }
                else
                {
                    up += 1e9;
                }

                int left = grid[i][j];
                if (j > 0)
                {
                    left += grid[i][j - 1];
                }
                else
                {
                    left += 1e9;
                }

                dp[i][j] = min(up, left);
            }
        }
    }
    return dp[n - 1][m - 1];
}

int main(int argc, char const *argv[])
{

    return 0;
}
