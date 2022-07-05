#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int MCM(int i, int j, int arr[], vector<vector<int>> &dp)
{

    // when both i and j are same it means there is just single array element and hence
    // it cannot have any steps for multiplication -> Hence return 0.
    // eg -> arr[10,20,30,40,50] -> let say i and j are at 20 -> then it becomes (A)(BCD)
    // and A does not need any multiplications while BCD have steps = ((20 * 30) * (30 * 40) * (40 * 50))
    // = (steps =) (20 * 30 * 40 * 50).
    if (i == j)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int mini = 1e9;

    for (int k = i; k < j; k++)
    {
        int steps = (arr[i - 1] * arr[k] * arr[j]) + MCM(i, k, arr, dp) + MCM(k + 1, j, arr, dp);
        mini = min(mini, steps);
    }
    return dp[i][j] = mini;
}

int matrixMultiplication(int N, int arr[])
{
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return MCM(1, N - 1, arr, dp);
}

// Tabulation
int MCM2(int N, vector<int> arr)
{
    int dp[N][N];

    for (int i = 1; i < N; i++)
    {
        dp[i][i] = 0;
    }

    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < N; j++)
        {
            int mini = 1e9;
            for (int k = i; k < j; k++)
            {
                int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                if (steps < mini)
                {
                    mini = steps;
                }
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][N - 1];
}

int main(int argc, char const *argv[])
{

    return 0;
}
