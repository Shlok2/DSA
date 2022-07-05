#include <iostream>
#include <string.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, string &s, string &t, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    // If element of both i,j(ind1,ind2) are same -> Then just return
    // 1 + (reducing both index).Eg - acd(<-ind1)|ced(<-ind2) -> ind1
    // and ind2 are on d -> Hence 1 + f(c,e).
    if (s[i] == t[j])
    {
        return dp[i][j] = 1 + f(i - 1, j - 1, s, t, dp);
    }

    // if elements are not same then do either ind1 - 1 or ind2 - 1.
    else
    {
        return dp[i][j] = 0 + max(f(i - 1, j, s, t, dp), f(i, j - 1, s, t, dp));
    }
}

int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    return f(n - 1, m - 1, text1, text2, dp);
}

// Tabulation
int lcs(string s, string t)
{
    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int main(int argc, char const *argv[])
{

    return 0;
}
