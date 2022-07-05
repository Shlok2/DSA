#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int f(string s, string t, int i, int j, vector<vector<int>> &dp)
{
    if (i < 0)
    {
        return j + 1;
    }
    if (j < 0)
    {
        return i + 1;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if (s[i] == t[j])
    {
        return dp[i][j] = 0 + f(s, t, i - 1, j - 1, dp);
    }

    else
    {
        int insertion = 1 + f(s, t, i, j - 1, dp);
        int deletion = 1 + f(s, t, i - 1, j, dp);
        int replacement = 1 + f(s, t, i - 1, j - 1, dp);
        return dp[i][j] = min(insertion, min(deletion, replacement));
    }
}

// 1 - based indexing
// int f(string s, string t, int i, int j, vector<vector<int>> &dp)
// {
//     if (i == 0)
//     {
//         return j;
//     }
//     if (j == 0)
//     {
//         return i;
//     }

//     if (dp[i][j] != -1)
//     {
//         return dp[i][j];
//     }

//     if (s[i - 1] == t[j - 1])
//     {
//         return dp[i][j] = 0 + f(s, t, i - 1, j - 1, dp);
//     }

//     else
//     {
//         int insertion = 1 + f(s, t, i, j - 1, dp);
//         int deletion = 1 + f(s, t, i - 1, j, dp);
//         int replacement = 1 + f(s, t, i - 1, j - 1, dp);
//         return dp[i][j] = min(insertion, min(deletion, replacement));
//     }
// }

int minDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(word1, word2, n - 1, m - 1, dp);
}

// tabulation
// 1 - based indexing
int minDidstance2(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = j;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
            }
        }
    }
    return dp[n][m];
}

int main(int argc, char const *argv[])
{

    return 0;
}
