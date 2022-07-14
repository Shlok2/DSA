#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

// N = 10^5 + 2 (Just a constant).
const int N = 1e5 + 2;

int main(int argc, char const *argv[])
{
    // n -> no. of vertices.
    // m -> no. of edges.
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        // use both condition below in case of undirected.
        // Ans use first condition only in case of directed.
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "Adjacency List of above graph is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << "->";
        vector<int>::iterator it;
        for (it = adj[i].begin(); it != adj[i].end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    return 0;
}

// For weighted Graph

// int main(int argc, char const *argv[])
// {
//     int n, m;
//     cin >> n >> m;
//     vector<pair<int, int>> adj[n];
//     for (int i = 0; i < m; i++)
//     {
//         int u, v, wt;
//         cin >> u >> v >> wt;

//         adj[u].push_back({v, wt});
//         adj[v].push_back({u, wt});
//     }
//     return 0;
// }
