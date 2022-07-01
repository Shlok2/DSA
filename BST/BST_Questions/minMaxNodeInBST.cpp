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

// Min in a BST is leftmost node.
int findMin(node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    while (root->left)
    {
        root = root->left;
    }
    return root->data;
}

int findMax(node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    while (root->right)
    {
        root = root->right;
    }
    return root->data;
}

node *insertBST(node *root, int k)
{
    if (root == NULL)
    {
        return new node(k);
    }
    if (k > root->data)
    {
        root->right = insertBST(root->right, k);
    }
    else
    {
        root->left = insertBST(root->left, k);
    }
    return root;
}

int main(int argc, char const *argv[])
{
    struct node *root = NULL;
    root = insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 6);
    insertBST(root, 5);
    cout << findMin(root) << endl;
    cout << findMax(root) << endl;
    return 0;
}
