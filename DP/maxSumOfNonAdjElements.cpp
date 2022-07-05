#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

// ------ Memoization ------
int f(int ind, vector<int> &num, vector<int> &dp)
{
    // if we reach first element then just return value of first element.
    // if we reach first element then we can't reach 1st element
    // as 1st element is adj of 0th element.
    if (ind == 0)
    {
        return num[0];
    }

    // if we reached 1st element and than chose pick then it will take to
    // f(1 - 2) -> i.e. f(-1) -> then return 0.
    if (ind < 0)
    {
        return 0;
    }

    // memoization step 3.
    if (dp[ind] != -1)
    {
        return dp[ind];
    }

    int pick = num[ind] + f(ind - 2, num, dp);

    // adding 0 shows that we are not taking current ind.
    int notPick = 0 + f(ind - 1, num, dp);

    // memoization step 2.
    return dp[ind] = max(pick, notPick);
}

int maximumNonAdjSum(vector<int> &num)
{
    int n = num.size();
    vector<int> dp(n, -1);
    return f(n - 1, num, dp);
}

// ------ Tabulation ------
// int f2(vector<int> &num, vector<int> &dp)
// {
//     int n = num.size();
//     dp[0] = num[0];
//     int neg = 0;

//     for (int i = 1; i < n; i++)
//     {
//         int take = num[i];
//         if (i > 1)
//         {
//             take += dp[i - 2];
//         }

//         int notTake = 0 + dp[i - 1];
//         dp[i] = max(take, notTake);
//     }
// }

int main(int argc, char const *argv[])
{
    vector<int> num = {2, 1, 4, 9};
    int ans = maximumNonAdjSum(num);
    cout << ans << endl;
    return 0;
}
