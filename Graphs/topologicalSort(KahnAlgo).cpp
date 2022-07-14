#include <iostream>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

vector<int> topoSort(int n, vector<int> adj[])
{
    queue<int> q;

    // Making vector indegree ans initiallising all
    // its values as 0.
    vector<int> indegree(n, 0);

    // forming indegree array. indegree will be no. of
    // outgoing edges from a node -> hence we can count
    // indegree just by counting no. of adj elements.
    for (int i = 0; i < n; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    // push elements with indegree 0 to queue.
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto it : adj[node])
        {
            // Node ki adjacent ki indegree ko kum kar do.
            indegree[it]--;

            // Aur agar indegree 0 ho gyi-> toh usse queue
            // me push kar do.
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    return topo;
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;

    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        // adj[v].push_back(u);
    }

    vector<int> ans;
    ans = topoSort(n, adj);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
