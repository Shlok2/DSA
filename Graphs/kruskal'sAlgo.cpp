#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e5 + 6;
vector<int> parent(N);
// sz -> size
vector<int> sz(N);

void make_set(int v)
{
    parent[v] = v;
    sz[v] = 1;
}

// to find parent.
int find_set(int v)
{
    if (v == parent[v])
    {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        // swap if size of b is greater than size of a.
        if (sz[a] < sz[b])
        {
            swap(a, b);
        }

        // join b to a as a is larger.
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main(int argc, char const *argv[])
{
    for (int i = 0; i < N; i++)
    {
        make_set(i);
    }

    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> w >> u >> v;
        edges.push_back({w, u, v});
    }

    // sort array according to weight.
    sort(edges.begin(), edges.end());
    int cost = 0;
    for (auto i : edges)
    {
        int w = i[0];
        int u = i[1];
        int v = i[2];
        int x = find_set(u);
        int y = find_set(v);

        // if x == y -> then it is a cycle and hence
        // we will not include this edge.(Can check
        // cycle detection using dsu).
        if (x == y)
        {

            continue;
        }
        else
        {
            // We included this edge hence print edge
            // and add weight to cost.
            cout << u << " " << v << endl;
            cost += w;
            union_sets(u, v);
        }
    }
    cout << cost << endl;
    return 0;
}
