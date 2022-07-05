#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int longestCommonSubsequence(string s, string t)
{
    // Initially it is the same code as of longestCommonSubsequence.cpp
    // (26 lecture code) to form the table.
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

    // From now main code begins.

    int len = dp[n][m];
    string ans = "";
    // store $ at every index of ans.
    for (int i = 0; i < len; i++)
    {
        ans += "$";
    }

    // initially index is at last of ans string.
    int index = len - 1;
    int i = n, j = m;

    // Run loop till any one of s or t is exausted.
    while (i > 0 && j > 0)
    {
        // if both index has same element (eg -> e,e)
        if (s[i - 1] == t[j - 1])
        {
            ans[index] = s[i - 1];
            index--;
            i--;
            j--;
        }

        // if element is different but in dp 2D array
        // [i-1][j] is greater than [i][j-1].
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }

        // dp[i][j-1] > dp[i-1][j].
        else
        {
            j--;
        }
    }
    cout << ans << endl;
}

int main(int argc, char const *argv[])
{

    return 0;
}
