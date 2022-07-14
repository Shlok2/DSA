#include <iostream>
#include <string.h>
#include <vector>
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
    return 0;
}
