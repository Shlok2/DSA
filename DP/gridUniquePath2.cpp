#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

// vector a stores 2d array with 0 and -1 in which -1 signifies
// the cell in which you cannon move.
// Nearly same as gridUniquePath.cpp function(tabulation), just one difference is
// that one more base case is added.
// extra base case ->
// if (obstacleGrid[i][j] == -1)
//    {
//      dp[i][j] = 0;
//    }
int uniquePaths2(int m, int n, vector<vector<int>> obstacleGrid)
{
    int dp[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (obstacleGrid[i][j] == -1)
            {
                dp[i][j] = 0;
            }
            else if (i == 0 && j == 0)
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

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = 0, n = 0;
    for (int i = 0; i < obstacleGrid.size(); i++)
    {
        m++;
    }
    for (int i = 0; i < obstacleGrid[0].size(); i++)
    {
        n++;
    }
    int a = uniquePaths2(m, n, obstacleGrid);
    return a;
}

int main(int argc, char const *argv[])
{

    return 0;
}
