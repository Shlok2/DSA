
// Find shortest distance between 2 nodes.

#include <iostream>
#include <string.h>
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

node *LCA(node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    node *left = LCA(root->left, n1, n2);
    node *right = LCA(root->right, n1, n2);

    if (left != NULL && right != NULL)
    {
        return root;
    }
    if (left == NULL && right == NULL)
    {
        return NULL;
    }
    if (left != NULL)
    {
        return LCA(root->left, n1, n2);
    }
    else
    {
        return LCA(root->right, n1, n2);
    }
    return root;
}

// dis is distance between root and k.
int findDis(node *root, int k, int dis)
{
    if (root == NULL)
    {
        return -1;
    }

    if (root->data == k)
    {
        return dis;
    }

    // Because we are moving from root to root->left ->
    // Hence our distance will be increased by one.
    int left = findDis(root->left, k, dis + 1);

    // If we found left in leftSubtree -> then return left
    // If we don't find left -> then find and return right.
    if (left != -1)
    {
        return left;
    }
    else
    {
        // Because we are moving from root to root->right ->
        // Hence our distance will be increased by one.
        int right = findDis(root->right, k, dis + 1);
        if (right != -1)
        {
            return right;
        }
    }
}

int distanceBetweenNodes(node *root, int n1, int n2)
{
    node *lca = LCA(root, n1, n2);
    int d1 = findDis(lca, n1, 0);
    int d2 = findDis(lca, n2, 0);

    return d1 + d2;
}

// node *shortestDistance(node *root, int n1, int n2, int &dis)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     // int dis = 0;
//     if (root->data == n1 || root->data == n2)
//     {
//         return root;
//     }
//     dis++;
//     shortestDistance(root->left, n1, n2);
//     shortestDistance(root->right, n1, n2);
//     return dis;
// }

int main(int argc, char const *argv[])
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->right = new node(5);
    cout << distanceBetweenNodes(root, 4, 5) << endl;
    return 0;
}
