#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

const int N = 1e5 + 2;

bool checkForCycle(int s, int n, vector<int> adj[], vector<int> &vis)
{
    queue<pair<int, int>> q;
    vis[s] = true;
    q.push({s, -1});

    while (!q.empty())
    {
        int node = q.front().first;
        // parent
        int par = q.front().second;
        q.pop();

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = true;
                q.push({it, node});
            }
            // if it is visited (i.e. vis[it] = true) and parent != it->
            // than return true.
            else if (par != it)
            {
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int n, vector<int> adj[])
{
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (checkForCycle(i, n, adj, vis))
            {
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    // bool vis[N];
    // for (int i = 0; i < N; i++)
    // {
    //     vis[i] = 0;
    // }
    int n, m;
    vector<int> adj[n];
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (isCycle(n, adj))
    {
        cout << "Yes,it have a cycle" << endl;
    }
    else
    {
        cout << "No,it don't have a cycle" << endl;
    }
    return 0;
}
