#include <iostream>
#include <string.h>
#include <vector>
#include <stack>
using namespace std;
const int N = 1e5 + 2;
vector<int> adj[N];
bool vis[N];

// Steps ->
// 1) mark node as visited
// 2) If adj of that node is not visited -> then call func for that node.
// 3) After no adj left ,then start pushing in stack.
void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[])
{
    vis[node] = 1;
    vector<int>::iterator it;
    for (it = adj[node].begin(); it != adj[node].end(); it++)
    {
        if (!vis[*it])
        {
            findTopoSort(*it, vis, st, adj);
        }
    }

    // Only thing different from DFS function is We are
    // pushing it in stack after traversing to last reccursive call.
    st.push(node);
}

vector<int> topoSort(int n, vector<int> adj[])
{
    stack<int> st;
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            findTopoSort(i, vis, st, adj);
        }
    }
    vector<int> topo;
    while (!st.empty())
    {
        topo.push_back(st.top());
        st.pop();
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

        // Making dirested graph.
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
