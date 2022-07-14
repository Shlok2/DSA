#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int N, m;
    cin >> N >> m;
    vector<pair<int, int>> adj[N];
    int a, b, wt;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> wt;
        adj[a].push_back(make_pair(b, wt));
        adj[b].push_back(make_pair(a, wt));
    }

    int key[N];
    bool mstSet[N];
    int parent[N];

    for (int i = 0; i < N; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Min heap.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // first element of key arr is 0 and also push first element (0) with
    // 0 index in pq.
    key[0] = 0;
    parent[0] = -1;
    // pushing weight and node in pq.
    pq.push({0, 0});

    while (!pq.empty())
    {
        // u -> index of 'smallest value in key'(As heap is used).
        int u = pq.top().second;
        pq.pop();

        // make mst[u] as true.
        mstSet[u] = true;

        // For its adjacent edges.
        for (auto it : adj[u])
        {
            // v is adjacent element.
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v])
            {
                parent[v] = u;
                key[v] = weight;
                pq.push({key[v], v});
            }
        }
    }

    cout << "MST is:" << endl;
    for (int i = 1; i < N; i++)
    {
        cout << parent[i] << " - " << i << endl;
    }
    return 0;
}
