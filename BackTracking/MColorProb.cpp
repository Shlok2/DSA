#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

// col -> color trying to assign to current node.
bool isSafe(int node, int color[], bool graph[101][101], int n, int col)
{
    for (int k = 0; k < n; k++)
    {
        // if it is not the node itself, and if it is adj of node,
        // and adj node color is equal to color we want to assign
        // -> then it is not possible (as adj color can not be same)
        // Hence return false.
        if (k != node && graph[k][node] == 1 && color[k] == col)
        {
            return false;
        }
    }
    return true;
}

// m is amount of colors(eg -> 4 colors ->1,2,3,4)
// N is no. of nodes.
bool solve(int node, int color[], int m, int N, bool graph[101][101])
{
    if (node == N)
    {
        return true;
    }

    for (int i = 1; i <= m; i++)
    {
        if (isSafe(node, color, graph, N, i))
        {
            color[node] = i;
            if (solve(node + 1, color, m, N, graph))
            {
                return true;
            }
            color[node] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int N)
{
    int color[N] = {0};
    if (solve(0, color, m, N, graph))
    {
        return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int n, m, e;
    cin >> n >> m >> e;
    int i;
    bool graph[101][101];
    for (int i = 0; i < n; i++)
    {
        memset(graph[i], 0, sizeof(graph[i]));
    }
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a - 1][b - 1] = 1;
        graph[b - 1][a - 1] = 1;
    }
    cout << graphColoring(graph, m, n) << endl;
    return 0;
}
