#include <iostream>
#include <string.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> largestDivisibleSubset(vector<int> &nums)
{
    // Initiallise dp arr with 1.
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> hash(n);
    int maxi = 1;
    int lastIndex = 0;

    // ->Only difference is sorting the array and in line 25 of taking modulo. else
    // full code is same as of 42longestIncreasingSubsequence.

    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        // For a particular index(i) we made pointer prev to check all previous
        // elements of index i.
        for (int prev = 0; prev < i; prev++)
        {
            if (nums[i] % nums[prev] == 0 && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            lastIndex = i;
        }
    }
    vector<int> temp;
    temp.push_back(nums[lastIndex]);
    while (hash[lastIndex] != lastIndex)
    {
        lastIndex = hash[lastIndex];
        temp.push_back(nums[lastIndex]);
    }
    reverse(temp.begin(), temp.end());

    return temp;
}

int main(int argc, char const *argv[])
{

    return 0;
}
