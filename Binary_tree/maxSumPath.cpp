#include <bits/stdc++.h>
#include <string.h>
using namespace std;

struct node
{
    int data;
    node *left, *right;
};

node *newnode(int val)
{
    node *temp = new node;
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

int maxpathsumutil(node *root, int &ans)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = maxpathsumutil(root->left, ans);
    int right = maxpathsumutil(root->right, ans);

    // To find the max of 4 values founded for each node.
    int nodemax = max(max(root->data, left + right + root->data), max(root->data + left, root->data + right));

    // To store max of (nodemax or ans) to ans.

    ans = max(nodemax, ans);

    // left + right + root->data is not passed because this include both left and right subtree of root and hence
    // now it is not a singular path.we cannot include anscestor of root in this condition.
    int singlepathsum = max(root->data, max(root->data + left, root->data + right));
    return singlepathsum;
}

int maxpathsum(node *root)
{
    // INT_MIN store the lowest possible value for ans(i.e. near to -infinity. so that the first root->data(leaf node)
    // should always be greater than ans)
    int ans = INT_MIN;
    maxpathsumutil(root, ans);
    return ans;
}

int main(int argc, char const *argv[])
{
    node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->right->right = newnode(5);
    cout << maxpathsum(root) << endl;
    return 0;
}
