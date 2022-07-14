#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
const int N = 1e5 + 2;

bool checkForCycle(int node, int parent, vector<int> &vis, vector<int> adj[])
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (vis[it] == 0)
        {
            if (checkForCycle(it, node, vis, adj))
            {
                return true;
            }
        }

        // if visited and it != parent.
        // if adj of node is already visited and it is not equal to
        // its parent node that means cycle is present.
        else if (it != parent)
        {

            return true;
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
            if (checkForCycle(i, -1, vis, adj))
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

        // Making directed graph.
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool ans = isCycle(n, adj);
    if (ans)
    {
        cout << "Yes,it has a cycle" << endl;
    }
    else
    {
        cout << "No,it doesn't have a cycle" << endl;
    }
    return 0;
}
