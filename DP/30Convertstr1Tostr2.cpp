#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
#include <vector>
using namespace std;

int lcs(string s, string t)
{
    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = 0;
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

// str1 -> abcd ; str2 -> anc.
// lcs = ac.
// Deletion -> Just remove elements which are not common in both the string(i.e. remove lcs).
// eg -> abcd -> ac (removed bd).
// insertion -> Just add elements which are not there in str1 after deletion.
// eg -> ac -> anc (added n).
int minOperations(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();

    // return (n + m - 2 * (lcs(str1, str2)));
    int deletion = n - lcs(str1, str2);
    int insertion = m - lcs(str1, str2);
    return insertion + deletion;
}

int main(int argc, char const *argv[])
{

    return 0;
}
