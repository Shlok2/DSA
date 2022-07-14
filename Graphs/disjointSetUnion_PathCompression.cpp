#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int Rank[100000];
int parent[100000];
int n;

// To make every element of rank array = 0 initially.
// and to make every element as its own parent initially.
void makeSet()
{
    for (int i = 1; i <= n; i++)
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

void Union(int u, int v)
{
    u = findPar(u);
    v = findPar(v);

    // jiska size chota hoga usse connect karenge.
    if (Rank[u] < Rank[v])
    {
        parent[u] = v;
    }
    else if (Rank[v] < Rank[u])
    {
        parent[v] = u;
    }
    // if rank[v] = rank[u] -> we can join any.
    else
    {
        parent[v] = u;
        Rank[u]++;
    }
}

int main(int argc, char const *argv[])
{
    return 0;
}
