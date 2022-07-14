#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, m, source;
    cin >> n >> m;
    // 1 - indexed adjacency list for graph.
    vector<pair<int, int>> g[n + 1];
    int a, b, wt;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> wt;
        g[a].push_back(make_pair(b, wt));
        g[b].push_back(make_pair(a, wt));
    }

    // source -> From where we have to find distance.
    cin >> source;

    // min heap.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // 1- indexed array for calculating distance.
    vector<int> distTo(n + 1, INT_MAX);

    distTo[source] = 0;
    // (dist,from) -> from -> 'node' from where we have to find dist.
    pq.push(make_pair(0, source));

    while (!pq.empty())
    {
        // dist is distance from source.
        // prev is curr node for which we are taking adjacents.
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();

        // iterate all adj node of current node(initially from).
        vector<pair<int, int>>::iterator it;
        for (it = g[prev].begin(); it != g[prev].end(); it++)
        {
            // it.first -> adj node
            // it.second -> weight btw node and adj node.
            int next = it->first;
            int nextDist = it->second;

            // distTo[prev] = dist.
            if (distTo[next] > distTo[prev] + nextDist)
            {
                distTo[next] = distTo[prev] + nextDist;
                pq.push(make_pair(distTo[next], next));
            }
        }
    }

    cout << "The distances from source " << source << " are:" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << distTo[i] << " ";
    }
    cout << endl;
    return 0;
}
