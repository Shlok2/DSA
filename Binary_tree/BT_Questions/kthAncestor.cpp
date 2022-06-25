#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

struct node
{
    int data;
    node *left, *right;
    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

node *temp = NULL;

node *KthAncestor(node *root, int &k, int val)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == val || (temp = KthAncestor(root->left, k, val)) || (temp = KthAncestor(root->right, k, val)))
    {
        if (k > 0)
        {
            k--;
        }
        else if (k == 0)
        {
            cout << "The kth ancester of node is: " << root->data;
            // return Null to stop further backtracking.
            return NULL;
        }
        // return current node to previous call.
        return root;
    }
}

int main(int argc, char const *argv[])
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    int k = 2;
    int Node = 5;
    vector<int> v;

    node *parent = KthAncestor(root, k, Node);

    // if parent is not null,it means there
    // is no Kth ancestor of the node.
    if (parent)
    {
        cout << "-1";
    }
    return 0;
}
