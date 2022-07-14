#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;

    // Create 2D matrix in form of vector.
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    if (adj[3][7] == 1)
    {
        cout << "There is an edge between 3 and 7" << endl;
    }
    return 0;
}
