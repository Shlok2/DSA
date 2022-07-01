#include <iostream>
#include <climits>
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

struct info
{
    int size;
    int min;
    int max;
    int ans;
    bool isBST;
};

info largestBSTinBT(node *root)
{

    // if root is NULL.
    if (root == NULL)
    {
        return {0, INT_MAX, INT_MIN, 0, true};
    }

    // if it is a leaf node.
    if (root->left == NULL && root->right == NULL)
    {
        return {1, root->data, root->data, 1, true};
    }

    info leftinfo = largestBSTinBT(root->left);
    info rightinfo = largestBSTinBT(root->right);

    info curr;
    // curr node ka size = 1 + leftnode ka size + rightnode ka size.
    curr.size = (1 + leftinfo.size + rightinfo.size);

    // if leftinfo and rightinfo is BST and left subtree ka max < root->data and right subtree ka min is > root->data
    // -> then curr node is also a part of BST.
    if (leftinfo.isBST && rightinfo.isBST && leftinfo.max < root->data && rightinfo.min > root->data)
    {
        curr.min = min(leftinfo.min, min(rightinfo.min, root->data));
        curr.max = max(rightinfo.max, max(leftinfo.max, root->data));

        // Since we already prooved that current root(node) is Part of BST. Hence, ans will be size of curr node.
        curr.ans = curr.size;
        curr.isBST = true;
        return curr;
    }

    // if curr node is not part of BST.
    curr.ans = max(leftinfo.ans, rightinfo.ans);
    curr.isBST = false;
    return curr;
}

int main(int argc, char const *argv[])
{
    node *root = newnode(15);
    root->left = newnode(20);
    root->right = newnode(30);
    root->left->left = newnode(5);
    cout << "Largest BST in BT is: " << largestBSTinBT(root).ans;
    return 0;
}
