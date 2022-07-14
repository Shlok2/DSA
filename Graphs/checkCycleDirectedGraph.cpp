// #include <iostream>
// #include <string.h>
// #include <vector>
#include <bits/stdc++.h>
using namespace std;

bool checkCycle(int node, vector<int> adj[], int vis[], int dfsVis[])
{
    vis[node] = 1;
    dfsVis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (checkCycle(it, adj, vis, dfsVis))
            {
                return true;
            }
        }

        // if node is visited (i.e. vis[it] = 1)
        // and dfsVis[it] = 1.
        else if (dfsVis[it])
        {
            return true;
        }
    }
    dfsVis[node] = 0;
    return false;
}

bool isCyclic(int n, vector<int> adj[])
{
    int vis[n], dfsVis[n];

    // Initiallise vis and non visited array every
    // element with 0.
    memset(vis, 0, sizeof vis);
    memset(dfsVis, 0, sizeof dfsVis);

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (checkCycle(i, adj, vis, dfsVis))
            {
                return true;
            }
        }
    }
    return false;
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

    bool ans = isCyclic(n, adj);
    if (ans)
    {
        cout << "1" << endl;
    }
    else
    {
        cout << "0" << endl;
    }
    return 0;
}

// 9 10
// 1 2
// 2 3
// 3 4
// 4 5
// 3 6
// 6 5
// 7 2
// 7 8
// 8 9
// 9 7
