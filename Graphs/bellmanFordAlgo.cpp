#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

struct node
{
    int u;
    int v;
    int wt;
    node(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<node> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(node(u, v, wt));
    }

    int src;
    cin >> src;

    int inf = 10000000;
    vector<int> dist(n, inf);

    // dist array with source elemene 0 and rest element infinity.
    dist[src] = 0;

    // applying relaxation n-1 times.
    for (int i = 1; i <= n - 1; i++)
    {
        for (auto it : edges)
        {
            if (dist[it.u] + it.wt < dist[it.v])
            {
                dist[it.v] = dist[it.u] + it.wt;
            }
        }
    }

    // Check if after N-1 time we can still decrease distance than
    // it means we have negative cycle.
    int fl = 0;
    for (auto it : edges)
    {
        if (dist[it.u] + it.wt < dist[it.v])
        {
            cout << "Negative Cycle";
            fl = 1;
            break;
        }
    }

    // if flag = 0 -> then it means no -ve cycle is found
    // Hence, return i index and dist[i] array respectively.
    if (!fl)
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << " " << dist[i] << endl;
        }
    }

    return 0;
}
