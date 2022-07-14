#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, e;
    cin >> n >> e;
    vector<int> g[n + 1];
    vector<int> indegree(n + 1, 0);

    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);

        // as we are pushing y into x -> hence indegree of y is
        // increased.
        indegree[y]++;
    }

    vector<int> ans(n + 1, 0);
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);

            // Since initially whoseever i is 0 -> it will be completed
            // first -> hence ans[i] = 1 where 1 is to denote it will be
            // completed is first unit of time.
            ans[i] = 1;
        }
    }

    while (!q.empty())
    {
        int val = q.front();
        q.pop();

        // To move to adj element of val and reducing the indegree by 1.
        // and if indegree becomes 0 -> then push it into queue and
        // make ans[that element] = ans[its parent] + 1 as it will take
        // one unit more time then its parent.
        for (auto x : g[val])
        {
            indegree[x]--;
            if (indegree[x] == 0)
            {
                ans[x] = ans[val] + 1;
                q.push(x);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}

// Given a Directed Acyclic Graph having V vertices and E edges, where each
//  edge {U, V} represents the Jobs U and V such that Job V can only be
//  started only after completion of Job U. The task is to determine the
//  minimum time taken by each job to be completed where each Job takes
//  unit time to get completed.
//
// Input: can be seen on gfg(graph).
// Output: 1 1 2 2 2 3 4 5 2 6
// Explanation:
// Start the jobs 1 and 2 at the beginning and complete them at 1 unit of time.
// Since, jobs 3, 4, 5, and 9 have the only dependency on one job (i.e 1st job for jobs 3, 4, and 5 and 2nd job for job 9). So, we can
// start these jobs at 1st unit of time and complete these at 2nd unit of time after the completion of the dependent Job.
// Similarly,
// Job 6 can only be done after 3rd and 4th jobs are done. So, start it at 2nd unit of time and complete it at 3rd unit of time.
// Job 7 can only be done after job 6 is done. So, you can start it at 3rd unit of time and complete it at 4th unit of time.
// Job 8 can only be done after 4th, 5th, and 7th jobs are done. So, start it at 4th unit of time and complete it at 5th unit of time.
// Job 10 can only be done after the 8th job is done. So, start it at 5th unit of time and complete it at 6th unit of time.
