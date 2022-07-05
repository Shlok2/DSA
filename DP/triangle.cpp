#include <iostream>
#include <string.h>
#include <vector>
#include <cmath>
using namespace std;

// Triangle -
// 1
// 3 2
// 6 3 7
// 8 9 1 6
// if we reach last row then return we also have to include its value
// in sum -> hence we return its value.
// Also we can have multiple values in last row.(eg - 8,9,1,6).
// min path -> 1+2+3+1 -> 7
int f(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp, int n)
{
    if (i == n - 1)
    {
        return triangle[n - 1][j];
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int down = triangle[i][j] + f(i + 1, j, triangle, dp, n);
    int diagonalDown = triangle[i][j] + f(i + 1, j + 1, triangle, dp, n);
    return dp[i][j] = min(down, diagonalDown);
}

// n stores no. of rows in triangle.
int minimumPathSum(vector<vector<int>> &triangle)
{
    int n = 0;
    for (int i = 0; i < triangle.size(); i++)
    {
        n++;
    }
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return f(0, 0, triangle, dp, n);
}

// Memoization
int minimumPathSum2(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));
    // as we can have multiple ending points -> hence we have to
    // set multiple values in dp array.
    // step 1 -> write base case first.
    for (int j = 0; j < n; j++)
    {
        dp[n - 1][j] = triangle[n - 1][j];
    }

    // step 2 -> convert reccurssion into for loops.
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + dp[i + 1][j];
            int diagonalDown = triangle[i][j] + dp[i + 1][j + 1];
            dp[i][j] = min(down, diagonalDown);
        }
    }

    // step 3 -> return final answer.
    return dp[0][0];
}

int main(int argc, char const *argv[])
{

    return 0;
}

// Given a triangle array, return the minimum path sum from top to bottom.

// For each step,
// you may move to an adjacent number of the row below.More
// formally,
// if you are on index i on the current row, you may move to either
// index i or index i + 1 on the next row.
// Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
// Output: 11
// The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11