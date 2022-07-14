#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int N = 1e5 + 6;
vector<int> Rank(N);
vector<int> parent(N);

// To make every element of rank array = 0 initially.
// and to make every element as its own parent initially.
void makeSet()
{
    for (int i = 0; i <= N; i++)
    {
        parent[i] = i;
        Rank[i] = 0;
    }
}

// eg - 7,6,4,3
// parent[node] stores parent of node.
int findPar(int node)
{
    // if node is itself parent ->
    // Then that node will be the final parent.
    if (node == parent[node])
    {
        return node;
    }

    // for Path compression.
    // parent[3] = reccursion call.
    return parent[node] = findPar(parent[node]);

    // Without path compression.
    // return findPar(parent[node]);
}

// Union function.

void union_set(int a, int b)
{
    int x, y;
    a = findPar(a);
    b = findPar(b);

    if (a != b)
    {
        if (Rank[a] < Rank[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        Rank[a] += Rank[b];
    }
}

int main(int argc, char const *argv[])
{

    makeSet();
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    bool cycle = false;
    for (auto i : edges)
    {
        int u = i[0];
        int v = i[1];
        int x = findPar(u);
        int y = findPar(v);

        // agar dono ke parent same he -> cycle present.
        if (x == y)
        {
            cycle = true;
        }
        else
        {
            union_set(u, v);
        }
    }

    if (cycle)
    {
        cout << "Cycle is Found" << endl;
    }
    else
    {
        cout << "Cycle not found" << endl;
    }
    return 0;
}
