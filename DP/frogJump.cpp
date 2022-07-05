#include <bits/stdc++.h>
using namespace std;

// ------memoization------

int f(int ind, vector<int> &height, vector<int> &dp)
{
    if (ind == 0)
    {
        return 0;
    }
    if (dp[ind] != -1)
    {
        return dp[ind];
    }

    // left -> first jump with 1 step ; right -> second jump with 2 steps.
    int left = f(ind - 1, height, dp) + abs(height[ind] - height[ind - 1]);
    int right = INT_MAX;
    if (ind > 1)
    {
        right = f(ind - 2, height, dp) + abs(height[ind] - height[ind - 2]);
    }
    return dp[ind] = min(left, right);
}

int frogJump(int n, vector<int> &height)
{
    vector<int> dp(n + 1, -1);
    return f(n - 1, height, dp);
}

// ------Tabulation------

int frogJump2(int n, vector<int> &height)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int fs = dp[i - 1] + abs(height[i] - height[i - 1]);

        int ss = INT_MAX;
        if (i > 1)
        {
            ss = dp[i - 2] + abs(height[i] - height[i - 2]);
        }

        dp[i] = min(fs, ss);
    }
    return dp[n - 1];
}

int main(int argc, char const *argv[])
{
    int n = 6;
    vector<int> height = {30, 10, 60, 10, 60, 50};
    cout << frogJump(n, height) << endl;
    cout << frogJump2(n, height) << endl;
    return 0;
}
