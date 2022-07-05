#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
#include <vector>
using namespace std;

string shortestCommonSupersequence(string s, string t)
{
    // To make normal lcs table.
    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
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

    // main code starts.
    string ans = "";
    int i = n, j = m;

    // if elements are same in a string then just add one of them
    // in ans and then do i-- and j-- pointer.
    // and if elements are not same then increase ptr of any one
    // str and include that element in ans.
    // eg -> s1 = brute and s2 = groot.
    // at i = e and j = t -> b != j -> hence do i-- and add
    // e in ans. -> ans = e
    // not i = t and j = t -> same -> hence i-- and j--
    // and add t in answer once. -> ans = et
    // By repeating these step final ans will be ans = etouorbg
    // but we started indexing of i and j from last and hence
    // reverse the ans.
    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            ans += s[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            ans += s[i - 1];
            i--;
        }
        // if dp[i][j-1] > dp[i-1][j];
        else
        {
            ans += t[j - 1];
            j--;
        }
    }

    // if j becomes 0 but i don't -> then include all remaining i elements
    while (i > 0)
    {
        ans += s[i - 1];
        i--;
    }

    // if i becomes 0 but j don't -> then include all remaining j elements
    while (j > 0)
    {
        ans += t[j - 1];
        j--;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main(int argc, char const *argv[])
{

    return 0;
}
