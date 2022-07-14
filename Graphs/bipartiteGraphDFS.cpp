#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

bool bipartiteDfs(int node, vector<int> adj[], int color[])
{

    // If we are starting with first node of a component
    // then initiallise it with 1.
    if (color[node] == -1)
    {
        color[node] = 1;
    }

    // for adj nodes check if color[adj node] is still not
    // colored(i.e. -1) -> then color it with opposite node
    // of node and then run a reccursive(dfs) function.
    for (auto it : adj[node])
    {
        if (color[it] == -1)
        {
            color[it] = !color[node];
            if (!bipartiteDfs(it, adj, color))
            {
                return false;
            }
        }

        // if adj node is initially colored and
        // it has same color as of node ->
        // then return false.
        else if (color[it] == color[node])
        {
            return false;
        }
    }
    return true;
}

bool checkBipartite(vector<int> adj[], int n)
{
    int color[n];
    memset(color, -1, sizeof color);
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {

            // If any comp is not bipartite then return
            // false.
            if (!bipartiteDfs(i, adj, color))
            {
                return false;
            }
        }
    }
    return true;
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
        adj[v].push_back(u);
    }

    if (checkBipartite(adj, n))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
