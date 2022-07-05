// very same as frog jump question but only difference is we can jump 1 to k jumps at a time instead of 1|2 jumps.

#include <bits/stdc++.h>
using namespace std;

// ------memoization------

int f(int ind, vector<int> &height, vector<int> &dp, int k)
{
    if (ind == 0)
    {
        return 0;
    }
    if (dp[ind] != -1)
    {
        return dp[ind];
    }

    int jump;
    int minSteps = INT_MAX;

    for (int j = 1; j <= k; j++)
    {
        if (ind - j >= 0)
        {
            jump = f(ind - j, height, dp, k) + abs(height[ind] - height[ind - j]);
            minSteps = min(minSteps, jump);
        }
    }
    return dp[ind] = minSteps;
}

int frogJump(int n, vector<int> &height, int k)
{
    vector<int> dp(n + 1, -1);
    return f(n - 1, height, dp, k);
}

int main(int argc, char const *argv[])
{
    int n = 6;
    vector<int> height = {30, 10, 60, 10, 60, 50};
    int k = 4;
    cout << frogJump(n, height, k) << endl;
    return 0;
}
