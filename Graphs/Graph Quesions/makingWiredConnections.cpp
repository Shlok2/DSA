#include <iostream>
#include <string.h>
#include <vector>
#include <unordered_map>
using namespace std;

void DFS(unordered_map<int, vector<int>> &adj, int curr, vector<bool> &visited)
{
    visited[curr] = true;
    for (auto i : adj[curr])
    {
        if (visited[i] == false)
        {
            DFS(adj, i, visited);
        }
    }
}

int makeConnected(int n, vector<vector<int>> &connections)
{
    vector<bool> visited(n, false);
    unordered_map<int, vector<int>> adj;

    // edges is to calculate total edges.
    // 1) -> make adj list of graph
    //       and also increase edges on the way.
    int edges = 0;
    for (int i = 0; i < connections.size(); i++)
    {
        adj[connections[i][0]].push_back(connections[i][1]);
        adj[connections[i][1]].push_back(connections[i][0]);
        edges += 1;
    }

    // 2) -> find no. of components.
    // if visited of i = false increase component by 1.
    int components = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            components++;
            DFS(adj, i, visited);
        }
    }

    // If edges < n-1 -> then connect graph not possible.
    if (edges < n - 1)
    {
        return -1;
    }

    // 3) -> find no. of redundant edges.
    // and if redundant edges >= components-1 -> then
    // return (component - 1).
    int redundant = edges - ((n - 1) - (components - 1));
    if (redundant >= (components - 1))
    {
        return components - 1;
    }
    else
    {
        return -1;
    }
}

int main(int argc, char const *argv[])
{

    return 0;
}

// Explanation ->
//
// There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi]
// represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.
// You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place
// them between any pair of disconnected computers to make them directly connected.
// Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.
//
// Input: n = 4, connections = [[0,1],[0,2],[1,2]]
// Output: 1