// Given a non-empty array nums containing only positive integers,
// find if the array can be partitioned into two subsets such that the
// sum of elements in both subsets is equal.
// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].

// Nearly same code as in Previous lecture,just one extra condition.

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

bool f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    // if at any point target becomes 0.
    if (target == 0)
    {
        return true;
    }

    // if we reached first index from ind-1 -> and if arr[0] == target
    // then return true.
    if (ind == 0)
    {
        return (arr[0] == target);
    }

    if (dp[ind][target] != -1)
    {
        return dp[ind][target];
    }

    // If we dont take curr element than just reduce element and pass it
    // to reccurssion.
    bool notTake = f(ind - 1, target, arr, dp);

    // If curr element is < target and we want to take the element than
    // reduce index and also reduce value of target to target - curr
    // element value.
    bool take = false;
    if (arr[ind] <= target)
    {
        take = f(ind - 1, target - arr[ind], arr, dp);
    }

    return dp[ind][target] = take | notTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return f(n - 1, k, arr, dp);
}

// If sum of all elements is equal to a odd number -> then it cannot be
// divided into two subarrays with equal sum -> Hence return false.
// Else if sum is even ->
// if target = sum/2 is found as 'sum of subarray of vector nums'->
// Then rest subarray sum will also be sum/2 -> Hence return true.
// Else return false.
// eq -> if array -> [1,5,11,5].
// if we find 22/2(=11) as sum of subarray elements -> then we can
// divide this array into partion with equal subset sum.(i.e. 11,(5+5+1))
bool canPartition(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    if (sum % 2 == 1)
    {
        return false;
    }
    int target = sum / 2;
    return subsetSumToK(n, target, nums);
}

int main(int argc, char const *argv[])
{

    return 0;
}
