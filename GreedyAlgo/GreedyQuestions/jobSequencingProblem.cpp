//  CodeLibrary - by Yogesh & Shailesh
//
// Given an array of jobs where every job has a deadline and associated profit if the job
// is finished before the deadline. It is also given that every job takes a single unit
// of time, so the minimum possible deadline for any job is 1. How to maximize total profit
// if only one job can be scheduled at a time.
//
// Input - Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
// Output - 2 60 -> 2(days),60(profit(val))
//
// Input:  Five Jobs with following
// deadlines and profits
// JobID   Deadline  Profit
//   a       2        100
//   b       1        19
//   c       2        27
//   d       1        25
//   e       3        15
// Output: Following is maximum
// profit sequence of jobs
//         c, a, e

#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

struct Job
{
    int id;
    int deadline;
    int profit;
};

static bool comp(Job a, Job b)
{
    return a.profit > b.profit;
}

vector<int> printJobScheduling(Job arr[], int n)
{
    sort(arr, arr + n, comp);

    // This function shows that done[i]->ith slot is
    // already filled or not.Initially none slot is
    // filled -> Hence initialise all by false.
    // bool done[n] = {0};
    bool done[n];
    for (int i = 0; i < n; i++)
    {
        done[i] = false;
    }

    // val -> shows max profit
    // days -> max days needed.
    int days = 0, val = 0;

    for (int i = 0; i < n; i++)
    {
        // To check all indexes from j->0(j--) in 'done' array that is
        // there any place with done[j] = false.
        for (int j = min(n, arr[i].deadline - 1); j >= 0; j--)
        {
            if (done[j] == false)
            {
                days++;
                val += arr[i].profit;
                done[j] = true;
                break;
            }
        }
    }
    return {days, val};
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    Job a[n];
    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        a[i].id = x;
        a[i].deadline = z;
        a[i].profit = y;
    }
    cout << "Following is no. of days and maximum profit sequence of jobs \n";

    // Function call
    vector<int> ans;
    ans = printJobScheduling(a, n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
