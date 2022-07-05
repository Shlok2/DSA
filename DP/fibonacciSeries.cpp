
// Fibonacci Series -> 0 1 1 2 3 5 8 13 21 ......

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

// Memoization -> ans then check base case.
int f(int n, vector<int> &dp)
{
    // base case -> if n=0 or n=1 then return 0,1 respectively.
    if (n <= 1)
    {
        return n;
    }

    // If at any point dp[n] != -1 then return value of dp[n].
    if (dp[n] != -1)
    {
        return dp[n];
    }

    // store dp[n] as sum of its previous two elemnents.
    return dp[n] = f(n - 1, dp) + f(n - 2, dp);
}

// Tabulation -> base case then ans.
int f2(int n, vector<int> &dp)
{
    // initiallise dp of base case first.
    dp[0] = 0;
    dp[1] = 1;

    // then for rest elements do calculation.
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << "Using memoization: " << f(n, dp);
    cout << endl;
    cout << "Using tabulation: " << f2(n, dp);
    return 0;
}
