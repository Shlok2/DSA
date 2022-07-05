// Given two strings s and t, return the number of distinct subsequences of s which equals t.
// A string's subsequence is a new string formed from the original string by deleting some
// (can be none) of the characters without disturbing the remaining characters' relative positions.
//  (i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).

// Input: s = "babgbag", t = "bag"
// Output: 5
// Explanation:
// As shown below, there are 5 ways you can generate "bag" from S.
// babgbag
// babgbag
// babgbag
// babgbag
// babgbag

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

// 1-based indexing
int f(int i, int j, string s, string t, vector<vector<int>> &dp)
{

    // if j < 0 -> that means j word is already found in s1 -> hence return 1(as we have to count
    // all possible ways).
    // We are using 1 - based indexing -> hence we use for j == -1 (+1) = 0.
    if (j == 0)
    {
        return 1;
    }

    // if i < 0 but j is still greater than equal to 0 -> then return false.
    // We are using 1 - based indexing -> hence we use for i == -1 (+1) = 0.
    if (i == 0)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    // If two elements are same in both string s and t -> then either we take that element
    // of i or we dont take that element of i.(use + sign as we our counting our total
    // possibilities).-> if we take that element from s -> then we also do j-1, as
    // we took that element. But if we dont take that element than we just do i-1 and
    // not j-1 as we are not taking element from s.
    // eg -> s = bagbag ; t = bag.
    // i = n-1 (at g) and t = m-1 (at g) -> they both are same (s[i-1] = t[i-1]) ->
    // if we take that g from s -> then we call for i-1 and j-1(meaning i,j are
    // a and a.) '+'
    // if we dont take that g from s -> then we just call for i-1(meaning i,j are
    // a and g).
    if (s[i - 1] == t[j - 1])
    {
        return dp[i][j] = (f(i - 1, j - 1, s, t, dp) + f(i - 1, j, s, t, dp));
    }

    else
    {
        return dp[i][j] = f(i - 1, j, s, t, dp);
    }
}

// 1 - based indexing
int numDistinct(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return f(n, m, s, t, dp);
}

// tabulation
int numDistinct2(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    // We will start loop from 1 because of first
    // box of table will be rewrited.
    for (int j = 1; j <= m; j++)
    {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][m];
}

int main(int argc, char const *argv[])
{

    return 0;
}
