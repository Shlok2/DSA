#include <iostream>
#include <string.h>
#include <vector>
#include <climits>
using namespace std;
#define V 4

// count represents no. of nodes traversed,initially count is 1,
// when count reaches 1 it means all nodes are traversed.
// graph stores costs for travelling.
// v is visited array.
// curr pos is current location.
// cost is cost upto now.
// ans stores final minimum cost.
void tsp(int graph[][V], vector<bool> &v, int currPos, int n,
         int count, int cost, int &ans)
{
    // if count = n and there is a edge between currPos(lastNode) and
    // first node -> then check ans.
    // graph[currPos][0] != 0 -> means edge is there.
    if (count == n && graph[currPos][0])
    {
        ans = min(ans, cost + graph[currPos][0]);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!v[i] && graph[currPos][i])
        {
            v[i] = true;
            tsp(graph, v, i, n, count + 1, cost + graph[currPos][i], ans);
            v[i] = false;
        }
    }
}

int main(int argc, char const *argv[])
{
    int n = 4;

    // graph shows cost between vertices.
    int graph[][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}};

    vector<bool> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i] = false;
    }

    v[0] = true;
    int ans = INT_MAX;
    tsp(graph, v, 0, n, 1, 0, ans);
    cout << ans;

    return 0;
}
