#include <iostream>
#include <string.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Same function of maxSumOfNonAdjElements.cpp file.
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

int houseRobber(vector<int> &valueInHouse)
{
    vector<int> temp1, temp2;
    int n = valueInHouse.size();
    if (n == 1)
    {
        return valueInHouse[0];
    }
    for (int i = 0; i < n; i++)
    {
        // Insert every element exept first in temp1.
        if (i != 0)
        {
            temp1.push_back(valueInHouse[i]);
        }

        // Insert every element exept last in temp2.
        if (i != n - 1)
        {
            temp2.push_back(valueInHouse[i]);
        }
    }

    // Max of maximumNonAdjSum(temp1),maximumNonAdjSum(temp2) will give ans.
    return max(maximumNonAdjSum(temp1), maximumNonAdjSum(temp2));
}

int main(int argc, char const *argv[])
{
    vector<int> valueInHouse = {2, 3, 2};
    cout << houseRobber(valueInHouse) << endl;
    return 0;
}
