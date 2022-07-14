#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
const int N = 1e5 + 2;
vector<int> adj[N];
bool vis[N];

void dfs(int node)
{
    vis[node] = 1;
    cout << node << " ";

    vector<int>::iterator it;
    for (it = adj[node].begin(); it != adj[node].end(); it++)
    {
        if (!vis[*it])
        {
            dfs(*it);
        }
    }
}

int main(int argc, char const *argv[])
{
    for (int i = 0; i < N; i++)
    {
        vis[i] = 0;
    }
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // To call dfs from node 1.
    dfs(1);
    return 0;
}
