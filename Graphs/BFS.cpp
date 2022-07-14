#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

// N = 10^5 + 2 (Just a constant).
const int N = 1e5 + 2;

int main(int argc, char const *argv[])
{
    vector<int> adj[N];
    bool vis[N];
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

    queue<int> q;

    // push first node.
    // This is just for our example graph,
    // If we change the graph we have to change this
    // first node also(instead of 1 write the first
    // node from where you have to start traversal).
    // also change x in vis[x]=true -> where x is node.
    q.push(1);
    vis[1] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << endl;

        vector<int>::iterator it;
        for (it = adj[node].begin(); it != adj[node].end(); it++)
        {
            if (!vis[*it])
            {
                vis[*it] = 1;
                q.push(*it);
            }
        }
    }
    return 0;
}

// BFS FUNCTION
//
// void bfs(int c, bool vis[], vector<int> adj[])
// {
//     queue<int> q;
//     q.push(c);
//     vis[c] = true;

//     while (!q.empty())
//     {
//         int node = q.front();
//         q.pop();
//         cout << node << endl;

//         vector<int>::iterator it;
//         for (it = adj[node].begin(); it != adj[node].end(); it++)
//         {
//             if (!vis[*it])
//             {
//                 vis[*it] = 1;
//                 q.push(*it);
//             }
//         }
//     }
// }
