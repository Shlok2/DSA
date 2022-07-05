#include <iostream>
#include <string.h>
#include <vector>
#include <bits/stdc++.h>
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

// Just reverse the string and call longest common substring for both.
// as both s and t are reverse and hence longest common subsequence we get will
// also  be reverse (palindrome).
// eg -> s = bbabcbcab
//       t = bacbcbabb
// Hence lcs in s and t is -> babcbab(Which is longest palindrome possible).

int longestPalindromeSubseq(string s)
{
    string t = s;
    reverse(t.begin(), t.end());
    return lcs(s, t);
}

int main(int argc, char const *argv[])
{

    return 0;
}
