// You want to build an expression out of nums by adding one of the
// symbols '+' and '-' before each integer in nums and then concatenate
// all the integers.
//     For example, if nums = [2, 1], you can add a '+' before 2 and
// a '-' before 1 and concatenate them to build the expression "+2-1".
// Return the number of different expressions that you can build,
// which evaluates to target.
// Input: nums = [1,1,1,1,1], target = 3
// Output: 5
// Explanation: There are 5 ways to assign symbols to make the sum
// of nums be target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

// This code is of lecture 18(count Subset With Sum k) -> As this question
// Can be interpreted as sum of 2 subset whose sum equals
int f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
    {
        return 1;
    }
    if (ind == 0)
    {
        return (arr[0] == target);
    }
    if (dp[ind][target] != -1)
    {
        return dp[ind][target];
    }

    int notPick = f(ind - 1, target, arr, dp);
    int pick = 0;
    if (arr[ind] <= target)
    {
        pick = f(ind - 1, target - arr[ind], arr, dp);
    }
    return dp[ind][target] = pick + notPick;
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    return f(n - 1, tar, num, dp);
}

int countPartition(int n, int d, vector<int> &arr)
{
    int totalSum = 0;
    for (auto &it : arr)
    {
        totalSum += it;
    }
    if (totalSum - d < 0 || (totalSum - d) % 2)
    {
        return false;
    }
    return findWays(arr, (totalSum - d) / 2);
}

int targetSum(int n, int target, vector<int> &arr)
{
    // int n = arr.size();
    return countPartition(n, target, arr);
}

int main(int argc, char const *argv[])
{

    return 0;
}
