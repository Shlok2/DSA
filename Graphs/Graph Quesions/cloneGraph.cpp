#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

class Node
{
public:
    // val stores value of node.
    // neighbours stores neighboring 'nodes'(not int values).
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

void dfs(Node *node, Node *copy, vector<Node *> &vis)
{
    // initially make vis[copy->val] = copy(i.e. store copy node in
    // visited array at copy-> val position).
    // just like vus[1] = 1 in example in copy.
    vis[copy->val] = copy;

    // traverse neighbors of node.
    for (auto x : node->neighbors)
    {
        // if neighbors are not visited than make a new node with value
        // adj node ki value and then push it in (copy ki neighbour) array.
        // and again call dfs for adj node and new node created.
        // Above summary -> 1) make new node with x->val.
        //                  2) push new node in copy -> neighbour
        //                  3) call dfs func node = x and copy = newnode.
        if (vis[x->val] == NULL)
        {
            Node *newNode = new Node(x->val);
            (copy->neighbors).push_back(newNode);
            dfs(x, newNode, vis);
        }

        // If vis[x->val] != NULL -> then just push vis[x->val] to copy ka neighbor.
        else
        {
            (copy->neighbors).push_back(vis[x->val]);
        }
    }
}

Node *cloneGraph(Node *node)
{
    if (node == NULL)
    {
        return NULL;
    }
    vector<Node *> vis(1000, NULL);

    // copy will store our final copy graph.
    Node *copy = new Node(node->val);

    // node -> original graph node from where we want to copy.
    // copy -> copy graph to be created.
    // vis -> to store 'node'(not int) of copy graph.
    dfs(node, copy, vis);
    return copy;
}

int main(int argc, char const *argv[])
{

    return 0;
}

// Given a reference of a node in a connected undirected graph.

// Return a deep copy (clone) of the graph.

// Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

// class Node {
//     public int val;
//     public List<Node> neighbors;
// }
//
// Note ->
//
// For simplicity, each node's value is the same as the node's
// index (1-indexed). For example, the first node with val == 1,
// the second node with val == 2, and so on. The graph is represented
// in the test case using an adjacency list.

// Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
// Output: [[2,4],[1,3],[2,4],[1,3]]
