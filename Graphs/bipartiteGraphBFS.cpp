#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

bool bipartiteBFS(int src, vector<int> adj[], int color[])
{
    queue<int> q;
    q.push(src);
    color[src] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto it : adj[node])
        {
            // if color[adjacent] is -1 -> not colored yet.
            // Then color it with opposite of main node(it).
            // and push it in queue.
            if (color[it] == -1)
            {
                color[it] = !color[node];
                q.push(it);
            }

            // if color[adj] is not -1 and color[it]
            // = color[node] then adj nodes have same
            // color and hence return false.
            else if (color[it] == color[node])
            {
                return false;
            }
        }
    }
    return true;
}

bool checkBipartite(vector<int> adj[], int n)
{
    int color[n];

    // Just to initiallise color arr with -1.
    memset(color, -1, sizeof color);
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            // if any component is not bipartite then whole graph is
            // not bipartite.
            if (!bipartiteBFS(i, adj, color))
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
